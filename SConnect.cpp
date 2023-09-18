/* SConnect.cpp Chat */

#include "SConnect.h"

int SConnect::sconnection()
{
    std::string str;
	// Создадим сокет
    sockert_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (SConnect::sockert_file_descriptor == -1) {
		throw "Socket creation failed!";
    }
    serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
    // Зададим номер порта для связи
    serveraddress.sin_port = htons(PORT);
    // Используем IPv4
    serveraddress.sin_family = AF_INET;
    // Привяжем сокет
    bind_status = bind(sockert_file_descriptor, (struct sockaddr*)&serveraddress,
        sizeof(serveraddress));
    if (bind_status == -1) {
		throw "Socket binding failed!";
    }
    // Поставим сервер на прием данных
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
