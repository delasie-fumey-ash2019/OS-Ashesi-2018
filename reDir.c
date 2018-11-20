#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>

int redir(char *args[]){
    int fd = open(args[3], O_CREAT|O_WRONLY|O_APPEND);

    int dupStatus = dup2(fd, 1);

    if(dupStatus == -1){
        perror("Failed to redirect STDOUT");
    }
    close(fd);
                    //write(STDERR_FILENO, argv[3], 2);

    return 0;
}