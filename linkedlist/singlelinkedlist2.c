#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct node
{
	int data;  //有效数据
	struct node* pNext; //指向下一个节点的指针
};
\
//创建一个节点
//参数：需要存放的数据data
//返回值：指向新创建节点首地址的指针
struct node *create_node(int data)
{
	//step1:申请一个节点的内存空间(堆空间)
	struct node *p = (struct node *) malloc(sizeof(struct node));
	//step2:确认分配节点的内存空间是否有效
	if(NULL == p)
	{
		printf("malloc error!\n");
		return 	NULL;
	}
	//step3:清理申请到的节点的内存空间为0
	bzero(p, sizeof(struct node));
	//step4:往节点中存数据
	p->data = data;
	p->pNext = NULL;
	
	return p;
}

//在链表的尾部插入一个新节点
//参数：输入头指针和新创建节点的指针
//注意：要求头指针必须指向第一个节点
void insert_tail(struct node *pHeader, struct node *new)
{
	//分两步走
	//先找到最后一个节点
	int cnt = 0;
	struct node *p = pHeader;
	while(NULL != p->pNext)
	{
		p = p->pNext; //往后走一步
		cnt++;
	}
	//再把新节点链接到最后一个节点
	p->pNext = new;
	pHeader->data = cnt + 1;
}


int main(void)
{
	//创建头指针
	struct node *pHeader = create_node(0);

	insert_tail(pHeader, create_node(111));
	insert_tail(pHeader, create_node(222));
	insert_tail(pHeader, create_node(333));
	
	//打印节点存放的数据
	//注意：要用头指针来访问，不要用各个节点的指针，因为实际使用的时候只保留头指针。
	printf("pHeader->data = %d\n", pHeader->data); //相当于头节点的数据，用来记录链表的长度信息
	
	printf("pHeader->data = %d\n", pHeader->pNext->data); //相当于 p1->data
	
	printf("pHeader->data = %d\n", pHeader->pNext->pNext->data); //相当于 p2->data
	
	printf("pHeader->data = %d\n", pHeader->pNext->pNext->pNext->data); //相当于 p3->data
	
	return 0;
}

