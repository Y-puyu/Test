#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_search(int arr[], int key, int left, int right) //����Ϊ���顢����Ԫ�ء������±���Сֵ�������±����ֵ 
{
	while (left <= right) {                        //��left�Ѿ�����rightʱ��������Ԫ���Ѿ����ҵ���
		int mid = left + (right - left) / 2;
		if (key < arr[mid]) {                  //�ж�������Ԫ���Ƿ�������
			right = mid - 1;	       //���ǣ�����С������Χ
		}
		else if (key > arr[mid]) {             //�ж�������Ԫ���Ƿ����Ұ��
			left = mid + 1;		       //���ǣ�����С������Χ
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
		printf("û�ҵ�\n");
	}
	else {
		printf("Ԫ���±�Ϊ��%d\n", ret);
	}
	system("pause");
	return 0;
}