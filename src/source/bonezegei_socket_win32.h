/*
  Bonezegei Socket Win32 Implementation
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023
*/
#ifndef BONEZEGEI_SOCKET_WIN32_H_
#define BONEZEGEI_SOCKET_WIN32_H_

#include "../include/bonezegei_socket.h"

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>

class BonezegeiSocketWin32: public BonezegeiSocket{
public:
    BonezegeiSocketWin32();
    int  begin(int socket_type);
    int   begin(int socket_type, int socket_port);
    void  setPort(int p);
    int   sendData(char *data);
    int   receiveData();
    char* getData();
    int   getConnection();
    int   connectServer(char *ipAddress, int port);


	WSADATA wsa;
	SOCKET  new_socket, s, master, client_socket[SOCKET_MAX_CLIENT];
	struct  sockaddr_in server, address;
	int     max_clients = SOCKET_MAX_CLIENT , activity, addrlen, i, valread;
	fd_set  readfds;

	int type;
};

#endif

