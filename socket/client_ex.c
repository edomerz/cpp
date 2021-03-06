#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	int sockfd = 0;
	int n = 0;
	char recvbuff[1024];
	struct sockaddr_in serv_addr;
	
	if(argc != 2)
	{
		printf("\n Usage: %s <ip of server> \n", argv[0]);
		return(1);
	}
	
	memset(recvbuff, '0', sizeof(recvbuff));
	
	/* create the socket */
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Error: could not create socket\n");
		return(1);
	}
	
	memset(&serv_addr, '0', sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5000);
	
	if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
	{
		printf("\n inet_pton error occured\n");
		return(1);
	}
	
	if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\n Error: connect failed\n");
		return(1);
	}
	
	while((n = read(sockfd, recvbuff, sizeof(recvbuff) - 1)) > 0)
	{
		recvbuff[n] = 0;
		if(fputs(recvbuff, stdout) == EOF)
		{
			printf("\n Error: fputs error\n");
		}
	}
	
	if(n < 0)
	{
		printf("\n read error \n");
	}
	return(0);
	
}
