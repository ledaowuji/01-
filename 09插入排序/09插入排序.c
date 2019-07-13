#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printfArr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}
//1.�����ݷ�Ϊ��������������
//2.�ѵ�һ��������������
//3.����������,
//4.�������������������бȽ�
//5.������������������������ʱ����
//6.��ʱ�����е���ҪС��arr[j]��������
//7.arr[j + 1] = tmp;//��Ϊforѭ���е�j--,����Ҫj+1

//����2 3 4 8 
void InsertSort(int arr[], int len)
{
	//����������,
	for (int i = 1; i < len; i++)
	{
		//�����ﵽ����ʾҪ����
		if (arr[i] < arr[i - 1])//�������������������бȽ�
		{
			int tmp = arr[i];//3

			//����������
			int j = i - 1;//i=3-1==j=2
			//��ʱ�����е���ҪС��arr[j]������һ��
			for (; j >= 0 && tmp<arr[j]; j--) // 3<2
			{

				arr[j + 1] = arr[j];//arr[1]=arr[0]
				
			}
			arr[j + 1] = tmp;//��Ϊforѭ���е�j--,����Ҫj+1

		}
	}
}

int main()
{

	int arr[] = { 4, 2, 8, 3 };
	int len = sizeof(arr) / sizeof(int);

	printfArr(arr, len);

	InsertSort(arr, len);

	printfArr(arr, len);

	system("pause");
	return EXIT_SUCCESS;
}

