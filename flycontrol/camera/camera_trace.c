//�������������������˻�Ѱ��������Ϊcamera�ɼ��Ķ�ֵ��ͼ��
//���Ϊ��ȡ�켣���ĵ��һά����
//bug: ��ֵ�㷨ȱ�ݣ���һ��ֵ���ƫ��ϴ��ֱ�ӵ��º����ֵƫ������ֵ
//δ����ָ�˲�
#include <stdio.h>
#include <stdlib.h>

#define ROW 20 
#define COL 20
#define THRESHOLD 3   //��ֵ��ƫ������
#define CONTINUE 2    //�����Ե���������������ͷ�ɼ��ĺ�ɫ������ؿ����ѡȡ
//�ڵ�Ϊ1 �׵�Ϊ0
unsigned int image_array[ROW][COL] = 
	{
		1,0,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,
		0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,
		0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,
		0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,
		0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,
		1,0,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,
		0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,
		0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,
		1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,
		0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,
		0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,
		0,0,1,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,
		0,0,0,1,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,	
		0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,
	};	
int main(void)
{
	unsigned int i = 0, j = 0, a = 0, b = 0; //a��b�ֱ���������׵㡢�ڵ�ĸ���
	unsigned int flag = 0; //flag������ǵ�һ�����Ǻ��ǰ�
	unsigned int black_cnt = 0, white_cnt = 0; //black_cnt��white_cnt�ֱ�Ե��κڡ��׵���м���
	unsigned int total_black = 0; //�ܵĺڵ�����ȥb��Ϊ�����׵�Ĵ���
	unsigned int midpoint[ROW];
	
	//��ȡ�켣���ĵ�
	printf("before chazhi: \n");
	for(i = 0; i < ROW; i++)
	{		
		a = b = 0 ;
		total_black = 0;
		black_cnt = white_cnt = 0;
		flag = image_array[i][0];
		
		for(j = 0; j < COL; j++)
		{	
			//�ж�ÿ�еĵ�һ�����Ƿ�Ϊ�׵�
			if(flag == 0)
			{
				if(image_array[i][j] == 0)
				{
					black_cnt = 0;
					if(total_black >= 1 && b >= CONTINUE)
					{
						a += (total_black - b); //�Ѻ�ɫ�������׵�
						break;	
					}	
					a++;				
				}
				else if(image_array[i][j] == 1)
				{			
					black_cnt++;
					total_black++;
					if(black_cnt >= CONTINUE)//�Ƿ����������ĺڵ�
						b = black_cnt;		
				}
			}
			
			//�ж�ÿ�еĵ�һ�����Ƿ�Ϊ�ڵ�
			if(flag == 1)
			{
				if(image_array[i][j] == 1)
				{				
					black_cnt++;
					if(black_cnt >= CONTINUE)//�Ƿ����������ĺڵ�
					{
						b = black_cnt;
					}
				}
				else if(image_array[i][j] == 0)
				{
					white_cnt++;
					if(white_cnt >= CONTINUE && black_cnt >= CONTINUE)//�Ƿ����������İ׵�
					{
						break;
					}
					else if(white_cnt >= CONTINUE && black_cnt < CONTINUE)//�Ƿ����������İ׵�
					{
						//�ѵ�һ���㵱���׵�ͬʱ���˵�flag = 0�����
						flag = 0;
						a = 1;
						j -= white_cnt;
						continue;
					}
				}
			}
		}
		midpoint[i] = a + b / 2;
		printf("%d ", midpoint[i]);	
		
	}
	
	
	//�Ľ���ֵ�㷨
	printf("\nafter chazhi: \n");	
	for(i = 1; i < ROW - 1; i++)
	{
		//��ǰ���ǰһ���ֵ�Ƿ����
		if(abs(midpoint[i] - midpoint[i-1]) >= THRESHOLD)
		{
			//��ǰ��ǰһ��ͺ�һ���ֵ�Ƿ����
			if(abs(midpoint[i-1] - midpoint[i+1]) >= THRESHOLD)
				midpoint[i] = midpoint[i-1];
			else
				midpoint[i] = (midpoint[i-1] + midpoint[i+1]) / 2;
		}		
		else
		{
			//do nothing
		}
	}
	
	//�������һ��
	if(abs(midpoint[ROW-1] - midpoint[ROW-2]) >= THRESHOLD)
		midpoint[ROW-1] = midpoint[ROW-2];
	
	for(i = 0; i < ROW; i++)
		printf("%d ", midpoint[i]);
	
	
	return 0;
}
