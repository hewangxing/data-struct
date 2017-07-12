#include "cs.h"

int main(void)
{
	int sockfd = -1;
	int ret = -1;
	struct sockaddr_in server_addr = {0};
	//char send_buf[60], recv_buf[60];
	struct PACKET send_buf = {0};
	
	//第一步：打开一个socket文件，IPv4, TCP
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("socker");
		return -1;
	}
	printf("socketfd = %d.\n", sockfd);
	
	//第二步：将主机的IP地址和端口与socket绑定
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVER_PORT);
	server_addr.sin_addr.s_addr = inet_addr(SERVER_WANIP);
	ret = connect(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr));
	if(ret < 0)
	{
		perror("bind");
		return -1;
	}
	printf("connect success.\n");
	
	printf("please input some words:\n");
	scanf("%s", send_buf.cmd);
	scanf("%s", send_buf.arg);
	printf("send_buf = %s %s.\n", send_buf.cmd, send_buf.arg);
	//第三步：发送数据到服务器
	//ret = send(sockfd, (const char *)send_buf, sizeof(send_buf), 0);
	ret = write(sockfd, (struct PACKET *)&send_buf, sizeof(send_buf));
	if(ret < 0)
	{
		perror("send");
		return -1;
	}
	printf("send %d data success.\n", ret);
	
	//第四步：从服务器接收数据
	/*ret = recv(sockfd, (char *)recv_buf, sizeof(recv_buf), 0);
	if(ret < 0)
	{
		perror("recv");
		return -1;
	}
	printf("recv_buf = %s.\n", recv_buf);*/
	
	return 0;
}
