#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Data
{
	int data;
	struct list_head list;
};

int main(void)
{
	struct Data *pData; //定义一个双向循环链表的头指针
	struct Data pHead; //定义一个双向循环链表的头结点
	struct list_head *pos, *next;
	int i = 0;
	
	//初始化头结点：将list节点的前继节点和后继节点都是指向list本身。 
	INIT_LIST_HEAD(&(pHead.list));
	
	//添加结点
	for(i = 0; i < 10; i++)
	{
		pData = (struct Data *)malloc(sizeof(struct Data));
		pData->data = i;
		list_add_tail(&(pData->list), &(pHead.list));
	}
	
	//遍历节点
	//list_for_each(pos, head) for (pos = (head)->next; pos != (head); pos = pos->next) 
	list_for_each(pos, &(pHead.list))
	{
		pData = list_entry(pos, struct Data, list);
		printf("pData->data = %d.\n", pData->data);
	}
	
	//删除节点
	printf("---------delete value = 7 node---------\n");
	list_for_each_safe(pos, next, &(pHead.list))
	{
		pData = list_entry(pos, struct Data, list);
		if(pData->data == 7)
		{
			list_del_init(&(pData->list));
			free(pData);
		}	
	}
	
	//遍历节点
	//list_for_each(pos, head) for (pos = (head)->next; pos != (head); pos = pos->next) 
	list_for_each(pos, &(pHead.list))
	{
		pData = list_entry(pos, struct Data, list);
		printf("pData->data = %d.\n", pData->data);
	}
	
	//释放链表的内存空间
	printf("---------release all nodes---------\n");
	list_for_each_safe(pos, next, &(pHead.list))
	{
		pData = list_entry(pos, struct Data, list);
		list_del_init(&(pData->list));
		free(pData);
	}
	
	return 0;
}