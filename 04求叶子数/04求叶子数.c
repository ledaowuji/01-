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

void caculateNums(BiNode *root, int *num)
{
	//�ݹ��˳�����
	if (root == NULL)
	{
		return;
	}

	//���ڵ�����Ӻ��Һ��Ӷ�Ϊ��ʱ������ڵ����Ҷ�ӽڵ�
	if (root->Lchild == NULL && root->Rchild == NULL)
	{
		(*num)++;
	}
	//����������
	caculateNums(root->Lchild, num);
	//����������

	caculateNums(root->Rchild, num);
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

	//��Ҷ����
	int num = 0;
	caculateNums(&node1,&num);

	printf("num=%d\n", num);



	system("pause");
	return EXIT_SUCCESS;
}

