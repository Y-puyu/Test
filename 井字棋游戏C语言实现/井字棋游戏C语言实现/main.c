#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char arr[ROW][COL], int row, int col)   //�������践��ֵ����Ҫ��ά���顢������������Ϊ��������
{
	int i = 0;                          //ע���ڴ�game.h������������ʱ����Ҫȥ�� "��" �������ʾ�������ļ���Χ���ҵ���{��(�Ƿ�ȱ�ٺ���ͷ?)
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)        //������ά����
		{
			arr[i][j] = ' ';        //��ʼ����ά����
		}
	}
}

void DisplayBoard(char arr[ROW][COL], int row, int col)   //����������InitBoard��ͬ������Ϊ��ӡ�б߽�����̣�������ά���鸳ֵ
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)                                //������ά����
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)                                 //�߽紦����Ҫ���̱߿�      
				printf("|");
		}
		printf("\n");
		if (i < row - 1)                                     //�߽紦����Ҫ���̱߿�
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

	printf("����ߣ�\n");
	while (1)
	{
		printf("���������꣺");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= 3) && ((y >= 1 && x <= 3)))                     //��֤�������������ȷ��
		{
			if (arr[x - 1][y - 1] == ' ')                             //��������������ά�����±�֮�����1
			{
				arr[x - 1][y - 1] = '*';                                 //���Ϊ�գ���δ��ռ�ã���ֵΪ�ַ�X
				break;
			}
			else
			{
				printf("�����ѱ�ռ��\n");                            //��ռ����ʾ
			}
		}
		else                                                     //����if�����ֵ֮�ڼ��Ƿ�
		{
			printf("����Ƿ�\n");
		}
	}
}

void ComputerMove(char arr[ROW][COL], int row, int col)           //��������
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�>\n");
	while (1)
	{
		x = rand() % 3;                                              //�ö�ά�����±�0  1  2����3ȡģ����
		y = rand() % 3;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = 'o';                                     //��Ϊ�գ����丳ֵ
			break;
		}
	}
	printf("�������꣺%d %d\n", x + 1, y + 1);
}

//������û���˳�ʱ ���������  1>LINK : fatal error LNK1104: �޷����ļ���E:\A-bite\A\game\Debug\game.exe��

static int IsFull(char arr[ROW][COL], int row, int col)  //��Ϊ�ӿں���������Ҫ����game.h�����ڴ�ʹ�ã��޷�����test.c�е���
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)                                //������ά����
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')                        //�ж��Ƿ����п�ֵ
				return 0;                               //�п�ֵ����0
		}
	}
	return 1;                                           //�޿�ֵ����1
}

char IsWin(char arr[ROW][COL], int row, int col)         //�ж�ʤ��
{
	int i = 0;
	for (i = 0; i < row; i++)                                //�ж���  �Ƿ���ʤ��
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return arr[i][0];                           //��������ͬ,�Ҳ���Ϊ�գ�����Ԫ����ֵ
		}
	}

	for (i = 0; i < col; i++)                                //�ж���  �Ƿ���ʤ��
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ')
		{
			return arr[1][i];
		}
	}

	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')   //�ж����Խ����ܷ�ʤ��
	{
		return arr[1][1];
	}

	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')   //�жϷ��Խ����ܷ�ʤ��
	{
		return arr[1][1];
	}

	if (IsFull(arr, row, col))                                              //�ж�ƽ��
	{
		return 'Q';
	}
	return  ' ';                                     //����
}
