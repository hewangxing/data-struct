#include "stack.h"

//初始化操作，建立一个空栈
Status initStack(SqStack *S)
{
	if(NULL == S)
		return ERROR;
		
	S->top = -1;
	return OK;
}

//如果一个栈存在则销毁它
Status destroyStack(SqStack *S)
{
	if(NULL == S)
		return ERROR;
		
	S = NULL;	
	return OK;
}

//将栈清空
Status clearStack(SqStack *S)
{
	if(NULL == S | S->top == -1)
		return ERROR;
		
	S->top == -1;	
	
	return OK;
}

//若栈为空，返回OK, 否则返回ERROR
Status isStackEmpty(SqStack *S)
{
	if(NULL == S | S->top == -1)
		return ERROR;
	else
		return OK;
}

//如果栈存在且非空，则用e返回栈顶元素的值
//否则返回-1
Status getTop(SqStack *S, SElemType *e)
{
	if(S->top == -1 || NULL == S)
		return ERROR;
	
	*e = S->data[S->top];
	
	return OK;
}

//进栈
Status push(SqStack *S, SElemType e)
{
	if(S->top == (MAXSIZE - 1) || NULL == S)
		return ERROR;
	S->top++;
	S->data[S->top]	= e;
	
	return OK;
}

//出栈 
Status pop(SqStack *S, SElemType *e)
{
	if(S->top == -1 || NULL == S)
		return ERROR;
	*e = S->data[S->top];
	S->top--;

	return OK;
}


//成功返回栈S的元素个数, 失败返回-1，
int stackLength(SqStack *S)
{
	if(S->top == -1 || NULL == S)
		return ERROR;
		
	return S->top + 1;
}

