#include <stdio.h>// for printf
#include <signal.h>// for signal handling
#include <unistd.h>// for sleep

int main() {
    // Ignore SIGINT (Ctrl + C)
    signal(SIGINT, SIG_IGN);// Ignore SIGINT signal
    while(1) {// infinite loop to keep the program running
        printf("Running... Press Ctrl+C\n");
        sleep(1);// Sleep for 1 second before printing the message again
    }
    return 0;
}