#include <netinet/in.h>

#include "tcpstream.h"

class TCPConnector
{
public:
	// generated ctor and dtor
	
	TCPStream* Connect(const char* server, int port);
private:
	int resolveHostName(const char* host, struct in_addr* addr);
};
