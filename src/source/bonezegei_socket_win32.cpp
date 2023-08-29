/*
  Bonezegei Socket Win32 Implementation
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023
*/

#include "bonezegei_socket_win32.h"

BonezegeiSocketWin32::BonezegeiSocketWin32(){
    port=80;
}

int BonezegeiSocketWin32::begin(int socket_type){
    type=socket_type;

    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0){
        return SOCKET_ERROR_STARTUP;
    }

    if((master = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET){
        return SOCKET_ERROR_CREATE;
    }

    if(type==SOCKET_SERVER){

        for(i = 0 ; i < SOCKET_MAX_CLIENT; i++){
            client_socket[i] = 0;}

        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons( port );

        if( bind(master ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR){
            return SOCKET_ERROR_BIND;
        }

        listen(master , 3);
        addrlen = sizeof(struct sockaddr_in);
        return SOCKET_INIT_SUCCESS;
    }

    else if(type==SOCKET_CLIENT){
        return SOCKET_INIT_SUCCESS;
    }
}

int  BonezegeiSocketWin32::begin(int socket_type, int socket_port){
    port=socket_port;
    return begin(socket_type);
}

void BonezegeiSocketWin32::setPort(int p){

}

int BonezegeiSocketWin32::sendData(char *data){

    if(type==SOCKET_SERVER){
        return send(new_socket,data, strlen(data), 0);
    }
    else if(type==SOCKET_CLIENT){
        return send(master,data, strlen(data), 0);
    }
}

char* BonezegeiSocketWin32::getData(){
    return socket_data;
}

int BonezegeiSocketWin32::receiveData(){

    if(type==SOCKET_SERVER){
        memset(socket_data, 0, sizeof(socket_data) );
        return recv( new_socket, socket_data, SOCKET_MAX_RXDATA, 0);
    }
    else if(type==SOCKET_CLIENT){
        memset(socket_data, 0, sizeof(socket_data) );
        return recv( master, socket_data, SOCKET_MAX_RXDATA, 0);
    }
}

int BonezegeiSocketWin32::getConnection(){
    new_socket = accept(master , (struct sockaddr *)&new_socket, &addrlen);
    getpeername(new_socket , (struct sockaddr*)&address , (int*)&addrlen);
    return (new_socket != INVALID_SOCKET);
}


int BonezegeiSocketWin32::connectServer(char *ipAddress, int p){
    port=p;
	server.sin_addr.s_addr = inet_addr(ipAddress);
	server.sin_family = AF_INET;
	server.sin_port = htons( port );

	if (connect(master , (struct sockaddr *)&server , sizeof(server)) < 0){
		puts("connect error");
		return 0;
	}
	puts("Connected");

	return 1;
}

