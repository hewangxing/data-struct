#include "stack.h"

//��ʼ������������һ����ջ
Status initStack(SqStack *S)
{
	if(NULL == S)
		return ERROR;
		
	S->top = -1;
	return OK;
}

//���һ��ջ������������
Status destroyStack(SqStack *S)
{
	if(NULL == S)
		return ERROR;
		
	S = NULL;	
	return OK;
}

//��ջ���
Status clearStack(SqStack *S)
{
	if(NULL == S | S->top == -1)
		return ERROR;
		
	S->top == -1;	
	
	return OK;
}

//��ջΪ�գ�����OK, ���򷵻�ERROR
Status isStackEmpty(SqStack *S)
{
	if(NULL == S | S->top == -1)
		return ERROR;
	else
		return OK;
}

//���ջ�����ҷǿգ�����e����ջ��Ԫ�ص�ֵ
//���򷵻�-1
Status getTop(SqStack *S, SElemType *e)
{
	if(S->top == -1 || NULL == S)
		return ERROR;
	
	*e = S->data[S->top];
	
	return OK;
}

//��ջ
Status push(SqStack *S, SElemType e)
{
	if(S->top == (MAXSIZE - 1) || NULL == S)
		return ERROR;
	S->top++;
	S->data[S->top]	= e;
	
	return OK;
}

//��ջ 
Status pop(SqStack *S, SElemType *e)
{
	if(S->top == -1 || NULL == S)
		return ERROR;
	*e = S->data[S->top];
	S->top--;

	return OK;
}


//�ɹ�����ջS��Ԫ�ظ���, ʧ�ܷ���-1��
int stackLength(SqStack *S)
{
	if(S->top == -1 || NULL == S)
		return ERROR;
		
	return S->top + 1;
}

