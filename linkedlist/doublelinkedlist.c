//˫����Ļ�������
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct node 
{
	int data;
	struct node *pPrev;
	struct node *pNext;
};

//�����ڵ�
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

//β�巨
void insert_tail(struct node *pHeader, struct node *new)
{
	struct node *p = pHeader;
	//û��ͷ�������
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

//ͷ�巨
void insert_head(struct node *pHeader, struct node *new)
{
	struct node *p = pHeader;
	//û��ͷ�������
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

//����pHeaderָ��Ľڵ�
//���ú���ָ�롢ǰ��ָ�������һ��
void Traversal(struct node *pHeader)
{
	struct node *p = pHeader;
	
	//û��ͷ�������
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

//ɾ����Ч����Ϊdata�Ľڵ�
void delete_node(struct node *pHeader, int data)
{
	struct node *p = pHeader;
	int cnt = 0;
	
	//û��ͷ�������
	if(NULL == p)
	{
		return;
	}
	
	while(NULL != p->pNext)
	{
		p = p->pNext;
		//�ж��Ƿ��ҵ���Ҫɾ���Ľڵ�
		if(p->data == data)
		{
			//�ж��Ƿ���β�ڵ�
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