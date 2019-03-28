#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
#include <time.h>
#include <stdlib.h>

void menu()        //��ӡ��Ϸ�˵�
{
	printf("************************************\n");
	printf("********����    1. play    ����*********\n");
	printf("********����    0. exit    ����*********\n");
	printf("************************************\n");
}

void game()
{
	char board[ROW][COL] = { 0 };       //��������Ϊ��ά����Ĳ���ֵ
	char ret = 0;                     //�ַ�����ret��Ϊ���壬���ڶ�ά�����������ַ����бȶ�
	InitBoard(board, ROW, COL);       //����һ��ROW*COL�Ŀ�����
	DisplayBoard(board, ROW, COL);    //����ַ�/�����ַ���������ԣ��������̼��ϱ߽�

	while (1)                          //��ѭ��
	{
		PlayerMove(board, ROW, COL);  //����ߣ����庯��
		ret = IsWin(board, ROW, COL); //�ж�ʤ��
		if (ret != ' ')                //����˶�ά������Ԫ��δ���壬��Ϊ�գ���ִ������ĵ�����
		{
			break;
		}
		DisplayBoard(board, ROW, COL);//����ߺ��ӡ����
		ComputerMove(board, ROW, COL);//�����ߣ�һ���ǿհ׿ɸ�ֵ����25--28�У�
		ret = IsWin(board, ROW, COL); //�ж�ʤ��
		if (ret != ' ')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);//�����ߺ󣬴�ӡ����
	}
	if (ret == '0')                    //
	{
		printf("����Ӯ��\n");
	}
	else if (ret == 'X')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ�֣�\n");
	}
}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");            //ѡ��ʼ��Ϸ
		scanf("%d", &input);            //����ѡ��
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
		}
	} while (input);                    //ѭ���ṹ�������������׼ͣ��
}

int main()
{
	test();
	return 0;
}
