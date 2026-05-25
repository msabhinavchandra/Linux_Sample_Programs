#include <stdio.h>// for printf
#include <sys/socket.h>// for socket programming, including socket(), 
//bind(), sendto(), and recvfrom()
#include <sys/un.h>// for sockaddr_un structure, which is used for 
//UNIX domain sockets
#include <string.h>// for strcpy() and strlen() functions
#include <unistd.h>// for unlink() function, which is used to remove
int main() {
    int s;// Socket file descriptor
    struct sockaddr_un srv, cli;// Structures for server and client addresses
    socklen_t len;// Variable to hold the length of the client address structure
    char buf[2];// Buffer to hold the message received from the client
    s = socket(AF_UNIX, SOCK_DGRAM, 0);// Create a UNIX domain datagram socket
    srv.sun_family = AF_UNIX;// Set the address family to AF_UNIX
    strcpy(srv.sun_path, "/tmp/s");// Set the socket file path for the server
    unlink("/tmp/s");// Remove any existing socket file at the specified path
    bind(s, (struct sockaddr*)&srv, sizeof(srv));
    //**impt**//
    len = sizeof(cli);// Set the length of the client address structure
    recvfrom(s, buf, 2, 0, (struct sockaddr*)&cli, &len);
    printf("Client: %s\n", buf);
    sendto(s, buf, 2, 0, (struct sockaddr*)&cli, sizeof(cli));
}
