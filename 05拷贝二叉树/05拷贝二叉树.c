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
void printfMaker(BiNode *root)
{
	if (root == NULL)
	{
		return;
	}

	//先序遍历（根左右）
	printf("%c ", root->ch);
	//再访问左子树
	printfMaker(root->Lchild);
	//再访问右子树
	printfMaker(root->Rchild);
}

BiNode *copyTree(BiNode *root)
{
	if (root == NULL)
	{
		return NULL;
	}

	//递归拷贝左子树
	BiNode *l=copyTree(root->Lchild);
	//递归拷贝右子树
	BiNode *r = copyTree(root->Rchild);
	//定义空间，装数据
	BiNode *newnode = (BiNode*)malloc(sizeof(BiNode));
	//拷贝
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

	//释放左子树
	freeSpace(root->Lchild);
	//释放右子树
	freeSpace(root->Rchild);
	//释放根节点
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

	//建立二叉树
	node1.Lchild = &node2;
	node1.Rchild = &node6;

	node2.Rchild = &node3;

	node3.Lchild = &node4;
	node3.Rchild = &node5;

	node6.Rchild = &node7;

	node7.Lchild = &node8;

	//拷贝二叉树
	BiNode *root = copyTree(&node1);
	//打印原来的树
	printfMaker(&node1);
	printf("\n-----------------\n");
	//打印拷贝的树
	printfMaker(root);

	//释放拷贝的二叉树空间
	freeSpace(root);



	system("pause");
	return EXIT_SUCCESS;
}

