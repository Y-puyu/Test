#include "game.h"

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");          //���Ե���
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SetMine(char arr[ROWS][COLS], int row, int col)   //ѡ����Ϸ�Ѷȣ��� 10*10 ����20*20  
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % 9 + 1;                 //rand����ʹ�ù���  
		int y = rand() % 9 + 1;

		if (arr[x][y] == '0');    //'0'������
		{
			arr[x][y] = '1';     //'1'����
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1]
		+ mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int win = 0;
	int stap = 0;
	while (win < row*col - EASY_COUNT)
	{
		printf("����������:>");
		scanf("%d %d", &x, &y);
		stap++;
		if (stap == 1 && mine[x][y] == '1')   //��֤��һ�²���ը��
		{
			mine[x][y] = '0';
			a = rand() % 9 + 1;
			b = rand() % 9 + 1;
			if (mine[a][b] == '0')
			{
				mine[a][b] = '1';
			}
		}
		if (x >= 1 && x <= row && y >= 1 && y <= col)   //����Ϸ�����ʱ
		{
			if (mine[x][y] == '1')
			{
				printf("�㱻ը���ˣ�\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				SpreadMine(mine[ROWS][COLS], show[ROWS][COLS], row, col, x, y);
				DisplayBoard(show, ROW, COL);
			}
			//DisplayBoard(show, ROW, COL);
		}
		else
		{
			printf("�������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ,���׳ɹ���\n");
	}
}

void SpreadMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	int c = 0;
	int d = 0;
	int count = GetMineCount(mine, x, y);
	if (GetMineCount(mine, x, y) == 0) {
		for (c = -1; c <= 1; c++)
		{
			for (d = -1; d <= 1; d++)
			{
				if (x + c >= 1 && x + c <= row && y + d >= 1
					&& y + d <= col && (c != 0 || d != 0))
				{
					if (mine[x + c][y + d] == '0');
					{
						if (GetMineCount(mine, x + c, y + d) == 0)
						{
							SpreadMine(mine[ROWS][COLS], show[ROWS][COLS], row, col, x + c, y + d);
						}
						else 
						{
							mine[x][y] = GetMineCount(mine, x, y) + '0';
						}
					}
				}
			}
		}
	}
	else
	{
		mine[x][y] = GetMineCount(mine, x, y) + '0';  // ֻ��չʾ3*3�Ľ��࣬������...
	}
}
