#include "LinkQueue.h"

//初始化
void *Init_SQueue()
{
	return Init_ListList();
}

//入队
void Push_SQueue(void *queue, void *data)
{
	InsertByPos_ListList(queue, 0, data);
}
//出队
void Pop_SQueue(void *queue)
{
	RemoveByPos_LinkNode(queue, Size_LinkNode(queue) - 1);
}

//获取队头元素
void *Front_SQueue(void *queue)
{
	return Get_LinkNode(queue, Size_LinkNode(queue) - 1);
}

//获取队尾元素
void *Back_SQueue(void *queue)
{
	return Get_LinkNode(queue, 0);
}
//获取元素个数
int Size_SQueue(void *queue)
{
	return Size_LinkNode(queue);
}
//销毁队列
void Destroy_SQueue(void *queue)
{
	Destroy_LinkNode(queue);
}