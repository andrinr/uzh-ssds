#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handle(int signum){

    printf("Received signal %d\n", signum);
}

int main(){

    signal(SIGINT, sig_handle);
    sleep(10);
    return 0;

}
