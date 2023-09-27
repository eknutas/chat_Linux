/* client.cpp Chat */

#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MESSAGE_LENGTH 1024 // Maximum data buffer size
#define PORT 7777 // Will use this port number

int socket_file_descriptor, connection;
struct sockaddr_in serveraddress, client;
char message[MESSAGE_LENGTH];
int main() {
    // Create a socket
    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_file_descriptor == -1) {
        std::cout << "Creation of Socket failed!" << '\n';
        exit(1);
    }
    // Set the server address
    serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    // Set the port number
    serveraddress.sin_port = htons(PORT);
    // Using IPv4
    serveraddress.sin_family = AF_INET;
    // Establish a connection to the server
    connection = connect(socket_file_descriptor, (struct sockaddr*)&serveraddress, sizeof(serveraddress));
    if (connection == -1) {
        std::cout << "Connection with the server failed!" << '\n';
        exit(1);
    }
    // Interaction with the server
    while (true)
    {
        // Waiting for a message from the server
        read(socket_file_descriptor, message, sizeof(message));
        std::cout << message << '\n';
        if ((strncmp(message, "Goodbye!", 8)) == 0) {
            break;
        }
        bzero(message, sizeof(message));
        std::cin.getline(message, 1024);
        write(socket_file_descriptor, message, sizeof(message));
    }
    // Close the socket, terminate the connection
    close(socket_file_descriptor);
    return 0;
}
