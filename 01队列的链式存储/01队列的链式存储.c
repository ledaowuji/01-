#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkQueue.h"

typedef struct Maker{
	char name[64];
	int age;
}Maker;

int main()
{
	Maker p1 = { "aaa1", 10 };
	Maker p2 = { "aaa2", 20 };
	Maker p3 = { "aaa3", 30 };
	Maker p4 = { "aaa4", 40 };

	//初始化队列
	void *queue = Init_SQueue();
	//入队
	Push_SQueue(queue, &p1);
	Push_SQueue(queue, &p2);
	Push_SQueue(queue, &p3);
	Push_SQueue(queue, &p4);

	//输出队头和队尾元素
	Maker *m1 = (Maker *)Front_SQueue(queue);
	Maker *m2 = (Maker*)Back_SQueue(queue);
	printf("m1->name:%s,m1->age:%d\n", m1->name, m1->age);
	printf("m2->name:%s,m2->age:%d\n", m2->name, m2->age);

	printf("-------------------\n");

	//输出队中所有的元素
	while (Size_SQueue(queue)>0)
	{
		//获取队头元素，因为队头元素才是输出
		Maker *m3 = (Maker *)Front_SQueue(queue);
		printf("name:%s,age:%d\n", m3->name, m3->age);

		//弹出队头元素
		Pop_SQueue(queue);

	}

	printf("size:%d\n", Size_SQueue(queue));

	Destroy_SQueue(queue);

	system("pause");
	return EXIT_SUCCESS;
}

