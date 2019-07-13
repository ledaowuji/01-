#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Linklist.h"

typedef struct QueueNode{
	struct LinkNode node;
}QueueNode;

//初始化
void *Init_SQueue();

//入队
void Push_SQueue(void *queue, void *data);
//出队
void Pop_SQueue(void *queue);

//获取队头元素
void *Front_SQueue(void *queue);

//获取队尾元素
void *Back_SQueue(void *queue);
//获取元素个数
int Size_SQueue(void *queue);
//销毁队列
void Destroy_SQueue(void *queue);
