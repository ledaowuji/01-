#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
void test()
{
	int a = 10;//1����������
	for (int i = 0; i < 10; i++)
	{
		int b = i;//10����������
	}

	for (int i = 0; i < n; i++)
	{
		int c = i;//n����������
		//�ô�O��ʾ��:O(n)
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//�ô�O��ʾ��:O(n^2)//����ָ����
		}
	}

	int d = 10;

	//ʱ�临�Ӷ���:O(n^2),����n����һ�����Լ����Ļ�������

	int b = 1;
	while (b<n)
	{
		b = b * 2;
	}

	//bÿѭ��һ�ξͳ�2����b>=nѭ������������ѭ����m��
	//��ôb����2^m,2^m>=n,�õ�m=log2n   ʱ�临�Ӷ�0(logn),���Ƕ�����


	//��ʱ�临�Ӷ���˵������������ָ����
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

