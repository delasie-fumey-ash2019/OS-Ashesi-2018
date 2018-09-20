#include <stdio.h>

int main(int argc, char *argv[]) {
    for(int i = 1; i <= argc-1; i++){
        char line[60];
        FILE *fileRead = fopen(argv[i], "r");
        if(fileRead == NULL){
            printf("cannot open file\n");
            return 1;
        }
        else{
            while(fgets(line, 60, fileRead) != NULL){
                printf("%s\n", line);
            }
        }
        fclose(fileRead);
    }
    return 0;
}
