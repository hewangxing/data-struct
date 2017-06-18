//该程序用来生成一个简单的带main函数的模板
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd = -1, fd1 = -1, ret = 0;
	char buf[] = "#include<stdio.h>\n\nint main(void)\n{\n\n\n\treturn 0;\n}\n";
	if(argc != 2)
	{
		printf("Usage: %s filename.\n", argv[0]);
		_exit(-1);
	}
	
	//创建并打开一个指定filename的文件，如果文件存在就返回
	fd = open(argv[1], O_RDWR | O_CREAT | O_EXCL, 0666);
	if(fd == -1)
	{
		perror("open");
		_exit(-1);
	}

	//利用dup2重定向
	fd1 = dup2(fd, 1);
	ret = write(fd1, buf, strlen(buf));
	if(ret == -1)
	{
		//perror("write");
		_exit(-1);
	}
	close(fd);
	
	return 0;
}
