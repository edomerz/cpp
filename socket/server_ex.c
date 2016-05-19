/*
	creates a server that runs continuously, and seds the date and time as
	soon as a clinet connets to it
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>

int main(int argc, char* argv[])
{
	int listenfd = 0;
	int connfd = 0;
	struct sockaddr_in serv_addr;
	
	char sendbuff[1024];
	time_t ticks;
	
	 
/*	create unnamed socket inside the kernel, returns socket fd 
	takes a domain/family - AF_INET 
	define the transport layer protocol - SOCK_STREAM
	let the kernal decide the defualt protocol - TCP	*/	
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	
	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendbuff, '0', sizeof(sendbuff));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(5000);
	
/*	assigen the the struct SERV_ADDR to the socket
	family/domain,
	interface to listen on,
	port	*/
	bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	
	/* 10 - max number of clients connections that the server will queue */
	listen(listenfd, 10);
	
	/*********** socket is functional and listening *********** */
	
	while(1)
	{
		connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
		
		ticks = time(NULL);
		
		snprintf(sendbuff, sizeof(sendbuff), "%.24s\r\n", ctime(&ticks));
		
		write(connfd, sendbuff, strlen(sendbuff));
		
		close(connfd);
		
		sleep(1);
	}
}
