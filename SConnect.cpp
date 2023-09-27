/* SConnect.cpp Chat */

#include "SConnect.h"

int SConnect::sconnection()
{
    std::string str;
	// Create a socket
    sockert_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (SConnect::sockert_file_descriptor == -1) {
		throw "Socket creation failed!";
    }
    serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
    // Define the port number for communication
    serveraddress.sin_port = htons(PORT);
    // Using IPv4
    serveraddress.sin_family = AF_INET;
    // Bind the socket
    bind_status = bind(sockert_file_descriptor, (struct sockaddr*)&serveraddress,
        sizeof(serveraddress));
    if (bind_status == -1) {
		throw "Socket binding failed!";
    }
    // Puts a server to receive the data
    connection_status = listen(sockert_file_descriptor, 5);
    if (connection_status == -1) {
		throw "Socket is unable to listen for new connections!";
    }
    else {
		str = "Server in progress";
        std::cout << str << '\n';
    }
    length = sizeof(client);
    connection = accept(sockert_file_descriptor, (struct sockaddr*)&client, &length);
    if (connection == -1) {
		throw "Server is unable to accept the data from client!";
    }
    return connection;
}
