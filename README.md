# Basic-Linux-Shell
code for running basic shell commands 
The implementation of the shell is capable of executing the following commands:

    1. INTERNAL COMMANDS:
        i. cd- it uses the chdir(x) command which changes to directory x. It also gives an error message if the mentioned directory does not exist.
        ii. Echo – it prints everything that follows the command. It handles to corner cases, namely,-e for interpreting the escape sequences and -n for not adding a new line character.
        iii. History- this was done by creating a file that maintains the history of commands, adding to the file whenever a command is executed. The entire file was displayed whenever this command was executed.
        iv. Pwd- this used the getcwd() command and printed the present working directory.
        v. Exit- simply exited the code.
           
    2. EXTERNAL COMMANDS:
    i. mkdir
    ii. ls
    iii. rm
    iv. cat
    v. date
	all the external commands were executed using execv() by simply passing the path of the required command and the command line as the arguments.
The function fork() was used to to initiate a child process which handles the external commands. This was done to take care that the program does not terminate when an external command is done with its execution. The program recognises only the commands mentioned above and gives an error message whenever it does not recognise the entered command.
