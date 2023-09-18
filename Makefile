#Makefile for Project of console chat

chat: main.o Chat.o Logger.o SConnect.o
	g++ main.o Chat.o Logger.o SConnect.o -o chat `mysql_config --cflags --libs`

main.o: main.cpp
	g++ -c main.cpp -L/usr/include/mysql-lmysqlclient -I/usr/include/mysql

Chat.o: Chat.cpp
	g++ -c Chat.cpp -L/usr/include/mysql-lmysqlclient -I/usr/include/mysql

Logger.o: Logger.cpp
	g++ -c Logger.cpp -L/usr/include/mysql-lmysqlclient -I/usr/include/mysql

Connect.o: SConnect.cpp
	g++ -c SConnect.cpp -L/usr/include/mysql-lmysqlclient -I/usr/include/mysql

clean:
	rm -rf *.o *.a chat

