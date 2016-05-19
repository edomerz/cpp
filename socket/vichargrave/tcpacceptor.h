#include <string>
#include <netinet/in.h>

#include "tcpstream.h"

using namespace std;

class TCPAcceptor
{
public:
	TCPAcceptor(int port, const char* address = "");
	~TCPAcceptor();
	
	int Start();
	TCPStream* Accept();
private:
	int m_lsd;
	int m_port;
	string m_address;
	bool m_listening;
};


