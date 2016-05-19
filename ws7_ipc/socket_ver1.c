#include <sys/socket.h>

// create a socket
// INPUT: domain - nature of the communication, 
// including the address format (AF)
//		type - the type of the socket, the communication 
// characteristics
//		protocol - usually 0, default protocol for the given domain
// and socket type. for exmp: default protocol for SOCK_STREAM in AF_INET
// communication domain is TCP(transmission control protocol)
// the default protocol for SOCK_DGRAM socket in the AF_INET communication
// domain is UDP (user datagram protocol)
// OUTPUT: returns socket descriptor, or -1 on error
int socket(int domain, int type, int protocol);


//disable I/O  on a socket
// allow to disable a socket independently of the number of active fd
// (using dup())
// usage of a socket in 1 direction
// INPUT: sockfd - socket fd
//		how - SHUT_RD reading is disabled / SHUT_WR cant transmit data / 
// SHUT_RDWR disable both transmission and reception
int shutdown(int sockfd, int how);


// close(), open(), read(), write() work with sockets


