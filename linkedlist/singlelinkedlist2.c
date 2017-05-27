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

//在链表的尾部插入一个新节点
//参数：输入头指针和新创建节点的指针

void insert_head(struct node *pHeader, struct node *new)
{
	//第一步：把新节点和原来的第一个节点连接起来
	new->pNext = pHeader->pNext;
	
	//第二步：把头节点和新节点连接起来
	pHeader->pNext = new;
	
	//第三步：把头节点的计数值加1
	pHeader->data++;
}

//用来遍历链表的每一个节点
//方法一：用头指针的方式
void Traversal_node(struct node *pHeader)
{
	//头结点的数据不用打印 pHeader->data
	struct node *p = pHeader->pNext;
	printf("---------START-----------\n");
	while(NULL != p->pNext)
	{
		printf("node data = %d\n", p->data);
		p = p->pNext;	
	}
	//需要补一刀以免遗漏最后一个节点的数据
	printf("node data = %d\n", p->data);
	printf("----------END------------\n");

}

//用来遍历链表的每一个节点
//方法一：用头指针+头节点的方式
//头节点的创造完美的解决了边界问题，浑然一体，perfect
void Traversal_node1(struct node *pHeader)
{
	//头结点的数据不用打印 pHeader->data
	struct node *p = pHeader;
	printf("---------START-----------\n");
	while(NULL != p->pNext)
	{	
		p = p->pNext;
		printf("node data = %d\n", p->data);			
	}
	printf("----------END------------\n");

}

//删除数值为data的所有节点
//成功删除返回0，否则返回-1
int delete_node(struct node *pHeader, int data)
{
	//遍历每个节点，并把节点中的值和data作比较
	struct node *p = pHeader;
	struct node *pPrev = NULL;
	int cnt = 0; 	//用来计算删除了几个节点
	while(NULL != p->pNext)
	{
		pPrev = p; //先把上一个节点的指针保存
		p = p->pNext;
		if(p->data == data)
		{
			//找到值为data的节点后删除该节点
		    pPrev->pNext = p->pNext;
			//释放该节点的内存空间
			free(p);
			cnt++; 
		}
	}
	if(cnt != 0)
	{
		printf("%d data were deleted!\n", cnt);
		return 0;
	}
	printf("Can't find the data!\n");
	return -1;	
}

//pHeader指向的链表的逆序
void reverse_node(struct node *pHeader)
{
	struct node* p = pHeader->pNext; //pHeader指向头节点，p指向第一个有效节点
	struct node* pBack;
	//排除0或者1个有效节点的情况
	if((NULL == p) || (NULL == p->pNext))
		return;
		
	while(NULL != p->pNext)
	{
		pBack = p->pNext; //用于保存当前节点的下一个节点
		
		//判断是否是第一个有效节点
		if (p == pHeader->pNext)
			p->pNext = NULL;
		else
			insert_head(pHeader, p);
		
		p = pBack;
	}
	//把尾节点头插入pHeader指向的链表
	insert_head(pHeader, p);
}

int main(void)
{
	//创建头指针的同时创建头节点并且把头指针指向头节点
	struct node *pHeader = create_node(0);

	insert_tail(pHeader, create_node(111));
	insert_tail(pHeader, create_node(222));
	insert_tail(pHeader, create_node(333));
	insert_tail(pHeader, create_node(444));
	insert_tail(pHeader, create_node(555));
	
	Traversal_node1(pHeader);
	reverse_node(pHeader);
	Traversal_node1(pHeader);
	return 0;
}

