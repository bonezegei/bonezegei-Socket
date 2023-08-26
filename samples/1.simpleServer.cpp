/*
  Bonezegei Socket Server Hello World
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023
*/
#include <stdio.h>
#include <string.h>
#include "src/include/bonezegei_search.h"
#include "src/include/bonezegei_socket.h"
#include "src/source/bonezegei_socket_win32.h"

//Windows Server
BonezegeiSocketWin32 server;

// Open browser and type localhost on arddress bar
// This will not work if the device is already running a server at port 80 since this server is set by default at 80
// you can specify the socket port ( server.begin(SOCKET_SERVER,port);)
int main(){
    server.begin(SOCKET_SERVER);

	while( server.getConnection() ){
        printf("[receive] ");
        int r=server.receiveData();
        printf("size:%d data:\n%s\n",r,server.getData());

        char *html="<html> <div style=\"font-size:100px; margin:auto\"> Hello World</div></html>";

		char tmp[384];
        sprintf(tmp,"HTTP/1.1 200 OK\r\nContent-Type: %s\r\nServer: Bonezegei Server\r\nConnection: close\r\nContent-Length: %d\r\n\r\n%s","text/html",strlen(html),html);
        server.sendData(tmp);
	}

}
