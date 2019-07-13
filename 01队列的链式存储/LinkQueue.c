#include "LinkQueue.h"

//��ʼ��
void *Init_SQueue()
{
	return Init_ListList();
}

//���
void Push_SQueue(void *queue, void *data)
{
	InsertByPos_ListList(queue, 0, data);
}
//����
void Pop_SQueue(void *queue)
{
	RemoveByPos_LinkNode(queue, Size_LinkNode(queue) - 1);
}

//��ȡ��ͷԪ��
void *Front_SQueue(void *queue)
{
	return Get_LinkNode(queue, Size_LinkNode(queue) - 1);
}

//��ȡ��βԪ��
void *Back_SQueue(void *queue)
{
	return Get_LinkNode(queue, 0);
}
//��ȡԪ�ظ���
int Size_SQueue(void *queue)
{
	return Size_LinkNode(queue);
}
//���ٶ���
void Destroy_SQueue(void *queue)
{
	Destroy_LinkNode(queue);
}