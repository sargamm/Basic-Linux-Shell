#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
const int maxInput=100;
int parse(char* input, char** Command){
      FILE *mf;
    char cwd[1024];
    getcwd(cwd,sizeof(cwd));
    printf("%s",cwd);
    printf(":");
    fgets(input,maxInput,stdin);
    mf=fopen("/home/sargam/Documents/.history","a+");
    fputs(input,mf);
    fclose(mf);
    int i;
    for(i=0; i<maxInput; i++){
        Command[i]=strsep(&input," ");
        if(Command[i]==NULL){
            break;
        }
    }
    int tempSize=strlen(Command[i-1]);
    Command[i-1][tempSize-1]='\0';
    return i;
}
void main(){
    char input[maxInput];
    char *Command[maxInput];
    int x;
    x=parse(input,Command);

   // printf("%s\n",Command[0]);
    while(strcmp("exit",Command[0])!=0){
        if(strcmp("cd",Command[0])==0){
        //printf("HIIII");
        int j=chdir(Command[1]);
        if(j==-1)
            printf("%s\n","Such a directory does not exist.");
        }
    else if(strcmp("echo",Command[0])==0){
        int f1=0,f2=0;
        //printf(Command[0]);
        int i=1;
        if(strcmp(Command[1],"-n")==0 || strcmp(Command[1],"-en")==0 ||strcmp(Command[1],"-ne")==0) 
            {f1=1;
            i++;
            }
        if(x>2){
        if(strcmp(Command[2],"-n")==0){
            f1=1;
            i++;
            //printf(2);
        }
        }
        //printf("%s\n",Command[1]);
        if(strcmp(Command[1],"-e")==0 || strcmp(Command[1],"-en")==0 || strcmp(Command[1],"-ne")==0){
            f2=1;i++;
            //printf("Hiii\n");
        }
        if(x>2){
            if(strcmp(Command[2],"-e")==0){
            f2=1;
            i++;
            //printf(4);
        }
        }
       // printf("Do1\n");
        for(;i<x;i++){
            if(f2==1){
                for(int j=0;j<strlen(Command[i]);j++){
                    //printf("%c\n",Command[i][j]);
                    if(Command[i][j]=='\\'){
                        if(j!=strlen(Command[i])-1){
                        if(Command[i][j+1]=='a'){
                            printf("%c",'\a');
                        }
                        else if(Command[i][j+1]=='b'){
                            printf("%c",'\b');
                        }
                        else if(Command[i][j+1]=='e'){
                            printf("%c",'\e');
                        }
                        else if(Command[i][j+1]=='f'){
                            printf("%c",'\f');
                        }
                        else if(Command[i][j+1]=='n'){
                            printf("%c",'\n');
                        }
                        else if(Command[i][j+1]=='r'){
                            printf("%c",'\r');
                        }
                        else if(Command[i][j+1]=='t'){
                            printf("%c",'\t');
                        }
                        else if(Command[i][j+1]=='v'){
                            printf("%c",'\v');
                        }
                        j++;
                    }
                    }
                   else
                    {
                        printf("%c",Command[i][j]);
                    }
                    
                }
                printf("%c",' ');
            }
        else
            printf("%s ",Command[i]);
        }
        if(f1==0)
            printf("\n");
        
    }
    else if(strcmp(Command[0],"history")==0){
        char h[maxInput];
        FILE* mf;
        mf=fopen("/home/sargam/Documents/.history","r");
        while(fgets(h,maxInput,mf)){
            printf("%s",h);
        }
        fclose(mf);
    }
    else if(strcmp(Command[0],"pwd")==0){
     
        char cwd[1024];
        getcwd(cwd,sizeof(cwd));
        printf("%s",cwd);
        printf("\n");
    }
    else if(strcmp(Command[0],"exit")==0){
        exit(0);
    }
    else{
    int pid=fork();
    if(pid==0){
    if(strcmp(Command[0],"ls")==0){
        //printf("HIII");
        execv("/bin/ls",Command);
    }
    else if(strcmp(Command[0],"mkdir")==0){
        execv("/bin/mkdir",Command);
    }
    else if(strcmp(Command[0],"rm")==0){
        execv("/bin/rm",Command);
    }
    else if(strcmp(Command[0],"cat")==0){
        execv("/bin/cat",Command);
    }
    else if (strcmp(Command[0],"date")==0)
    {
        execv("/bin/date",Command);
    }
    else{
        printf("%s\n","This command is not recognised" );
    }
    exit(0);
    }
    else{
        wait(NULL);
    }
}
x=parse(input,Command);
}
}