//���ýṹ����Ƕ�ĺ���ָ��ʵ�ּ򵥵�OOP��̬
#include "calc.h"

int main(void)
{
	struct Calc calc;
	char op = 0;
	int ret = 0;
	
	printf("Please input two integers:\n");
	scanf("%d %d", &calc.a, &calc.b);
	printf("Please input operator + | - | * | /:\n");
	getchar();  //���ϴ������\n�ӻ����������
	scanf("%c", &op);
	
	switch(op)
	{
		case '+': calc.op = add;break;
		case '-': calc.op = sub;break;
		case '*': calc.op = mul;break;
		case '/': calc.op = div;break;	
		default:
			calc.op = NULL;
			printf("sorry for your incorrect input.\n");
			return 0;
	}
	
	ret = calulator(&calc);
	printf("%d %c %d = %d\n", calc.a, op, calc.b, ret);
	
	return 0;
}