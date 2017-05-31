//利用结构体内嵌函数指针实现分层
#ifndef __CALC_H__
#define __CALC_H__

#include <stdio.h>

typedef int (*pOper)(int, int);

struct Calc
{
	int a;
	int b;
	pOper op;
};

//计算器函数原型声明
int calulator(struct Calc *calc);
//加
int add(int a, int b);
//减
int sub(int a, int b);
//乘
int mul(int a, int b);
//除
int div(int a, int b);

#endif
