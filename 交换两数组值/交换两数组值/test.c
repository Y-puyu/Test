#include <stdio.h>

int main()
{
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int arr2[10] = { 11,22, 33, 44, 55, 66, 77, 88, 99, 10 };
	int arr3[10] = { 0 };
	int *p1 = arr1;
	int *p2 = arr2;
	int i = 0;
	for (i = 0; i < 10; i++) {
		arr3[i] = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = arr3[i];
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf("%2d ", arr2[i]);
	}
	printf("\n");
	getchar();
	return 0;
}