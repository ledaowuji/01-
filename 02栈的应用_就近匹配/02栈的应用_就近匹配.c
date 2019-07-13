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
	//初始化栈
	void *stack = Init_SeqStack();

	char *p = (char *)str;

	while (*p!='\0')
	{
		//如果是左括号，入栈
		if (IsLeft(*p))
		{
			Push_SeqStack(stack, p);

		}


		//如果是右括号，会有两种情况：1.栈不为空，匹配成功，把栈中的字符弹出
		//2.栈为空，这个右括号没有匹配的左括号
		if (IsRigth(*p))
		{
			if (Size_SeqStack(stack) > 0)//栈不为空
			{
				Pop_SeqStack(stack);
			}
			else
			{
				//打印出错信息
				printErr(str, "没有匹配的左括号", p);
			}
		}

		p++;
	}


	//扫描完成字符串，那么判断栈是否为空
	while (Size_SeqStack(stack) > 0)
	{
		char *pChar = Top_SeqStack(stack);
		//弹出栈顶元素
		Pop_SeqStack(stack);
		//打印出错信息
		printErr(str, "没有匹配的右括号", pChar);
	}


	system("pause");
	return EXIT_SUCCESS;
}

