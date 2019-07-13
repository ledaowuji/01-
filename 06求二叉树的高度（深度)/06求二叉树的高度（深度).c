#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct BiNode{
	char ch;

	struct BiNode *Lchild;
	struct BiNode *Rchild;


}BiNode;

int TreeHeigh(BiNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//���������ĸ߶�
	int Lheight = TreeHeigh(root->Lchild);
	//���������ĸ߶�
	int Rheight = TreeHeigh(root->Rchild);

	//�����������ĸ��߾�ȡ�Ǹ���Ȼ���ټ�1
	int height = Lheight > Rheight ? Lheight + 1 : Rheight + 1;

	return height;

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


	int heigh=TreeHeigh(&node1);
	printf("heigh=%d\n", heigh);

	system("pause");
	return EXIT_SUCCESS;
}

