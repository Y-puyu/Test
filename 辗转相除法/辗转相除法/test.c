#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int a, b, r = 1;
	printf("������������������\n");
	scanf("%d %d", &a, &b);
	if (a < b) {
		r = a;
		a = b;
		b = r;
	}
	//շת���������Ϊr�ĳ�ʼֵ��Ϊ0������while������ٻ�ִ��һ��
	//ֱ������Ϊ�㣬����ѭ��
	while (r != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	//������Լ��
	printf("���Լ��Ϊ��%d\n", a);
	system("pause");
	return 0;
}