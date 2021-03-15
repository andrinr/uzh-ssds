#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int fd[2];
    pid_t pid;

    pipe(fd);

    pid = fork();

    if (pid == 0){
        close(fd[0]);
        char msg1[] = "Hello World #1";
        char msg2[] = "Hello World #2";
        char msg3[] = "Hello World #3";
        write(fd[1], msg1, (strlen(msg1)+1));
        write(fd[1], msg2, (strlen(msg2)+1));
        write(fd[1], msg3, (strlen(msg3)+1));
        exit(0);
    }
    else{
        close(fd[1]);
        char buffer1[80];
        char buffer2[80];
        char buffer3[80];

        read(fd[0], buffer1, sizeof(buffer1));
        read(fd[0], buffer2, sizeof(buffer2));
        read(fd[0], buffer3, sizeof(buffer3));

        printf("received: %s", buffer1);
        printf("received: %s", buffer2);
        printf("received: %s", buffer3);
    }
    return 0;
}
