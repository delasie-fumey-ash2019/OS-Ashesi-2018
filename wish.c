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
    char *pos;
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
            pid_t pid = fork();
            printf("%d", pid);
            if(pid == 0){
                char* parameters[] = {strPath1,NULL};
                if((execv(strPath1,parameters) == -1) || pid < 0){
                    puts("An error occured");
                } else{
                    do{
                        pid_t newpid = waitpid(pid, &state, WUNTRACED);
                    } while(!WIFEXITED(state) && !WIFSIGNALED(state));
                }
                }
            }  

        else if(access(strPath2, F_OK) == 0){
            pid_t pid = fork();
            if(pid == 0){
                char* parameters[] = {strPath2,NULL};
                if((execv(strPath2,parameters) == -1) || pid < 0){
                    puts("An error occured");
                } else{
                    do{
                        pid_t newpid = waitpid(pid, &state, WUNTRACED);
                    } while(!WIFEXITED(state) && !WIFSIGNALED(state));
                }
                } 
            } 

        pos = args[0];
        if(pos == "exit"){
            state = promptExit();
        } else if(pos == "cd"){
            state = promptcd(args);
        } 
      
    } while(state);
    
    return 0;   
}