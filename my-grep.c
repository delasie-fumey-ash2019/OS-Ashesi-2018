#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int n = 1;
    for(int i = 2; i <= argc-1; i++){
        FILE *fileRead = fopen(argv[i], "r");
        char line[60];

        if(fileRead == NULL){
            printf("cannot open file\n");
            return 1;
        }
        else{
            while(fgets(line, 60, fileRead) != NULL){
                if(strstr(line, argv[n])){
                    puts(line);
                }
            }
        }
        fclose(fileRead);
    }
    return 0;
}