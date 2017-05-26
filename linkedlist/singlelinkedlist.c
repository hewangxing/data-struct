#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct node
{
	int data;  //有效数据
	struct node* pNext; //指向下一个节点的指针
};

int main(void)
{
	//创建头指针
	struct node *pHeader;
	
	/*****************************/
	//创建一个节点
	//step1:申请一个节点的内存空间(堆空间)
	struct node *p = (struct node *) malloc(sizeof(struct node));
	//step2:确认分配节点的内存空间是否有效
	if(NULL == p)
	{
		printf("malloc error!\n");
		return -1;
	}
	//step3:清理申请到的节点的内存空间为0
	bzero(p, sizeof(struct node));
	//step4:往节点中存数据，并把节点关联起来
	p->data = 1;
	p->pNext = NULL;
	pHeader = p;
	/*****************************/
	
	//创建一个节点
	//step1:申请一个节点的内存空间(堆空间)
	struct node *p1 = (struct node *) malloc(sizeof(struct node));
	//step2:确认分配节点的内存空间是否有效
	if(NULL == p1)
	{
		printf("malloc error!\n");
		return -1;
	}
	//step3:清理申请到的节点的内存空间为0
	bzero(p1, sizeof(struct node));
	//step4:往节点中存数据，并把节点关联起来
	p1->data = 2;
	p1->pNext = NULL;
	p->pNext = p1;
	/*****************************/
	
	//创建一个节点
	//step1:申请一个节点的内存空间(堆空间)
	struct node *p2 = (struct node *) malloc(sizeof(struct node));
	//step2:确认分配节点的内存空间是否有效
	if(NULL == p1)
	{
		printf("malloc error!\n");
		return -1;
	}
	//step3:清理申请到的节点的内存空间为0
	bzero(p2, sizeof(struct node));
	//step4:往节点中存数据，并把节点关联起来
	p2->data = 3;
	p2->pNext = NULL;
	p1->pNext = p2;
	/*****************************/
	
	//打印节点存放的数据
	//注意：要用头指针来访问，不要用各个节点的指针，因为实际使用的时候只保留头指针。
	printf("pHeader->data = %d\n", pHeader->data); //相当于 p->data
	printf("p->data = %d\n", p->data);
	
	printf("pHeader->data = %d\n", pHeader->pNext->data); //相当于 p1->data
	printf("p1->data = %d\n", p1->data);
	
	printf("pHeader->data = %d\n", pHeader->pNext->pNext->data); //相当于 p2->data
	printf("p2->data = %d\n", p2->data);
	
	return 0;
}
