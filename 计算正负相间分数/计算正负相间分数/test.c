#include <stdio.h>

int main()
{
	int i = -1;
	int j = 0;
	float sum = 0.0;
	for (j = 1; j <= 100; j++) {
		i *= -1;
		sum += i * 1.0 / j;
	}
	printf("%f\n", sum);
	getchar();
	return 0;
}