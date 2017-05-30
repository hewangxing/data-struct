//用状态机实现简单的密码锁
//描述：该密码锁同过用户的输入可以实现状态的切换，
//		且一旦输错可以直接重新输入，不用重置
#include <stdio.h>

typedef enum
{
	STATE1 = 0,
	STATE2,
	STATE3,
	STATE4,
	STATE5,
	STATE6,
	STATE7,

}STATE;

int password[6] ={3, 5, 4, 2, 0, 0};

int main(void)
{
	int num = 0;
	STATE current_state = STATE1; //用来记录当前状态
	
	printf("Please input password to unlock the lock!\n");
	while(1)
	{
		scanf("%d", &num);
		printf("num = %d.\n", num);
		switch(current_state)
		{
			case STATE1:
				if(num == password[0])
				{
					current_state++; //切换到下一状态
				}
				else
				{
					current_state = STATE1;
				}
				break;
			case STATE2:
				if(num == password[1])
				{
					current_state++;
				}
				else
				{
					current_state = STATE1;
				}
				break;
			case STATE3:
				if(num == password[2])
				{
					current_state++;
				}
				else
				{
					current_state = STATE1;
				}
				break;
			case STATE4:
				if(num == password[3])
				{
					current_state++;
				}
				else
				{
					current_state = STATE1;
				}
				break;
			case STATE5:
				if(num == password[4])
				{
					current_state++;
				}
				else
				{
					current_state = STATE1;
				}
				break;
			case STATE6:
				if(num == password[5])
				{
					current_state++;
				}
				else
				{
					current_state = STATE1;
				}
				break;
			default:
				current_state = STATE1; //错误输入报错
				printf("You are wrong! Please start from scratch!\n");
		
		}
		if(current_state == STATE7) //密码输入正确
		{
			printf("The lock was unlocked!\n");
			break;
		}
	}
	
	return 0;
}