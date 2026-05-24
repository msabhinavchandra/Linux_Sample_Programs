#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Alarm has gone off\n");
}

int main() {
    int pid;

    printf("Alarm application starting\n");

    pid = fork();

    if(pid == 0) {
        sleep(5);
        kill(getppid(), SIGALRM);
        exit(0);
    }
    else {
        signal(SIGALRM, handler);

        printf("Waiting for alarm...\n");

        pause();

        printf("Done\n");
    }

    return 0;
}