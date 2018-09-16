#include <stdio.h>

int main(int *argc, char *argv[]) {
    char line[60];
    FILE *fileRead = fopen(argv[1], "r");
    if(fileRead == NULL){
        printf("cannot open file\n");
        return 0;
    }
    else{
        while(fgets(line, 60, fileRead) != NULL){
            printf("%s\n", line);
        }
    }
    fclose(fileRead);
    return 0;
}
