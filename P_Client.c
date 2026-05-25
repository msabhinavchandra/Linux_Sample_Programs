
#include<stdio.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<string.h>
#include<unistd.h>

int main(){
	
	int s;// for socket file descriptor
	struct sockaddr_un cli,srv;
	char buf[2]="Cl";
	//initialize client socket and bind it to an address(file system path)
	s=socket(AF_UNIX,SOCK_DGRAM,0);
	cli.sun_family=AF_UNIX;
	strcpy(cli.sun_path,"/tmp/c");
	//unlink old or used or alr attached paths
	//for bind to socket file descriptor freely
	unlink("/tmp/c");
	bind(s,(struct sockaddr*)&cli,sizeof(cli));
	//initialize for server
	srv.sun_family=AF_UNIX;
        strcpy(srv.sun_path,"/tmp/s");
	//binding will be in server code only
	sendto(s,buf,2,0,(struct sockaddr*)&srv,sizeof(srv));
	printf("message sent from client: %s\n",buf);
	recvfrom(s,buf,2,0,0,0);
	printf("message received from server: %s\n",buf);
	return 0;
}

