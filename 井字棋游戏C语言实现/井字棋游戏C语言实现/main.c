#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char arr[ROW][COL], int row, int col)   //函数不需返回值，需要二维数组、行数、列数作为函数参数
{
	int i = 0;                          //注：在从game.h拷贝函数名的时候需要去除 "；" 否则会提示错误：在文件范围内找到“{”(是否缺少函数头?)
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)        //遍历二维数组
		{
			arr[i][j] = ' ';        //初始化二维数组
		}
	}
}

void DisplayBoard(char arr[ROW][COL], int row, int col)   //函数参数与InitBoard相同，功能为打印有边界的棋盘，即给二维数组赋值
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)                                //遍历二维数组
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)                                 //边界处不需要棋盘边框      
				printf("|");
		}
		printf("\n");
		if (i < row - 1)                                     //边界处不需要棋盘边框
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void PlayerMove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("玩家走：\n");
	while (1)
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= 3) && ((y >= 1 && x <= 3)))                     //保证玩家输入坐标正确性
		{
			if (arr[x - 1][y - 1] == ' ')                             //玩家输入坐标与二维数组下标之间相差1
			{
				arr[x - 1][y - 1] = '*';                                 //如果为空，即未被占用，则赋值为字符X
				break;
			}
			else
			{
				printf("坐标已被占用\n");                            //被占用提示
			}
		}
		else                                                     //不在if语句限值之内即非法
		{
			printf("坐标非法\n");
		}
	}
}

void ComputerMove(char arr[ROW][COL], int row, int col)           //电脑落子
{
	int x = 0;
	int y = 0;
	printf("电脑走：>\n");
	while (1)
	{
		x = rand() % 3;                                              //得二维数组下标0  1  2，对3取模即可
		y = rand() % 3;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = 'o';                                     //若为空，对其赋值
			break;
		}
	}
	printf("电脑坐标：%d %d\n", x + 1, y + 1);
}

//当进程没有退出时 会产生错误  1>LINK : fatal error LNK1104: 无法打开文件“E:\A-bite\A\game\Debug\game.exe”

static int IsFull(char arr[ROW][COL], int row, int col)  //不为接口函数，不需要放入game.h，仅在此使用，无法进行test.c中调用
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)                                //遍历二维数组
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')                        //判断是否仍有空值
				return 0;                               //有空值返回0
		}
	}
	return 1;                                           //无空值返回1
}

char IsWin(char arr[ROW][COL], int row, int col)         //判断胜负
{
	int i = 0;
	for (i = 0; i < row; i++)                                //判断行  是否能胜利
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return arr[i][0];                           //若三子相同,且不能为空，返回元素内值
		}
	}

	for (i = 0; i < col; i++)                                //判断列  是否能胜利
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ')
		{
			return arr[1][i];
		}
	}

	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')   //判断正对角线能否胜利
	{
		return arr[1][1];
	}

	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')   //判断反对角线能否胜利
	{
		return arr[1][1];
	}

	if (IsFull(arr, row, col))                                              //判定平局
	{
		return 'Q';
	}
	return  ' ';                                     //继续
}
