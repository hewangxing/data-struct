//���ýṹ����Ƕ����ָ��ʵ�ֲַ�
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

//����������ԭ������
int calulator(struct Calc *calc);
//��
int add(int a, int b);
//��
int sub(int a, int b);
//��
int mul(int a, int b);
//��
int div(int a, int b);

#endif
