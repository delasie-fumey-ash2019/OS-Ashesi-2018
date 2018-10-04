#include <stdio.h>

char *promptLine(){
    char *line = NULL;
    size_t buffersize = 0;
    getline(&line, &buffersize, stdin);
    return line;
}