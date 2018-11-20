#include <unistd.h>
#include <stdio.h>
#include <string.h>

void promptcd(char **args){

    if(chdir(args[1]) != 0){
        printf("%s\n", "Directory not found");
    }
   
}