#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//�������Ľڵ�
typedef struct BiNode{
	char ch;

	struct BiNode *Lchild;
	struct BiNode *Rchild;


}BiNode;
void printfMaker(BiNode *root)
{
	if (root == NULL)
	{
		return;
	}

	//��������������ң�
	printf("%c ", root->ch);
	//�ٷ���������
	printfMaker(root->Lchild);
	//�ٷ���������
	printfMaker(root->Rchild);
}

BiNode *copyTree(BiNode *root)
{
	if (root == NULL)
	{
		return NULL;
	}

	//�ݹ鿽��������
	BiNode *l=copyTree(root->Lchild);
	//�ݹ鿽��������
	BiNode *r = copyTree(root->Rchild);
	//����ռ䣬װ����
	BiNode *newnode = (BiNode*)malloc(sizeof(BiNode));
	//����
	newnode->ch = root->ch;
	newnode->Lchild = l;
	newnode->Rchild = r;

	return newnode;
}

void freeSpace(BiNode *root)
{
	if (root == NULL)
	{
		return;
	}

	//�ͷ�������
	freeSpace(root->Lchild);
	//�ͷ�������
	freeSpace(root->Rchild);
	//�ͷŸ��ڵ�
	free(root);
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

	//����������
	BiNode *root = copyTree(&node1);
	//��ӡԭ������
	printfMaker(&node1);
	printf("\n-----------------\n");
	//��ӡ��������
	printfMaker(root);

	//�ͷſ����Ķ������ռ�
	freeSpace(root);



	system("pause");
	return EXIT_SUCCESS;
}

