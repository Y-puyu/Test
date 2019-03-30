#include<stdio.h>

// 1
int main()
{
	int i = 1;
	int j = 2;
	int tmp = 0;               //创建第三变量

	printf("%d %d\n", i, j);
	tmp = i;                   //通过第三变量进行交换
	i = j;
	j = tmp;
	printf("%d %d\n", i, j);
	return 0;
}

// 2
#include<stdio.h>

int main()
{
	int i = 18;
	int j = 23;               //未创建第三变量
	printf("%d %d\n", i, j);
	i = i + j;               //执行逻辑算法
	j = i - j;
	i = i - j;
	printf("%d %d\n", i, j);
	return 0;
}

// 3
#include<stdio.h>

int main()
{
	int i = 1;
	int j = 2;                 //未进行第三变量创建
	printf("%d %d\n", i, j);
	i = i ^ j;                   //使用异或操作符
	j = i ^ j;
	i = i ^ j;
	printf("%d %d\n", i, j);
	return 0;
}

