#include<stdio.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<string.h>
#include<unistd.h>

int main(){

        int s;// for socket file descriptor
        struct sockaddr_un cli,srv;
        char buf[2];
        //initialize server socket and bind it to an address(file system path)
        s=socket(AF_UNIX,SOCK_DGRAM,0);
        srv.sun_family=AF_UNIX;
        strcpy(srv.sun_path,"/tmp/s");
        //unlink old or used or alr attached paths
        //for bind to socket file descriptor freely
        unlink("/tmp/s");
        bind(s,(struct sockaddr*)&srv,sizeof(srv));
        //initialize client only len
	socklen_t len;
	len=sizeof(cli);
        recvfrom(s,buf,2,0,(struct sockaddr*)&cli,&len);
        printf("message received from client: %s\n",buf);
	strcpy(buf,"S");
	sendto(s,buf,2,0,(struct sockaddr*)&cli,sizeof(cli));
	printf("message sent to client: %s\n",buf);
        return 0;
}

