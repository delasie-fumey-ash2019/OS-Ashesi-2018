#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LSH_TOK_DELIM " \t\r\n\a"

char **promptRead(char *line){
    int bufferSize = 256; 
    int position = 0;
    char *token;
    char **tokenSet = malloc(sizeof(char*) * bufferSize);

    if(!tokenSet){
        fprintf(stderr, "Allocation failed");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, LSH_TOK_DELIM);
    while(token != NULL){
        tokenSet[position] = token;
        position = position + 1;
       
        if(position >= bufferSize){
            bufferSize += 256;
            tokenSet = realloc(tokenSet, sizeof(char*) * bufferSize);
        }
        token = strtok(NULL, LSH_TOK_DELIM);
    }
    tokenSet[position] = NULL;
    return tokenSet;
}