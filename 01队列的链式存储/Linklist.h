#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//让用户的数据包含这个结构体
typedef struct LinkNode{
	struct LinkNode *next;
}LinkNode;

//链表的结构体
typedef struct LList{
	LinkNode head;
	int size;
}LList;

//初始化函数
void *Init_ListList();

//指定位置插入
void InsertByPos_ListList(void *list, int pos, LinkNode *data);
//遍历
void Foreach_LinkNode(void *list,void(*foreach)(void *));
//根据位置获取值
void *Get_LinkNode(void *list, int pos);
//获取元素个数
int Size_LinkNode(void *list);
//根据位置删除
void RemoveByPos_LinkNode(void *list, int pos);
//销毁
void Destroy_LinkNode(void *list);


