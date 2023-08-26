/*
  Bonezegei Socket
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023
*/
#ifndef BONEZEGEI_SOCKET_H_
#define BONEZEGEI_SOCKET_H_

/* Socket Type */
#define SOCKET_SERVER 0
#define SOCKET_CLIENT 1

/* Initialization flags*/
#define SOCKET_INIT_SUCCESS     1
#define SOCKET_ERROR_STARTUP    0
#define SOCKET_ERROR_CREATE    -1
#define SOCKET_ERROR_BIND      -2

/* Client Connect to Server Flag*/


#define SOCKET_MAX_CLIENT 50
#define SOCKET_MAX_RXDATA 16384


class BonezegeiSocket{
public:
    BonezegeiSocket(){}

    virtual int   begin(int socket_type){return 0;}
    virtual int   begin(int socket_type, int socket_port){return 0;}
    virtual void  setPort(int p){}
    virtual int   sendData(char *data){return 0;}
    virtual int   receiveData(){return 0;}
    virtual char* getData(){return 0;}
    virtual int   getConnection(){return 0;}
    virtual int   connectServer(char *ipAddress, int port){return 0;}

    int port;
    char ip[32];
    char socket_data[SOCKET_MAX_RXDATA];
};


#endif
