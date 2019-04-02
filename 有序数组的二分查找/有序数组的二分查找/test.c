#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_search(int arr[], int key, int left, int right) //参数为数组、查找元素、数组下标最小值、数组下标最大值 
{
	while (left <= right) {                        //当left已经超过right时，及数组元素已经被找到了
		int mid = left + (right - left) / 2;
		if (key < arr[mid]) {                  //判定所查找元素是否在左半边
			right = mid - 1;	       //若是，则缩小分区范围
		}
		else if (key > arr[mid]) {             //判定所查找元素是否在右半边
			left = mid + 1;		       //若是，则缩小分区范围
		}
		else {
			return mid;
		}
	}
	return -1;
}

int main()
{
	int key = 0;
	int sz = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int ret = 0;
	scanf("%d\n", &key);
	sz = sizeof(arr) / sizeof(arr[0]);
	ret = my_search(arr, key, 0, sz - 1);
	if (ret == -1) {
		printf("没找到\n");
	}
	else {
		printf("元素下标为：%d\n", ret);
	}
	system("pause");
	return 0;
}