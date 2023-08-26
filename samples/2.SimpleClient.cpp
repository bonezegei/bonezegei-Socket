/*
  Bonezegei Socket Client Hello World
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023
*/
#include <stdio.h>
#include <string.h>
#include "src/include/bonezegei_search.h"
#include "src/include/bonezegei_socket.h"
#include "src/source/bonezegei_socket_win32.h"

//Client
//win32 client 
BonezegeiSocketWin32 client;
int main(){
    client.begin(SOCKET_CLIENT);
    client.connectServer("127.0.0.1",80);                                    //get data to localhost server
    char *message = "GET /index.html \r\nHost:localhost HTTP/1.1\r\n\r\n";   
    client.sendData(message);

        printf("[receive] ");
        int r=client.receiveData();
        printf("size:%d data:\n%s\n",r,client.getData());

    return 0;
}
