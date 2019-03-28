#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int a, b, r = 1;
	printf("请输入两个正整数：\n");
	scanf("%d %d", &a, &b);
	if (a < b) {
		r = a;
		a = b;
		b = r;
	}
	//辗转相除法，因为r的初始值不为0，所以while语句至少会执行一次
	//直至余数为零，跳出循环
	while (r != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	//输出最大公约数
	printf("最大公约数为：%d\n", a);
	system("pause");
	return 0;
}