#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>

#define MAXSIZE 100 //栈的最大空间
typedef int SElemType;

typedef enum 
{
	ERROR = -1,
	OK = 0,
}Status;

typedef struct 
{
	SElemType data[MAXSIZE];
	int top; //栈顶
}SqStack; 

Status initStack(SqStack *S);
Status destroyStack(SqStack *S);
Status clearStack(SqStack *S);
Status isStackEmpty(SqStack *S);
Status getTop(SqStack *S, SElemType *e);
Status push(SqStack *S, SElemType e);
Status pop(SqStack *S, SElemType *e);
int stackLength(SqStack *S);

#endif /*__STACK_H__*/