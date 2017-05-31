#include "calc.h"

//¼ÆËãÆ÷
int calulator(struct Calc *calc)
{
	return calc->op(calc->a, calc->b);
}

//¼Ó
int add(int a, int b)
{
	return a + b;
}

//¼õ
int sub(int a, int b)
{
	return a - b;
}

//³Ë
int mul(int a, int b)
{
	return a * b;
}

//³ı
int div(int a, int b)
{
	return a / b;
}
