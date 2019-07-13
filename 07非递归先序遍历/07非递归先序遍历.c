#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SeqStack.h"
#include<stdbool.h>//����ͷ�ļ�

//�������Ľڵ�
typedef struct BiNode{
	char ch;

	struct BiNode *Lchild;
	struct BiNode *Rchild;


}BiNode;

//�б�־������
typedef struct Info{
	BiNode *node;
	bool flag;
}Info;

Info *CreateInfo(BiNode *node, bool flag)
{
	Info *info = (Info*)malloc(sizeof(Info));

	info->node = node;
	info->flag = flag;

	return info;
}

void Freeforeach(BiNode *root)
{
	//��ʼ��ջ
	void *stack = Init_SeqStack();
	//1.�ȰѸ��ڵ���ջ
	Push_SeqStack(stack, CreateInfo(root,false));

	while (Size_SeqStack(stack)>0)
	{
		//2.��ȡջ��Ԫ��,��Ϊѹջʱ���������Info��������
		Info *info = (Info*)Top_SeqStack(stack);
		//3.����ջ��Ԫ��
		Pop_SeqStack(stack);
		//4.�жϵ�����Ԫ�صı�־�Ƿ�Ϊtrue,��true�����
		if (info->flag)
		{
			printf("%c ", info->node->ch);

			free(info);

			//��������������ߴ���
			continue;
		}
		

		//���������Ԫ�ر�־��Ϊtrue,ȡ���ýڵ�����Һ���
		//�Һ�����ջ
		if (info->node->Rchild != NULL)
		{
			Push_SeqStack(stack, CreateInfo(info->node->Rchild, false));
		}

		


		//������ջ
		if (info->node->Lchild != NULL)
		{
			Push_SeqStack(stack, CreateInfo(info->node->Lchild, false));
		}

		//���ڵ���ջ
		info->flag = true;
		Push_SeqStack(stack, info);


		//���ڵ��������������������м��������������ǰ���Ǻ������

		
	}


}

int main()
{
	BiNode node1 = { 'A', NULL, NULL };
	BiNode node2 = { 'B', NULL, NULL };
	BiNode node3 = { 'C', NULL, NULL };
	BiNode node4 = { 'D', NULL, NULL };
	BiNode node5 = { 'E', NULL, NULL };
	BiNode node6 = { 'F', NULL, NULL };
	BiNode node7 = { 'G', NULL, NULL };
	BiNode node8 = { 'H', NULL, NULL };

	//����������
	node1.Lchild = &node2;
	node1.Rchild = &node6;

	node2.Rchild = &node3;

	node3.Lchild = &node4;
	node3.Rchild = &node5;

	node6.Rchild = &node7;

	node7.Lchild = &node8;


	//�ǵݹ��������
	Freeforeach(&node1);


	system("pause");
	return EXIT_SUCCESS;
}

