#include<stdio.h>

// 1
int main()
{
	int i = 1;
	int j = 2;
	int tmp = 0;               //������������

	printf("%d %d\n", i, j);
	tmp = i;                   //ͨ�������������н���
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
	int j = 23;               //δ������������
	printf("%d %d\n", i, j);
	i = i + j;               //ִ���߼��㷨
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
	int j = 2;                 //δ���е�����������
	printf("%d %d\n", i, j);
	i = i ^ j;                   //ʹ����������
	j = i ^ j;
	i = i ^ j;
	printf("%d %d\n", i, j);
	return 0;
}

