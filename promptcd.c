#include <unistd.h>
#include <stdio.h>

int promptcd(char **args){
    if(args[1] == NULL){
        printf("Exception: 'cd' takes just one parameter\n");
        return -1;   
    }else{
        chdir(args[1]);
    }
    return 0;
}