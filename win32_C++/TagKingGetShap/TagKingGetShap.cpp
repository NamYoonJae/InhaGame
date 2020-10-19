#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>

#define MapDataLine 800
#define StageMapDataLine 1000
#define InfiniteMapDataLine 1000

void mainMenu();
void Gotxy(int x, int y);
void cursor(int n);
void gameDescription();	// ���� ����
void gamemodeChoice();//���� ��� ����
void practiceGame();
void ResultPracticeGame();
void StageGame();
void ResultStageGame(int plusY);
void InfiniteGame();
void ResultInfiniteGame();

HANDLE hBuffer[2];
int nScreenIndex;
int playerX = 0;
int playerY = 0;
int hitCount = 0;
int shapCount = 0;
int GameSpeed = 0;

void init();
void writeBuffer(char(*MapData)[MapDataLine], int col, int row, int plusY);
int writeBufferStage(char(*MapData)[StageMapDataLine], int col, int row, int  plusY);
int writeBufferInfinite(char(*MapData)[InfiniteMapDataLine], int col, int row, int  plusY);
void Flapping();
void Release();
void StageRelease(int plusY);
void InfiniteRelease();

void ScoreHistory();
void ViewStageHistory();
void ViewInfiniteHistory();


void main()
{
	mainMenu();


}

void mainMenu()
{
	int n = 0;




	system("mode con cols=120 lines=30");//�ܼ� ũ�� ���� 
	printf("========================================================================================================================\n\n\n");
	printf("\t\t\t\t\t\t\t�±׿� Get #\n\n\n\n");

	printf("\t\t\t\t\t\t    [1]. ���� ����\n\n\n\n\
			\t\t\t    [2]. ���� �ϱ� & ��� ����\n\n\n\n\
			\t\t\t    [3]. ���ھ� ��� Ȯ��\n\n\n");
	printf("========================================================================================================================\n\n\n\n");
	printf("\t\t\t\t\t\t     �Է� >");
	printf("\n\n\n\n========================================================================================================================");
	Gotxy(23, 61);

	scanf("%d", &n);
	switch (n)
	{

		//���� ����
	case 1:
		system("cls");
		gameDescription();

		break;


		//���� ��� ����
	case 2:
		system("cls");
		gamemodeChoice();
		break;


		//���ھ� ���
	case 3:
		system("cls");
		ScoreHistory();
		break;


	default:
		system("cls");
		mainMenu();

		break;
	}



}

void gameDescription()
{
	int n = 0;
	printf("========================================================================================================================\n\n\n");

	printf("\t\t\t\t\t\t      ���� ����\n\n\n\n");
	printf("\t\t\t\t���� ���ؼ� �±� ��ư #�� ��� �±� �� �Ǳ� �����Դϴ�.\n\n");
	printf("\t\t\t\t\t���۹� :    ����Ű ��    /    ����Ű ��\n\n\n\n\n");
	printf("\t\t\t\t\t\t   [0. ���� �޴�]\n\n\n\n");
	printf("========================================================================================================================\n\n\n\n");
	printf("\t\t\t\t\t\t     �Է� >");
	printf("\n\n\n\n========================================================================================================================");

	Gotxy(23, 61);
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		system("cls");
		mainMenu();
		break;
	default:
		system("cls");
		gameDescription();

		break;
	}

}

void gamemodeChoice()
{
	int n = 0;
	printf("========================================================================================================================\n\n\n");
	printf("\t\t\t\t\t\t���� ��� ����\n\n\n\n");
	printf("\t\t[1]. ���� ��� : ���� �浹�ص� ���� ������ �浹Ƚ���� ī��Ʈ�մϴ�\n\n");
	printf("\t\t[2]. �������� ��� : ������������ ������ ���������� ������ ������ �ӵ��� ����մϴ�\n\n");
	printf("\t\t[3]. ���� ��� : 3���� ����� �ο��Ǹ� �浹�ø��� ����� -1�� �Ǹ� ����� 0�̵Ǹ� ������ ����˴ϴ�\n\n\n");
	printf("\t\t\t\t\t\t[0]. ���� �޴�\n\n\n\n");
	printf("========================================================================================================================\n\n\n\n");
	printf("\t\t\t\t\t\t�Է� >\n\n\n\n");
	printf("========================================================================================================================");
	Gotxy(23, 57);
	scanf("%d", &n);


	switch (n)
	{

	case 1:
		system("cls");
		practiceGame();

		break;

	case 2:
		system("cls");
		StageGame();
		break;

	case 3:
		system("cls");
		InfiniteGame();
		break;

	case 0:
		system("cls");
		mainMenu();
		break;

	default:
		system("cls");
		gamemodeChoice();
		break;

	}

}

void practiceGame()
{

	int i = 0;
	int j = 0;
	int plusY = 0;
	int col = 0;
	int row = 0;
	GameSpeed = 33;

	FILE *readMapData = NULL;
	char MapData[30][MapDataLine] = { 0 };
	char getMapData[MapDataLine] = { 0 };

	readMapData = fopen("GetSharpMapPractice.txt", "r+");

	while (fread(getMapData, sizeof(getMapData), 1, readMapData))
	{
		memcpy(MapData[i], getMapData, sizeof(getMapData) + 1);
		i++;

	};
	fclose(readMapData);

	init();

	col = sizeof(MapData[0]) / sizeof(char);
	row = sizeof(MapData) / sizeof(MapData[0]);
	while (plusY < MapDataLine)
	{
		writeBuffer(MapData, col, row, plusY);
		Flapping();
		plusY = plusY + 2;
	}
	Release();


	cursor(0);
}

void StageGame()
{

	int i = 0;
	int j = 0;
	int plusY = 0;
	int col = 0;
	int row = 0;
	int end = 0;
	GameSpeed = 33;

	FILE *readMapData = NULL;
	char MapData[30][StageMapDataLine] = { 0 };
	char getMapData[StageMapDataLine] = { 0 };

	readMapData = fopen("GetSharpMapStage.txt", "r+");

	while (fread(getMapData, sizeof(getMapData), 1, readMapData))
	{
		memcpy(MapData[i], getMapData, sizeof(getMapData) + 1);
		i++;

	};
	fclose(readMapData);

	init();
	col = sizeof(MapData[0]) / sizeof(char);
	row = sizeof(MapData) / sizeof(MapData[0]);

	while (plusY < StageMapDataLine)
	{
		end = writeBufferStage(MapData, col, row, plusY);
		if (end == 100)
		{
			break;
		}
		Flapping();
		plusY = plusY + 2;
		if (plusY == 300)
		{
			GameSpeed = 10;
		}
		else if (plusY == 600)
		{
			GameSpeed = 0.5;
		}

	}

	StageRelease(plusY);

	cursor(0);

}

void InfiniteGame()
{
	int i = 0;
	int j = 0;
	int plusY = 0;
	int col = 0;
	int row = 0;
	int end = 0;
	int countwhile = 0;
	GameSpeed = 33;

	FILE *readMapData = NULL;
	char MapData[30][InfiniteMapDataLine] = { 0 };
	char getMapData[InfiniteMapDataLine] = { 0 };

	readMapData = fopen("GetSharpMapInfinite.txt", "r+");

	while (fread(getMapData, sizeof(getMapData), 1, readMapData))
	{
		memcpy(MapData[i], getMapData, sizeof(getMapData) + 1);
		i++;

	};
	fclose(readMapData);

	init();
	col = sizeof(MapData[0]) / sizeof(char);
	row = sizeof(MapData) / sizeof(MapData[0]);

	while (1)
	{
		end = writeBufferInfinite(MapData, col, row, plusY);

		if (plusY == 1000)
		{
			plusY = 0;
		}

		if (end == 100)
		{
			break;
		}

		Flapping();
		plusY = plusY + 2;
		countwhile++;

		//�ӵ� ���� ����
		if (countwhile == 500)
		{
			GameSpeed = 20;
		}
		else if (countwhile == 1000)
		{
			GameSpeed = 15;
		}
	}
	InfiniteRelease();

	cursor(0);

}

void cursor(int n)
{
	{
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		ConsoleCursor.bVisible = n;
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	}
}

void init()
{
	CONSOLE_CURSOR_INFO cci;

	COORD size = { 120, 31 }; //����ũ���ε� �ֿܼ� �׸���ŭ ����� �����
	SMALL_RECT rect;
	rect.Left = 0;
	rect.Right = 120 - 1;
	rect.Top = 0;
	rect.Bottom = 31 - 1;

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);//���� ���� �Լ��̴�
	SetConsoleScreenBufferSize(hBuffer[0], size); //�ܼ� ������ ũ�� ���� //���� ũ����� ����ü�� �����ŭ
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);//�ܼ� â ũ�� ����

	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);//���� ���� �Լ��̴�
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hBuffer[0], &cci);
	SetConsoleCursorInfo(hBuffer[1], &cci);


}

void writeBuffer(char(*MapData)[MapDataLine], int col, int row, int plusY)
{
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	int key = 0;
	DWORD dw;
	COORD CursorPosition = { x, y };    //��ǥ ����
	SetConsoleCursorPosition(hBuffer[nScreenIndex], CursorPosition);


	//����
	char nullBuf = '\n';
	for (i = 0; i < 30; i++)
	{
		for (j = 0 + plusY; j < 120 + plusY; j++)
		{

			switch (MapData[i][j])
			{
			case 48://0�� ���
				WriteFile(hBuffer[nScreenIndex], " ", 2, &dw, NULL);
				break;

			case 49:	//1�� ���
				WriteFile(hBuffer[nScreenIndex], "��", 2, &dw, NULL);
				break;

			case 50:	//2�� ��� 
				WriteFile(hBuffer[nScreenIndex], "��", 2, &dw, NULL);
				playerX = i;
				playerY = j;

				break;
			case 51:	//3�� ���
				WriteFile(hBuffer[nScreenIndex], "#", 2, &dw, NULL);

			default:
				break;
			}
			//WriteFile(hBuffer[nScreenIndex], szBuf, sizeof(szBuf), &dw, NULL);

		}
		WriteFile(hBuffer[nScreenIndex], &nullBuf, sizeof(nullBuf), &dw, NULL);

	}

	if (kbhit())
	{
		key = getch();

		if (key == 224 || key == 0)
		{
			key = getch();
			switch (key)
			{
			case 72:	// �� ����Ű
				MapData[playerX][playerY] = 48;	//���� ��ǥ�� �������� �ٲٰ�
				playerX = playerX - 1;	//x��ǥ�� ���� �̵�
				MapData[playerX][playerY] = 50;	//�ش� ��ǥ�� 2�� ����
				break;

			case 80:	//�Ʒ� ����Ű
				MapData[playerX][playerY] = 48;
				playerX = playerX + 1;
				MapData[playerX][playerY] = 50;
				break;

			default:
				break;
			}
		}
		else if (key == 27)
		{
			//���� �����ϰ� �浹 Ƚ�� �����ֱ�
			CloseHandle(hBuffer[0]);
			CloseHandle(hBuffer[1]);
			ResultPracticeGame();
		}
	}

	MapData[playerX][playerY] = 48;

	if (MapData[playerX][playerY + 2] == 49) //�̵��� ��ǥ�� ������ ���
	{
		hitCount++;
		MapData[playerX][playerY + 2] = 50;
	}
	else if (MapData[playerX][playerY + 2] == 51)
	{
		shapCount++;
		MapData[playerX][playerY + 2] = 50;
	}

	MapData[playerX][playerY + 2] = 50;
}

int writeBufferStage(char(*MapData)[StageMapDataLine], int col, int row, int plusY)
{

	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	int key = 0;
	int end = 0;
	DWORD dw;
	COORD CursorPosition = { x, y };    //��ǥ ����
	SetConsoleCursorPosition(hBuffer[nScreenIndex], CursorPosition);

	char nullBuf = '\n';

	for (i = 0; i < 30; i++)
	{
		for (j = 0 + plusY; j < 120 + plusY; j++)
		{
			if (120 + plusY > StageMapDataLine)
			{
				CloseHandle(hBuffer[0]);
				CloseHandle(hBuffer[1]);
				ResultStageGame(plusY);
			}

			switch (MapData[i][j])
			{
			case 48://0�� ���
				WriteFile(hBuffer[nScreenIndex], " ", 2, &dw, NULL);
				break;

			case 49:	//1�� ���
				WriteFile(hBuffer[nScreenIndex], "��", 2, &dw, NULL);
				break;

			case 50:	//2�� ��� 
				WriteFile(hBuffer[nScreenIndex], "��", 2, &dw, NULL);
				playerX = i;
				playerY = j;

				break;
			case 51:	//3�� ���
				WriteFile(hBuffer[nScreenIndex], "#", 2, &dw, NULL);
				break;
			default:
				break;
			}

		}
		WriteFile(hBuffer[nScreenIndex], &nullBuf, sizeof(nullBuf), &dw, NULL);

	}

	if (kbhit())
	{
		key = getch();

		if (key == 224 || key == 0)
		{
			key = getch();
			switch (key)
			{
			case 72:	// �� ����Ű
				MapData[playerX][playerY] = 48;	//���� ��ǥ�� �������� �ٲٰ�
				playerX = playerX - 1;	//x��ǥ�� ���� �̵�
				MapData[playerX][playerY] = 50;	//�ش� ��ǥ�� 2�� ����
				break;

			case 80:	//�Ʒ� ����Ű
				MapData[playerX][playerY] = 48;
				playerX = playerX + 1;
				MapData[playerX][playerY] = 50;
				break;

			default:
				break;
			}
		}
		else if (key == 27)
		{
			//���� �����ϰ� �������� ��� �����ֱ�
			end = 100;
			return end;

		}
	}

	MapData[playerX][playerY] = 48;

	if (MapData[playerX][playerY + 2] == 49) //�̵��� ��ǥ�� ������ ���
	{
		end = 100;
		return end;
	}
	else if (MapData[playerX][playerY + 2] == 51)
	{
		shapCount++;
		MapData[playerX][playerY + 2] = 50;
	}

	MapData[playerX][playerY + 2] = 50;

}

int writeBufferInfinite(char(*MapData)[InfiniteMapDataLine], int col, int row, int  plusY)
{
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	int key = 0;
	int end = 0;
	DWORD dw;
	COORD CursorPosition = { x, y };    //��ǥ ����
	SetConsoleCursorPosition(hBuffer[nScreenIndex], CursorPosition);

	char nullBuf = '\n';

	for (i = 0; i < 30; i++)
	{
		for (j = 0 + plusY; j < 120 + plusY; j++)
		{

			switch (MapData[i][j])
			{
			case 48://0�� ���
				WriteFile(hBuffer[nScreenIndex], " ", 2, &dw, NULL);
				break;

			case 49:	//1�� ���
				WriteFile(hBuffer[nScreenIndex], "��", 2, &dw, NULL);
				break;

			case 50:	//2�� ��� 
				WriteFile(hBuffer[nScreenIndex], "��", 2, &dw, NULL);
				playerX = i;
				playerY = j;
				break;
			case 51:	//3�� ���
				WriteFile(hBuffer[nScreenIndex], "#", 2, &dw, NULL);
				break;

			default:
				break;
			}

		}
		WriteFile(hBuffer[nScreenIndex], &nullBuf, sizeof(nullBuf), &dw, NULL);

	}

	if (kbhit())
	{
		key = getch();

		if (key == 224 || key == 0)
		{
			key = getch();
			switch (key)
			{
			case 72:	// �� ����Ű
				MapData[playerX][playerY] = 48;	//���� ��ǥ�� �������� �ٲٰ�
				playerX = playerX - 1;	//x��ǥ�� ���� �̵�
				MapData[playerX][playerY] = 50;	//�ش� ��ǥ�� 2�� ����
				break;

			case 80:	//�Ʒ� ����Ű
				MapData[playerX][playerY] = 48;
				playerX = playerX + 1;
				MapData[playerX][playerY] = 50;
				break;

			default:
				break;
			}
		}
		else if (key == 27)
		{
			//���� �����ϰ� �������� ��� �����ֱ�
			end = 100;
			return end;

		}
	}

	MapData[playerX][playerY] = 48;

	if (MapData[playerX][playerY + 2] == 49) //�̵��� ��ǥ�� ������ ���
	{
		hitCount++;
		if (hitCount == 3)
		{
			end = 100;
			return end;
		}

	}
	else if (MapData[playerX][playerY + 2] == 51)
	{
		shapCount++;
		MapData[playerX][playerY + 2] = 50;
	}

	MapData[playerX][playerY + 2] = 50;

}


void Flapping()
{
	Sleep(GameSpeed);
	SetConsoleActiveScreenBuffer(hBuffer[nScreenIndex]);
	nScreenIndex = !nScreenIndex;
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(hBuffer[nScreenIndex], ' ', 120 * 31, Coor, &dw);
}

void Release()
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
	ResultPracticeGame();
}

void StageRelease(int plusY)
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
	system("cls");
	ResultStageGame(plusY);
}

void InfiniteRelease()
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
	system("cls");
	ResultInfiniteGame();
}


void ResultPracticeGame()
{
	int n = 0;
	printf("========================================================================================================================\n\n\n");
	printf("\t\t\t\t\t\t    �������� ���\n\n\n\n");
	printf("\t\t\t\t\t\t    �浹 Ƚ�� : %d \n\n\n", hitCount);
	printf("\t\t\t\t\t\t     # Score : %d \n\n\n\n\n\n", shapCount);
	printf("\t\t\t\t\t    [0] ���θ޴�\t [1]�ٽ��ϱ�\n\n");
	printf("========================================================================================================================\n\n\n\n");
	printf("\t\t\t\t\t\t�Է� >\n\n\n\n");
	printf("========================================================================================================================");
	Gotxy(23, 57);
	hitCount = 0;
	shapCount = 0;
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		system("cls");
		mainMenu();
		break;


	case 1:
		system("cls");
		practiceGame();
		break;

	default:
		system("cls");
		ResultPracticeGame();
		break;
	}
}

void ResultStageGame(int plusY)
{
	int n = 0;

	FILE *fStageGameHistory = NULL;
	fStageGameHistory = fopen("StageHistory.txt", "a+");
	if (fStageGameHistory == NULL)
	{
		printf("���� ���� ����");
		fclose(fStageGameHistory);
	}

	printf("========================================================================================================================\n\n\n");
	printf("\t\t\t\t\t\t    �������� ���� ���\n\n\n\n\n");
	if (0 < plusY && plusY < 300)
	{
		printf("\t\t\t\t\t\t\t�������� : 1\n\n");
		fprintf(fStageGameHistory, "%d\n", 1);
	}
	else if (300 < plusY && plusY <600)
	{
		printf("\t\t\t\t\t\t\t�������� : 2\n\n");
		fprintf(fStageGameHistory, "%d\n", 2);
	}
	else if (600 < plusY && plusY <MapDataLine)
	{
		printf("\t\t\t\t\t\t\t�������� : 3\n\n");
		fprintf(fStageGameHistory, "%d\n", 3);
	}
	fclose(fStageGameHistory);

	printf("\t\t\t\t\t\t\t# Score : %d\n\n\n\n\n", shapCount);
	printf("\t\t\t\t\t    [0] ���θ޴�\t [1]�ٽ��ϱ�\n\n\n");
	printf("========================================================================================================================\n\n\n\n");
	printf("\t\t\t\t\t\t   �Է� >\n\n\n\n");
	printf("========================================================================================================================");
	Gotxy(23, 61);
	shapCount = 0;
	scanf("%d", &n);
	switch (n)
	{
	case 0:
		system("cls");
		mainMenu();
		break;

	case 1:
		system("cls");
		StageGame();
		break;

	default:
		system("cls");
		ResultStageGame(plusY);
		break;
	}

}

void ResultInfiniteGame()
{
	int n = 0;

	FILE *fInfiniteGameHistory = NULL;
	fInfiniteGameHistory = fopen("InfiniteHistory.txt", "a+");
	if (fInfiniteGameHistory == NULL)
	{
		printf("���� ���� ����");
		fclose(fInfiniteGameHistory);
	}

	fprintf(fInfiniteGameHistory, "%d\n", shapCount);

	fclose(fInfiniteGameHistory);

	printf("========================================================================================================================\n\n\n");
	printf("\t\t\t\t\t\t    ���Ѹ�� ���� ���\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t# Score : %d\n\n\n\n\n\n", shapCount);
	printf("\t\t\t\t\t    [0] ���θ޴�\t [1]�ٽ��ϱ�\n\n\n\n");
	printf("========================================================================================================================\n\n\n\n");
	printf("\t\t\t\t\t\t   �Է� >\n\n\n\n");
	printf("========================================================================================================================");
	Gotxy(23, 61);
	hitCount = 0;
	shapCount = 0;

	scanf("%d", &n);
	switch (n)
	{
	case 0:
		system("cls");
		mainMenu();
		break;

	case 1:
		system("cls");
		InfiniteGame();
		break;

	default:
		system("cls");
		ResultInfiniteGame();
		break;
	}

}

void ScoreHistory()
{
	int n = 0;
	printf("========================================================================================================================\n\n\n");
	printf("\t\t\t\t\t\t      ���ھ� ��� Ȯ��\n\n\n\n\n");
	printf("\t\t\t\t\t\t[1]. �������� ��� ��� ����\n\n\n\n");
	printf("\t\t\t\t\t\t  [2]. ���Ѹ�� ��� ����\n\n\n\n");
	printf("\t\t\t\t\t\t       [0]. ���θ޴�\n\n");
	printf("========================================================================================================================\n\n\n\n");
	printf("\t\t\t\t\t\t     �Է� >\n\n\n\n");
	printf("========================================================================================================================");
	Gotxy(23, 61);
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		system("cls");
		ViewStageHistory();
		break;

	case 2:
		system("cls");
		ViewInfiniteHistory();
		break;

	case 0:
		system("cls");
		mainMenu();

	default:
		system("cls");
		ScoreHistory();
		break;
	}
}

void ViewStageHistory()
{
	FILE *fViewStageHistory = NULL;
	int nStage[100] = { 0 };
	int i = 0;
	int n = 0;
	fViewStageHistory = fopen("StageHistory.txt", "r");
	if (fViewStageHistory == NULL)
	{
		printf("���� ���� ����");
		fclose(fViewStageHistory);
	}

	for (i = 0; i < 100; i++)
	{
		fscanf(fViewStageHistory, "%d", &nStage[i]);
	}

	printf("========================================================================================================================\n\n\n");
	printf("\t\t\t\t\t\t  �������� ��� Ȯ��\n\n");
	for (i = 0; i < 100; i++)
	{
		if (nStage[i] == 0)
		{

		}
		else
		{
			printf("\t\t\t\t\t\t\t%d STAGE\n\n", nStage[i]);
		}
	}

	printf("\t\t\t\t\t    [0] ���θ޴�\t [1]�����޴�\n");

	Gotxy(19, 1);
	printf("========================================================================================================================\n\n\n\n");
	Gotxy(23, 54);
	printf("�Է� >\n\n\n\n");
	printf("========================================================================================================================");
	Gotxy(23, 61);
	scanf("%d", &n);

	switch (n)
	{
	case 0:
		system("cls");
		mainMenu();
		break;
	case 1:
		system("cls");
		ScoreHistory();
		break;
	default:
		system("cls");
		ViewStageHistory();
		break;
	}
	fclose(fViewStageHistory);
	cursor(0);
}

void ViewInfiniteHistory()
{
	FILE *fViewInfiniteHistory = NULL;
	int nShapScore[100] = { 0 };
	int nShapTotal = 0;
	int i = 0;
	int n = 0;
	fViewInfiniteHistory = fopen("InfiniteHistory.txt", "r");
	if (fViewInfiniteHistory == NULL)
	{
		printf("���� ���� ����");
		fclose(fViewInfiniteHistory);
	}

	for (i = 0; i < 100; i++)
	{
		fscanf(fViewInfiniteHistory, "%d", &nShapScore[i]);
	}

	printf("========================================================================================================================\n\n\n");
	printf("\t\t\t\t\t\t  ���Ѹ�� # ��� Ȯ��\n\n\n");
	for (i = 0; i < 100; i++)
	{
		if (nShapScore[i] == 0)
		{

		}
		else
		{
			nShapTotal += nShapScore[i];
			printf("\t\t\t\t\t\t      # Score : %d\n", nShapScore[i]);
		}
	}
	printf("\n\t\t\t\t\t\t    total  #  :  %d \n\n", nShapTotal);
	printf("\t\t\t\t\t    [0] ���θ޴�\t [1]�����޴�\n");

	Gotxy(19, 1);
	printf("========================================================================================================================\n\n\n\n");
	Gotxy(23, 54);
	printf("�Է� >\n\n\n\n");
	printf("========================================================================================================================");
	Gotxy(23, 61);
	scanf("%d", &n);

	switch (n)
	{
	case 0:
		system("cls");
		mainMenu();
		break;

	case 1:
		system("cls");
		ScoreHistory();
		break;

	default:
		system("cls");
		ViewInfiniteHistory();
		break;
	}
	fclose(fViewInfiniteHistory);
	cursor(0);
}


void Gotxy(int x, int y)
{
	COORD Pos = { y - 1,x - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}