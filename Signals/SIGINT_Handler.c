#include <stdio.h> // for printf
#include <signal.h>// for signal handling
// Signal handler function
void handler(int sig) {
    // Print a message when SIGINT is received
    printf("SIGINT received\n");
}
// Main function
int main() {
    // Register the signal handler for SIGINT
    signal(SIGINT, handler);// Set up the signal handler for SIGINT
    while(1);  // infinite loop to keep the program running
    return 0;// Return statement (not reached due to infinite loop)
}
// This program will print "SIGINT received" whenever the user 
// presses Ctrl+C, which sends the SIGINT signal to the program. 
// The signal handler function is registered using the signal() function, 
//and the program runs indefinitely until it is interrupted by the user.