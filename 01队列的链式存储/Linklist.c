#include "Linklist.h"

//初始化函数
void *Init_ListList()
{
	//头节点的空间
	LList *list = (LList*)malloc(sizeof(LList));
	if (list == NULL)
	{
		return NULL;
	}

	list->head.next = NULL;
	list->size = 0;
	return list;
}

//指定位置插入
void InsertByPos_ListList(void *list, int pos, LinkNode *data)
{
	if (list == NULL || data == NULL)
	{
		return;
	}
	LList *mylist = (LList*)list;
	if (pos<0 || pos>mylist->size)
	{
		pos = mylist->size;
	}

	//找到pos位置节点的前一个节点
	LinkNode *pCur = &(mylist->head);
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}

	//将新节点入链表
	data->next = pCur->next;
	pCur->next = data;

	mylist->size++;


}
//遍历
void Foreach_LinkNode(void *list, void(*foreach)(void *))
{
	if (list == NULL || foreach == NULL)
	{
		return;
	}
	LList *mylist = (LList*)list;

	LinkNode *pCur = mylist->head.next;

	while (pCur!=NULL)
	{
		foreach(pCur);
		pCur = pCur->next;

	}


}
//根据位置获取值
void *Get_LinkNode(void *list, int pos)
{
	if (list == NULL)
	{
		return NULL;
	}
	LList *mylist = (LList*)list;
	if (pos<0 || pos>mylist->size - 1)
	{
		return NULL;
	}

	LinkNode *pCur = &(mylist->head);
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}

	return pCur->next;

}
//获取元素个数
int Size_LinkNode(void *list)
{
	if (list == NULL)
	{
		return -1;
	}
	LList *mylist = (LList*)list;

	return mylist->size;

}
//根据位置删除
void RemoveByPos_LinkNode(void *list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	LList *mylist = (LList*)list;

	if (mylist->size == 0)
	{
		return;
	}

	if (pos<0 || pos>mylist->size)
	{
		return;
	}

	LinkNode *pCur = &(mylist->head);
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}

	//缓存待删除的节点
	LinkNode *Del = pCur->next;
	//重新建立前后驱关系
	pCur->next = Del->next;

	mylist->size--;

}
//销毁
void Destroy_LinkNode(void *list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
}
