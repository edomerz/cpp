#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

using namespace std;

class TCPStream
{
public:
	friend class TCPAcceptor;
	friend class TCPConnector;
	
	~TCPStream();
	
	ssize_t Send(const char* buffer, ssize_t len);
	ssize_t Recive(const char* buffer, ssize_t len);
	
	string getPeerIP();
	int getPeerPort();
private:
	int m_sd;
	string m_peerIP;
	int m_peerPort;
	
	TCPStream(int sd, struct sockaddr_in* address);
	TCPStream(const TCPStream& stream);
};

//TCPStream::TCPStream(int sd, struct sockaddr_in* address): m_sd(sd)
//{
//	char ip[50];
//	inet_ntop(PF_INET, (struct in_addr*)&(address->sin_addr.s_addr), 
//				ip, sizeof(ip) - 1);
//	m_peerIP = ip;
//	m_peerPort = ntohs(address->sin_port);
//}

//TCPStream::~TCPStream()
//{
//	close(m_sd);
//}

//string TCPStream::getPeerIP()
//{
//	return(m_peerIP);
//}

//int TCPStream::getPeerPort()
//{
//	return(m_peerPort);
//}

//ssize_t TCPStream::send(char* buffer, size_t len)
//{
//	// TO DO - wraps the call to write(), return number of bytes sent
//}

//ssize_t TCPStream::recive(char* buffer, size_t len)
//{
//	// TO DO - wraps the call to read(), return the number of bytes recived
//}
