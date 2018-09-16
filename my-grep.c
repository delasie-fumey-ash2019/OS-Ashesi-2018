#include <stdio.h>
#include <string.h>

int main(int *argc, char *argv[]) {
    FILE *fileRead = fopen(argv[1], "r");
    char line[60];

    if(fileRead == NULL){
        printf("cannot open file\n");
        return 0;
    }
    else{
        while(fgets(line, 60, fileRead) != NULL){
            if(strstr(line, argv[2])){
                puts(line);
            }
        }
    }
    fclose(fileRead);
    return 0;
}