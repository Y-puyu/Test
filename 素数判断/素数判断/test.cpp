#include<stdio.h>
#include<math.h>

int main()
{
	int i = 0;
	int count = 0;

	for (i = 101; i < 200; i += 2)            //ż���ڴ˲���Ҫ�����ж�
	{
		int j = 0;
		for (j = 2; j <= sqrt(i); j++)    //�㷨�Ż�
		{
			if (i%j == 0)
			{
				break;
			}
		}

		if (j > sqrt(i))
		{
			count++;             //������������
			printf("%d ", i);    //���δ�ӡ��������
		}
	}

	printf("\ncount = %d\n", count);     //��ӡ��������
	getchar();
	return 0;
}
