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
	struct Data *pData; //����һ��˫��ѭ�������ͷָ��
	struct Data pHead; //����һ��˫��ѭ�������ͷ���
	struct list_head *pos, *next;
	int i = 0;
	
	//��ʼ��ͷ��㣺��list�ڵ��ǰ�̽ڵ�ͺ�̽ڵ㶼��ָ��list���� 
	INIT_LIST_HEAD(&(pHead.list));
	
	//��ӽ��
	for(i = 0; i < 10; i++)
	{
		pData = (struct Data *)malloc(sizeof(struct Data));
		pData->data = i;
		list_add_tail(&(pData->list), &(pHead.list));
	}
	
	//�����ڵ�
	//list_for_each(pos, head) for (pos = (head)->next; pos != (head); pos = pos->next) 
	list_for_each(pos, &(pHead.list))
	{
		pData = list_entry(pos, struct Data, list);
		printf("pData->data = %d.\n", pData->data);
	}
	
	//ɾ���ڵ�
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
	
	//�����ڵ�
	//list_for_each(pos, head) for (pos = (head)->next; pos != (head); pos = pos->next) 
	list_for_each(pos, &(pHead.list))
	{
		pData = list_entry(pos, struct Data, list);
		printf("pData->data = %d.\n", pData->data);
	}
	
	//�ͷ�������ڴ�ռ�
	printf("---------release all nodes---------\n");
	list_for_each_safe(pos, next, &(pHead.list))
	{
		pData = list_entry(pos, struct Data, list);
		list_del_init(&(pData->list));
		free(pData);
	}
	
	return 0;
}