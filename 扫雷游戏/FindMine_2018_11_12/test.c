#include "game.h"

void menu()
{
	printf("************************************\n");
	printf("********¡¶¡¶    1. play    ¡·¡·*********\n");
	printf("********¡¶¡¶    0. exit    ¡·¡·*********\n");
	printf("************************************\n");
}

void game()
{  //²¼ÖÃÀ×Õó
	int x = 0;
	int y = 0;
	char mine[ROWS][COLS] = { 0 };      // '0'
	char show[ROWS][COLS] = { 0 };	  // '*'
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	SetMine(mine, ROW, COL);         //²¼ÖÃÀ×
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	FindMine(mine, show, ROW, COL);            //É¨À×
	//Expand(mine, show, x, y);
	SpreadMine(mine[ROWS][COLS], show[ROWS][COLS], ROW, COL, x, y);
}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));     //×¢Òâ£¡
	do
	{
		menu();
		printf("ÇëÑ¡ÔñÔò:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("ÍË³öÓÎÏ·!\n");
		default:
			printf("Ñ¡Ôñ´íÎó£¬ÇëÖØĞÂÊäÈë:>");
		}
	} while (input);
}

int main()
{
	test();      //²âÊÔÓÎÏ·
	return 0;
}