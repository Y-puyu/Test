#include<stdio.h>
void Init_arr(int arr[], int sz, int j)
{
	int i = 0;
	for (i = 0; i <= sz; i++)
	{
		arr[i] = j;
	}
}

void Empty_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i <= sz; i++)
	{
		arr[i] = 0;
	}
}
void Reverse_arr(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;

	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}

}
int main()
{
	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i <= sz; i++)
	{
		printf("%d", arr[i]);
	}
	Init_arr(arr, sz, 2);
	printf("\n");
	for (i = 0; i <= sz; i++)
	{
		printf("%d", arr[i]);
	}
	Empty_arr(arr, sz);
	printf("\n");
	for (i = 0; i <= sz; i++)
	{
		printf("%d", arr[i]);
	}
	Reverse_arr(arr, sz);
	printf("\n");
	for (i = 0; i <= sz; i++)
	{
		printf("%d", arr[i]);
	}
	getchar();
	return 0;
}
