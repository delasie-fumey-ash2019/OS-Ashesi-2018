#include <stdio.h>

void newline(char *line){
    char stringLength = strlen(line);
    if(line[stringLength-1] == '\n'){
        line[stringLength-1] = '\0';
    }
}

char *promptLine(){
    char *line = NULL;
    size_t buffersize = 100;
    getline(&line, &buffersize, stdin);
    newline(line);
    return line;
}