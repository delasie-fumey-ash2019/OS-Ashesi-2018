#include <stdio.h>
#include <string.h> 

char main(){
    char str1[1024];
    char str2[1024];

    strcpy(str1, "my word");
    strcpy(str2, " is final");
    strncat(str1, str2, 32);
    puts(str1);
}