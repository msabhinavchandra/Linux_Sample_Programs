#include <stdio.h>// for printf
#include <signal.h>// for signal handling
#include <unistd.h>// for alarm and pause
// Signal handler function
void handler(int sig) {// Print a message when SIGALRM is received
    printf("Alarm triggered\n");// Exit the program after handling the signal
}// Main function
int main() {
    signal(SIGALRM, handler);// Register the signal handler for SIGALRM
    alarm(5);// Set an alarm to trigger after 5 seconds
    //Stop here and wait until a signal arrives
    pause();/// Wait for the signal to be handled
    return 0;
}