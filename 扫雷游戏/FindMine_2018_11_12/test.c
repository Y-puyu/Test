#include "game.h"

void menu()
{
	printf("************************************\n");
	printf("********����    1. play    ����*********\n");
	printf("********����    0. exit    ����*********\n");
	printf("************************************\n");
}

void game()
{  //��������
	int x = 0;
	int y = 0;
	char mine[ROWS][COLS] = { 0 };      // '0'
	char show[ROWS][COLS] = { 0 };	  // '*'
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	SetMine(mine, ROW, COL);         //������
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	FindMine(mine, show, ROW, COL);            //ɨ��
	//Expand(mine, show, x, y);
	SpreadMine(mine[ROWS][COLS], show[ROWS][COLS], ROW, COL, x, y);
}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));     //ע�⣡
	do
	{
		menu();
		printf("��ѡ����:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ!\n");
		default:
			printf("ѡ���������������:>");
		}
	} while (input);
}

int main()
{
	test();      //������Ϸ
	return 0;
}