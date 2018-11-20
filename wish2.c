#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h> 
#include <stdlib.h>
#include <pthread.h>

#include "promptRead.c"
#include "promptExit.c"
#include "promptLine.c"
#include "promptcd.c"
#include "reDir.c"

//#include "promptPar.c"

int main(int argc, char **argv){  
   
    char strPath1[1024];
    char strPathargs[1024]; 
    char strPath2[1024];
    char error_message[30] = "An error has occurred\n";
    char *array[10];

    char **args;
    
    while(1){
        printf("wish> ");
        char *readline = promptLine();
        args = promptRead(readline);


        for (int i = 1; i < argc; i++) {
            array[i] = args[i];
        }

        strcpy(strPath1, "/bin/");
        strcpy(strPathargs, *args);
        strncat(strPath1, strPathargs, 128);
    
        strcpy(strPath2, "/usr/bin/");
        strncat(strPath2, strPathargs, 128);

        if(strcmp(args[0], "exit") == 0){
            promptExit();
        } else if(strcmp(args[0], "cd") == 0){
            promptcd(args);
        } else {
            for(int i = 1; i < argc; i++){
                if(strcmp(args[i], ">") == 0){
                    redir(args);
                }
            }
        }

        pid_t rc = fork();
        if(rc == 0){
            if(access(strPath1, F_OK) == 0){
                array[0] = strPath1;
                //char* parameters[] = {strPath1,NULL};
                if((execv(strPath1,array) == -1) || rc < 0){
                    write(STDERR_FILENO, error_message, strlen(error_message));
                }
            }
        
            else if(access(strPath2, F_OK) == 0){
                array[0] = strPath2;
                // char* parameters[] = {strPath2,NULL};
                if((execv(strPath2,array) == -1) || rc < 0){
                        write(STDERR_FILENO, error_message, strlen(error_message));
                }
                }

            else{
                write(STDERR_FILENO, error_message, strlen(error_message));
            }
        }
    

    
            else{
                wait(NULL);
            }
            } 
    }
    
