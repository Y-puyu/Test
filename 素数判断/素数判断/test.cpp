#include<stdio.h>
#include<math.h>

int main()
{
	int i = 0;
	int count = 0;

	for (i = 101; i < 200; i += 2)            //偶数在此不需要进行判断
	{
		int j = 0;
		for (j = 2; j <= sqrt(i); j++)    //算法优化
		{
			if (i%j == 0)
			{
				break;
			}
		}

		if (j > sqrt(i))
		{
			count++;             //计算素数个数
			printf("%d ", i);    //依次打印各个素数
		}
	}

	printf("\ncount = %d\n", count);     //打印素数总数
	getchar();
	return 0;
}
