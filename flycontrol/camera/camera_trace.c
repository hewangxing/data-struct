//本例程用于四旋翼无人机寻迹，输入为camera采集的二值化图像
//输出为提取轨迹中心点的一维数组
//bug: 插值算法缺陷，第一行值如果偏差较大会直接导致后面的值偏离正常值
//未加中指滤波
#include <stdio.h>
#include <stdlib.h>

#define ROW 20 
#define COL 20
#define THRESHOLD 3   //插值的偏差上限
#define CONTINUE 2    //连续性的条件，根据摄像头采集的黑色轨道像素宽度来选取
//黑点为1 白点为0
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
	unsigned int i = 0, j = 0, a = 0, b = 0; //a、b分别计算连续白点、黑点的个数
	unsigned int flag = 0; //flag用来标记第一个点是黑是白
	unsigned int black_cnt = 0, white_cnt = 0; //black_cnt、white_cnt分别对单次黑、白点进行计数
	unsigned int total_black = 0; //总的黑点数减去b即为遇到白点的次数
	unsigned int midpoint[ROW];
	
	//提取轨迹中心点
	printf("before chazhi: \n");
	for(i = 0; i < ROW; i++)
	{		
		a = b = 0 ;
		total_black = 0;
		black_cnt = white_cnt = 0;
		flag = image_array[i][0];
		
		for(j = 0; j < COL; j++)
		{	
			//判断每行的第一个点是否为白点
			if(flag == 0)
			{
				if(image_array[i][j] == 0)
				{
					black_cnt = 0;
					if(total_black >= 1 && b >= CONTINUE)
					{
						a += (total_black - b); //把黑色噪点计做白点
						break;	
					}	
					a++;				
				}
				else if(image_array[i][j] == 1)
				{			
					black_cnt++;
					total_black++;
					if(black_cnt >= CONTINUE)//是否遇到连续的黑点
						b = black_cnt;		
				}
			}
			
			//判断每行的第一个点是否为黑点
			if(flag == 1)
			{
				if(image_array[i][j] == 1)
				{				
					black_cnt++;
					if(black_cnt >= CONTINUE)//是否遇到连续的黑点
					{
						b = black_cnt;
					}
				}
				else if(image_array[i][j] == 0)
				{
					white_cnt++;
					if(white_cnt >= CONTINUE && black_cnt >= CONTINUE)//是否遇到连续的白点
					{
						break;
					}
					else if(white_cnt >= CONTINUE && black_cnt < CONTINUE)//是否遇到连续的白点
					{
						//把第一个点当做白点同时回退到flag = 0的情况
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
	
	
	//改进插值算法
	printf("\nafter chazhi: \n");	
	for(i = 1; i < ROW - 1; i++)
	{
		//当前点和前一点差值是否过大
		if(abs(midpoint[i] - midpoint[i-1]) >= THRESHOLD)
		{
			//当前点前一点和后一点差值是否过大
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
	
	//处理最后一点
	if(abs(midpoint[ROW-1] - midpoint[ROW-2]) >= THRESHOLD)
		midpoint[ROW-1] = midpoint[ROW-2];
	
	for(i = 0; i < ROW; i++)
		printf("%d ", midpoint[i]);
	
	
	return 0;
}
