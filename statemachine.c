//��״̬��ʵ�ּ򵥵�������
//��������������ͬ���û����������ʵ��״̬���л���
//		��һ��������ֱ���������룬��������
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
	STATE current_state = STATE1; //������¼��ǰ״̬
	
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
					current_state++; //�л�����һ״̬
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
				current_state = STATE1; //�������뱨��
				printf("You are wrong! Please start from scratch!\n");
		
		}
		if(current_state == STATE7) //����������ȷ
		{
			printf("The lock was unlocked!\n");
			break;
		}
	}
	
	return 0;
}