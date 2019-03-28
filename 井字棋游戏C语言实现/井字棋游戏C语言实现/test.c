#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
#include <time.h>
#include <stdlib.h>

void menu()        //打印游戏菜单
{
	printf("************************************\n");
	printf("********《《    1. play    》》*********\n");
	printf("********《《    0. exit    》》*********\n");
	printf("************************************\n");
}

void game()
{
	char board[ROW][COL] = { 0 };       //以行列作为二维数组的参数值
	char ret = 0;                     //字符类型ret作为载体，便于二维数组中所传字符进行比对
	InitBoard(board, ROW, COL);       //定义一个ROW*COL的空棋盘
	DisplayBoard(board, ROW, COL);    //添加字符/特殊字符（宣扬个性），给棋盘加上边界

	while (1)                          //死循环
	{
		PlayerMove(board, ROW, COL);  //玩家走，定义函数
		ret = IsWin(board, ROW, COL); //判定胜负
		if (ret != ' ')                //如果此二维数组内元素未定义，即为空，在执行下面的电脑走
		{
			break;
		}
		DisplayBoard(board, ROW, COL);//玩家走后打印棋盘
		ComputerMove(board, ROW, COL);//电脑走（一定是空白可赋值，见25--28行）
		ret = IsWin(board, ROW, COL); //判定胜负
		if (ret != ' ')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);//电脑走后，打印棋盘
	}
	if (ret == '0')                    //
	{
		printf("电脑赢！\n");
	}
	else if (ret == 'X')
	{
		printf("玩家赢！\n");
	}
	else if (ret == 'Q')
	{
		printf("平局！\n");
	}
}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");            //选择开始游戏
		scanf("%d", &input);            //输入选项
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
		}
	} while (input);                    //循环结构，输错后继续，不准停！
}

int main()
{
	test();
	return 0;
}
