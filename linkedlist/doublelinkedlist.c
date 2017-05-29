//双链表的基本操作
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct node 
{
	int data;
	struct node *pPrev;
	struct node *pNext;
};

//创建节点
struct node *create_node(int data)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	if(NULL == p)
	{
		printf("malloc error!\n");
		return NULL;
	}
	bzero(p, sizeof(struct node));
	p->data = data;
	p->pPrev = NULL;
	p->pNext = NULL;
}

//尾插法
void insert_tail(struct node *pHeader, struct node *new)
{
	struct node *p = pHeader;
	//没有头结点的情况
	if(NULL == p)
	{
		return;
	}
	
	while(NULL != p->pNext)
	{
		p = p->pNext;
	}
	
	p->pNext = new;
	new->pPrev = p;
	pHeader->data++;
}

//头插法
void insert_head(struct node *pHeader, struct node *new)
{
	struct node *p = pHeader;
	//没有头结点的情况
	if(NULL == p)
	{
		return;
	}
	
	if(NULL == p->pNext)
	{		
		p->pNext = new;
		new->pPrev = p;
	}
	else
	{	
		new->pNext = p->pNext;
		p->pNext->pPrev = new;
		p->pNext = new;
		//new->pNext->pPrev = new;
		new->pPrev = p;
	}
	pHeader->data++;
}

//遍历pHeader指向的节点
//利用后向指针、前向指针各遍历一次
void Traversal(struct node *pHeader)
{
	struct node *p = pHeader;
	
	//没有头结点的情况
	if(NULL == p)
	{
		return;
	}
	
	printf("---Next START---\n");
	while(NULL != p->pNext)
	{
		p = p->pNext;
		printf("p->data = %d\n", p->data);
	}
	printf("---Prev START--\n");
	while(NULL != p->pPrev)
	{
		printf("p->data = %d\n", p->data);
		p = p->pPrev;
	}
	printf("---END---\n");
}

//删除有效数据为data的节点
void delete_node(struct node *pHeader, int data)
{
	struct node *p = pHeader;
	int cnt = 0;
	
	//没有头结点的情况
	if(NULL == p)
	{
		return;
	}
	
	while(NULL != p->pNext)
	{
		p = p->pNext;
		//判断是否找到需要删除的节点
		if(p->data == data)
		{
			//判断是否是尾节点
			if(NULL == p->pNext)
			{
				p->pPrev->pNext = NULL;
			
			}
			else
			{
				p->pPrev->pNext = p->pNext;
				p->pNext->pPrev = p->pPrev;
			}
			free(p);
			cnt++;
			pHeader->data--;			
		}
	}
	
	if(cnt != 0)
		printf("%d data were deleted!\n", cnt);
	else
		printf("No data were deleted!\n");
}

int main(void)
{
	struct node *pHeader = create_node(0);
	//struct node *pHeader = NULL;
	insert_tail(pHeader, create_node(111));
	insert_tail(pHeader, create_node(222));
	insert_tail(pHeader, create_node(333));
	
	Traversal(pHeader);
	delete_node(pHeader, 111);
	
	printf("---after delete---\n");
	Traversal(pHeader);
	return 0;
}