#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **promptRead(char *line){
    int bufferSize = 64, position = 0;
    char *token;
    char **tokenSet = malloc(sizeof(char*) * bufferSize);

    token = strtok(line, "\n");
    while(token != NULL){
        tokenSet[position] = token;
        position = position + 1;
        token = strtok(NULL, "\n");

    if(position >= bufferSize){
        bufferSize += 64;
        tokenSet = realloc(tokenSet, sizeof(char*) * bufferSize);
    }
    }
    tokenSet[position] = NULL;
    return tokenSet;
}