#include "stack.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	SqStack *S;
	Status state;
	SElemType e;
	int i = 0;
	
	//��ʼ��ջ
	state = initStack(S);
	if(state == ERROR)
	{
		printf("init stack failed!\n");
		_exit(-1);
	}
	printf("init stack success!\n");
	
	//ѹջ
	for(i = 0; i < 10; i++)
		push(S, i);
	
	//�ж�ջ�Ƿ��
	if(isStackEmpty(S) == OK)
		printf("stack is not empty!\n");
	else
		printf("stack is empty!\n");
	//���ջ��ָ��Ԫ��
	getTop(S, &e);
	printf("the top value of stack = %d.\n", e);
	//��ö�ջԪ�ظ���
	printf("the length of stack: %d.\n", stackLength(S));
	
	//���ջ
	clearStack(S);

	//��ջ
	for(i = 0; i < 10; i++)
	{
		pop(S, &e);
		printf("%d data of stack is %d.\n", i, e);
	}
	
	//����ջ
	destroyStack(S);	
	return 0;
}