// SortStrings.cpp		C-字符串数组排序
#include "SortStrings.h"
#include <cstring>

void GetStrings0(char **&dest, const char *const source[], int n) // 11. 第一个参数为什么要传递二级指针的引用？
{
	dest = new char *[n];
	if (dest == NULL)
		return;
	dest[0] = new char[n * NUM];
	if (dest[0] == NULL)
	{
		delete[] dest; // 释放申请成功的堆空间单元
		dest = NULL;
		return;
	}
	for (int i = 1; i < n; i++) // 12. 请指出本循环的作用
		dest[i] = dest[i - 1] + NUM;
	for (int i = 0; i < n; i++)
	{
		strncpy(dest[i], source[i], NUM); // 13. 此处为什么要用strncpy函数？
		dest[i][NUM - 1] = '\0';		  // 14. 此语句的作用是什么？
	}
}

void GetStrings1(char **&dest, const char *const source[], int n)
{
	dest = new char *[n];
	if (dest == NULL)
		return;
	for (int i = 0; i < n; i++)
	{
		dest[i] = new char[NUM];
		strncpy(dest[i], source[i], NUM);
		dest[i][NUM - 1] = '\0';
	}
}

void GetStrings2(char **&dest, const char *const source[], int n)
{
	dest = new char *[n];
	if (dest == NULL)
		return;
	size_t len;
	for (int i = 0; i < n; i++)
	{
		len = strlen(source[i]);
		dest[i] = new char[len + 1];
		strcpy(dest[i], source[i]);
	}
}

void FreeStrings(char **&strs, int n, bool flag) // 15. 第一个参数为什么要传递二级指针的引用？
{
	if (strs != NULL)
	{
		if (flag)
		{
			char *temp = strs[0];
			for (int i = 1; i < n; i++) // 16. 这一段代码的作用是什么？
				if (strs[i] < temp)
					temp = strs[i];
			if (temp != NULL)
				delete[] temp;
		}
		else
		{
			for (int i = 0; i < n; i++)
				if (strs[i] != NULL)
					delete[] strs[i];
		}
		delete[] strs; // 17. 此处释放的数组是什么数组？
		strs = NULL;
	}
}

void BubbleA(char (*strs)[NUM], int n)
{
	char temp[NUM];
	for (int i = 1; i < n; i++) // 共进行 size-1 轮比较和交换
	{
		for (int j = 0; j < n - i; j++)
		{
			if (strcmp(strs[j], strs[j + 1]) > 0) // 相邻元素之间比较，必要时
			{
				strcpy(temp, strs[j]); // 交换指针strs[j] 与 strs[j+1]的内容
				strcpy(strs[j], strs[j + 1]);
				strcpy(strs[j + 1], temp);
			}
		}
	}
}

void BubbleA(char **strs, int n) // 重载BubbleA函数，以适应不同的实参
{
	char temp[NUM];
	for (int i = 1; i < n; i++) // 共进行 size-1 轮比较和交换
	{
		for (int j = 0; j < n - i; j++)
		{
			if (strcmp(strs[j], strs[j + 1]) > 0) // 相邻元素之间比较，必要时
			{
				strcpy(temp, strs[j]); // 交换指针strs[j] 与 strs[j+1]的内容
				strcpy(strs[j], strs[j + 1]);
				strcpy(strs[j + 1], temp);
			}
		}
	}
}

void BubbleB(char **strs, int n)
{
	char *temp;
	for (int i = 1; i < n; i++) // 共进行 size-1 轮比较和交换
	{
		for (int j = 0; j < n - i; j++)
		{
			if (strcmp(strs[j], strs[j + 1]) > 0) // 相邻元素之间比较，必要时
			{
				temp = strs[j]; // 交换指针strs[j] 与 strs[j+1]的指向
				strs[j] = strs[j + 1];
				strs[j + 1] = temp;
			}
		}
	}
}
