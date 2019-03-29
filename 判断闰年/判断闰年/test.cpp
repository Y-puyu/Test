#include<stdio.h>
int main()
{
	int year = 0;
	int count = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))    //判断条件
		{
			printf("%d ", year);
			count++;                                       //计数1
		}
	}
	if (year % 400 == 0)                                      //被400整除也是闰年
	{
		count++;                                           //
		printf("%d ", year);

	}
	printf("\n1000--2000年闰年总数：%d 年\n", count);

	getchar();
	return 0;
}
