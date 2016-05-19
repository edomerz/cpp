/* Simple select()-driven chat server */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <err.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


main() 
{
	struct protoent *tp = getprotobyname("tcp"); 	/* TCP protocol */
	int serv_sock; 								/* Master socket for server */
	fd_set ifds; 									/* Bitmap of active sockets */
	int maxfd; 									/* Last active socket */
	struct sockaddr_in sin;
	char **hostnames;  							/* Names of currently connected hosts */


	/* Create a TCP socket */
	if (tp == NULL) 
	{
	err(1, "Cannot get tcp protocol\n");
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, tp->p_proto);
	if (serv_sock < 0)
	{
	 err(2, "Cannot create socket:  %s\n", strerror(errno));
	}


	/* Bind the socket to port 12345 */
	memset(&sin, 0, sizeof(sin));
	sin.sin_len = sizeof(sin);
	sin.sin_family = PF_INET;
	sin.sin_port = htons(12345);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(serv_sock, (struct sockaddr*)&sin, sizeof(sin)) < 0)
	{
	 err(3, "Cannot bind socket:  %s\n", strerror(errno));
	}


	/* Allow incoming connections */
	if (listen(serv_sock, 64) < 0)
	{
	 err(3, "Cannot listen to socket:  %s\n", strerror(errno));
	}

	FD_ZERO(&ifds);
	FD_SET(serv_sock, &ifds);
	maxfd = serv_sock;

	for (;;) 
	{
	int fd = -1; 					/* Current file descriptor (socket) with input */
	int i;
	struct timeval to = { 2, 0 }; 	/* 2 seconds, 0 microseconds */

	/* Wait for input from anywhere */
	fd_set tifds = ifds;

	int numfds = select(maxfd+1, &tifds, NULL, NULL, &to);
	if (numfds == -1) 
	{
		err(4, "Cannot select:  %s\n", strerror(errno));
	}
	if (numfds == 0) 
	{
		continue;
	}

	/* Find first connection with available input */
	fd = -1;
	for (i = 0; i <= maxfd; i++)
	{
	  if (FD_ISSET(i, &tifds)) 
	  {
		fd = i;
		break;
	  }
	}
	if (fd == -1) 
	{
		err(5, "Oops");
	}

	if (fd == serv_sock) /* New connection request */
	{ 
		struct sockaddr_in remote;
		int len = sizeof(remote);
	  	int rfd;
	  	/* Accept the connection */
	  	rfd = accept(serv_sock, (struct sockaddr*)&remote, &len);
	  	if (rfd == -1) 
	  	{
	  		err(6, "Cannot accept:  %s\n", strerror(errno));
	  	}
	  	/* Add the new connection to file descriptors I watch */
	  	FD_SET(rfd, &ifds);
	  	if (hostnames && rfd < maxfd && hostnames[rfd]) 
	  	{
			free(hostnames[rfd]);
			hostnames[rfd] = strdup(inet_ntoa(remote.sin_addr));
	  	} 
	  	else 
	  	{
			maxfd = rfd;
			hostnames = realloc(hostnames, (maxfd+1)*sizeof(char*));
			hostnames[rfd] = strdup(inet_ntoa(remote.sin_addr));
	  	}
	} 
	else /* Input is from a chat participant */
	{  
	  	char buf[80];
	  	int count;
	  	char *h = hostnames[fd];
	  	/* Get the input */
	  	count = read(fd, buf, sizeof(buf));
	  	if (count == 0) 
	  	{
	  		FD_CLR(fd, &ifds);
	  	}
	  	else /* Relay it to every other participant */
	  	{
			int i;
			for (i = 0; i <= maxfd; i++) 
			{
		  		if (FD_ISSET(i, &ifds) && i != serv_sock && i != fd) 
		  		{
		    		write(i, h, strlen(h));
		    		write(i, ": ", 2);
		    		write(i, buf, count);
		  		}
			}
	  	}
	}
	}
}
