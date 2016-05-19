#include <arpa/inet.h>

#include "tcpstream.h"

TCPStream::TCPStream(int sd, struct sockaddr_in* address): m_sd(sd)
{
	char ip[50];
	inet_ntop(AF_INET, (struct in_addr*)&(address->sin_addr.s_addr), 
				ip, sizeof(ip) - 1);
	m_peerIP = ip;
	m_peerPort = ntohs(address->sin_port);
}

TCPStream::~TCPStream()
{
	close(m_sd);
}

string TCPStream::getPeerIP()
{
	return(m_peerIP);
}

int TCPStream::getPeerPort()
{
	return(m_peerPort);
}

ssize_t TCPStream::Send(const char* buffer, ssize_t len)
{
	return(write(m_sd, (void*)buffer, len));
	// TO DO - wraps the call to write(), return number of bytes sent
}

ssize_t TCPStream::Recive(const char* buffer, ssize_t len)
{
	return(read(m_sd, (void*)buffer, len));
	// TO DO - wraps the call to read(), return the number of bytes recived
}
