#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
void test()
{
	int a = 10;//1个基础步骤
	for (int i = 0; i < 10; i++)
	{
		int b = i;//10个基础步骤
	}

	for (int i = 0; i < n; i++)
	{
		int c = i;//n个基础步骤
		//用大O表示法:O(n)
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//用大O表示法:O(n^2)//这是指数级
		}
	}

	int d = 10;

	//时间复杂度是:O(n^2),到了n级别，一般会忽略几步的基础步骤

	int b = 1;
	while (b<n)
	{
		b = b * 2;
	}

	//b每循环一次就乘2，当b>=n循环结束，假如循环有m次
	//那么b最终2^m,2^m>=n,得到m=log2n   时间复杂度0(logn),这是对数级


	//就时间复杂度来说，对数级优于指数级
}
*/

void test()
{
	double a = 0.11;
	for (int i = 0; i < 27; i++)
	{
		a = a * 2;
	}
	//8848  14763
	printf("%lf\n", a / 1000.0);
}
int main()
{
	test();
	

	system("pause");
	return EXIT_SUCCESS;
}

