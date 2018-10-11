#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h> 
#include <stdlib.h>
#include "promptRead.c"
#include "promptExit.c"
#include "promptLine.c"
#include "promptcd.c"

int main(int argc, char **argv){  
   
    char strPath1[1024];
    char strPathargs[1024]; 
    char strPath2[1024];

    char **args;
    int state;
    
    do{
        printf("wish> ");
        char *readline = promptLine();
        args = promptRead(readline);

        strcpy(strPath1, "/bin/");
        strcpy(strPathargs, *args);
        strncat(strPath1, strPathargs, 128);
        strcpy(strPath2, "/usr/bin/");
        strncat(strPath2, strPathargs, 128);

        if(access(strPath1, F_OK) == 0){
            int rc = fork();

            if(rc == 0){
                printf("%d", rc);
                char* parameters[] = {strPath1,NULL};
                if((execv(strPath1,parameters) == -1) || rc < 0){
                    puts("An error occured");
                }
                }
            }  

        else if(access(strPath2, F_OK) == 0){
            printf("%s", strPath2);
            int rc = fork();
            if(rc == 0){
                char* parameters[] = {strPath2,NULL};
                if((execv(strPath2,parameters) == -1) || rc < 0){
                    puts("An error occured");
                }
                } 
            } 
        
        if(strcmp(args[0], "exit") == 0){
            state = promptExit();
        } else if(strcmp(args[0], "cd") == 0){
            state = promptcd(args);
        } 
      
    } while(state != 1);
    
    return 0;   
}