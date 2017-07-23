//Client-Server mode based on TCP 

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define SERVER_PORT 6003
#define SERVER_LANIP "10.105.195.224"
#define SERVER_WANIP "115.159.151.95"
#define BACKLOG 50

struct PACKET
{
	char cmd[20];
	char arg[20];
};