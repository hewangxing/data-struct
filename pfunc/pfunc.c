//利用函数指针实现简单的OOP多态
#include <stdio.h>
typedef int (*pFunc)(int, int);

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main(void)
{
	int a = 0, b = 0;
	int c = 0;
	char op = 0;
	pFunc p = NULL;
	 
	printf("Please input two integers:\n");
	scanf("%d %d", &a, &b);
	printf("Please input operator + | - | * | /:\n");
	getchar();  //把上次输入的\n从缓冲区中清除
	scanf("%c", &op);
	
	switch(op)
	{
		case '+': p = add;break;
		case '-': p = sub;break;
		case '*': p = mul;break;
		case '/': p = div;break;	
		default:
			p = NULL;
			printf("sorry for your incorrect input.\n");
			return 0;
	}
	
	c = p(a, b);
	printf("%d %c %d = %d\n", a, op, b, c);
	
	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return a / b;
}
