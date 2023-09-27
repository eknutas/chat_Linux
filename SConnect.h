/* SConnect.h Chat */

#pragma once
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>

class SConnect
{
private:
	#define PORT 7777 // Will use this port number
	struct sockaddr_in serveraddress, client;
	socklen_t length;
	
public:
	SConnect() = default;
	~SConnect() = default;
	int sockert_file_descriptor;
	int bind_status;
	int connection_status;
	int connection;
	int sconnection();
};
