#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SeqStack.h"

int IsLeft(char ch)
{
	return ch == '(';
}
int IsRigth(char ch)
{
	return ch == ')';
}

void printErr(const char *str, const char *err, const char *p)
{
	printf("Error:%s\n", err);
	printf("%s\n", str);
	int len = p - str;
	for (int i = 0; i < len; i++)
	{
		printf(" ");
	}
	printf("A\n");
}

int main()
{

	const char *str = "5+5*(6)+9/3*1)-(1+3(";
	//��ʼ��ջ
	void *stack = Init_SeqStack();

	char *p = (char *)str;

	while (*p!='\0')
	{
		//����������ţ���ջ
		if (IsLeft(*p))
		{
			Push_SeqStack(stack, p);

		}


		//����������ţ��������������1.ջ��Ϊ�գ�ƥ��ɹ�����ջ�е��ַ�����
		//2.ջΪ�գ����������û��ƥ���������
		if (IsRigth(*p))
		{
			if (Size_SeqStack(stack) > 0)//ջ��Ϊ��
			{
				Pop_SeqStack(stack);
			}
			else
			{
				//��ӡ������Ϣ
				printErr(str, "û��ƥ���������", p);
			}
		}

		p++;
	}


	//ɨ������ַ�������ô�ж�ջ�Ƿ�Ϊ��
	while (Size_SeqStack(stack) > 0)
	{
		char *pChar = Top_SeqStack(stack);
		//����ջ��Ԫ��
		Pop_SeqStack(stack);
		//��ӡ������Ϣ
		printErr(str, "û��ƥ���������", pChar);
	}


	system("pause");
	return EXIT_SUCCESS;
}

