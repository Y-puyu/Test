#include<stdio.h>
int main()
{
	int year = 0;
	int count = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))    //�ж�����
		{
			printf("%d ", year);
			count++;                                       //����1
		}
	}
	if (year % 400 == 0)                                      //��400����Ҳ������
	{
		count++;                                           //
		printf("%d ", year);

	}
	printf("\n1000--2000������������%d ��\n", count);

	getchar();
	return 0;
}
