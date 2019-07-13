#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//二叉树的节点
typedef struct BiNode{
	char ch;

	struct BiNode *Lchild;
	struct BiNode *Rchild;


}BiNode;

void caculateNums(BiNode *root, int *num)
{
	//递归退出条件
	if (root == NULL)
	{
		return;
	}

	//当节点的左孩子和右孩子都为空时，这个节点就是叶子节点
	if (root->Lchild == NULL && root->Rchild == NULL)
	{
		(*num)++;
	}
	//遍历左子树
	caculateNums(root->Lchild, num);
	//遍历右子树

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

	//建立二叉树
	node1.Lchild = &node2;
	node1.Rchild = &node6;

	node2.Rchild = &node3;

	node3.Lchild = &node4;
	node3.Rchild = &node5;

	node6.Rchild = &node7;

	node7.Lchild = &node8;

	//求叶子数
	int num = 0;
	caculateNums(&node1,&num);

	printf("num=%d\n", num);



	system("pause");
	return EXIT_SUCCESS;
}

