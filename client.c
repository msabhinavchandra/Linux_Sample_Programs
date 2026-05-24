#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>
int main() {
    int s;
    struct sockaddr_un srv, cli;
    char buf[2] = "hi";
    s = socket(AF_UNIX, SOCK_DGRAM, 0);
    cli.sun_family = AF_UNIX;
    strcpy(cli.sun_path, "/tmp/c");
    unlink("/tmp/c");
    bind(s, (struct sockaddr*)&cli, sizeof(cli));
    srv.sun_family = AF_UNIX;
    strcpy(srv.sun_path, "/tmp/s");
    sendto(s, buf, 2, 0, (struct sockaddr*)&srv, sizeof(srv));
    recvfrom(s, buf, 2, 0, 0, 0);
    printf("Server: %s\n", buf);
}