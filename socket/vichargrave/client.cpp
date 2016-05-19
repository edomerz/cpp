#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "tcpconnector.h"

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage: %s <port> <ip>\n", argv[0]);
		exit(1);
	}
	
	int len;
	string message;
	char line[256];
	
	TCPConnector* connector = new TCPConnector();
	TCPStream* stream = connector->Connect(argv[2], atoi(argv[1]));
	
	if(stream)
	{
		message = "is there life on mars?";
		stream->Send(message.c_str(), message.size());
		
		printf("sent - %s\n", message.c_str());
		
		len = stream->Recive(line, sizeof(line));
		
		line[len] = '\0';
		printf("Received - %s\n", line);
		
		delete stream;
	}
	
	stream = connector->Connect(argv[2], atoi(argv[1]));
	if(stream)
	{
		message = "why is there air?";
		stream->Send(message.c_str(), message.size());
		printf("sent - %s\n", message.c_str());
		
		len = stream->Recive(line, sizeof(line));
		line[len] = '\0';
		
		printf("received - %s\n", line);
		
		delete stream;
	}
	
	exit(0);
}
