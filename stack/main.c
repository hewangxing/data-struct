#include "stack.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	SqStack *S;
	Status state;
	SElemType e;
	int i = 0;
	
	//初始化栈
	state = initStack(S);
	if(state == ERROR)
	{
		printf("init stack failed!\n");
		_exit(-1);
	}
	printf("init stack success!\n");
	
	//压栈
	for(i = 0; i < 10; i++)
		push(S, i);
	
	//判断栈是否空
	if(isStackEmpty(S) == OK)
		printf("stack is not empty!\n");
	else
		printf("stack is empty!\n");
	//获得栈顶指针元素
	getTop(S, &e);
	printf("the top value of stack = %d.\n", e);
	//获得堆栈元素个数
	printf("the length of stack: %d.\n", stackLength(S));
	
	//清空栈
	clearStack(S);

	//出栈
	for(i = 0; i < 10; i++)
	{
		pop(S, &e);
		printf("%d data of stack is %d.\n", i, e);
	}
	
	//销毁栈
	destroyStack(S);	
	return 0;
}