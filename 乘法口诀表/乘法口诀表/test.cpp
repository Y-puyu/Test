#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= 9; i++)          //寻找乘数与被乘数的关系
	{
		for (j = 1; j <= i; j++)      //9*9乘法表，每一行的个数等于i，而j每次都要从1开始，所以在此j的限制条件可以得到j<=i
		{
			printf("%d*%d=%2d ", i, j, i*j);   //打印每一行，注意 %2d 的使用让打印格式更加整齐
		}
		printf("\n");            //打印完毕一行时，要进行换行
	}
	getchar();
	return 0;
}
