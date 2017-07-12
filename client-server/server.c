#include "cs.h"

int main(void)
{
	int sockfd = -1, accfd = -1;
	pid_t pid = -1;
	int ret = -1;
	socklen_t client_len = 0;
	struct sockaddr_in server_addr = {0};
	struct sockaddr_in client_addr = {0};
	//char recv_buf[50], send_buf[] = "OK";
	struct PACKET recv_buf = {0};

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
	server_addr.sin_addr.s_addr = inet_addr(SERVER_LANIP);
	ret = bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr));
	if(ret < 0)
	{
		perror("bind");
		return -1;
	}
	printf("bind success.\n");
	
	//第三步：监听
	ret = listen(sockfd, BACKLOG);
	if(ret < 0)
	{
		perror("listen");
		return -1;
	}
	printf("listen success.\n");
	
	accfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
	if(accfd < 0)
	{
		perror("accept");
		return -1;
	}
	printf("accept success.\n");
	//printf("client IP Adress = %s.\n", inet_ntoa(client_addr.sin_addr));
	//printf("client PORT = %d.\n", client_addr.sin_port);
	
	
	//第四步：从客户端接收数据
	//ret = recv(accfd, (char *)recv_buf, sizeof(recv_buf), 0);
	memset((struct PACKET *)&recv_buf, 0, sizeof(recv_buf));
	ret = read(accfd, (struct PACKET *)&recv_buf, sizeof(recv_buf));
	if(ret < 0)
	{
		perror("recv");
		return -1;
	}
	printf("recv_buf = %s %s.\n", recv_buf.cmd, recv_buf.arg);
	pid = fork();
	if(pid == 0)
	{
		execlp(recv_buf.cmd, recv_buf.cmd, recv_buf.arg,(char  *) NULL);
	}
	else if(pid > 0)
	{
		printf("in parent.\n");
	}
	else
	{
		perror("fork");
		return -1;
	}
	//第五步：发送数据到客户端
	/*ret = send(accfd, (const char *)send_buf, sizeof(send_buf), 0);
	if(ret < 0)
	{
		perror("send");
		return -1;
	}
	printf("send %d data success.\n", ret);*/

	return 0;
}
