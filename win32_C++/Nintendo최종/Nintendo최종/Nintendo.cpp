////////////////////////////////////////////Header
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include<MMSystem.h>
#pragma comment(lib,"Winmm.lib")
////////////////////////////////////////////Define
#define O 111
#define F 102
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define SQUARE 97
#define CIRCLE 100
#define TRIANGLE 119
#define XALPA 115
#define BACKSPACE 8
////////////////////////////////////////////All Function
int gotoxy(int, int);
int ClearBuffer();
int gameOn();
int mainscreen();
int GameSelScr();
int ShutDown();
int TapTapMain_1();
int TapTapMain_2();
int TapTapRealPlay();
int TapTapPractice();
int TapTapSurvival();
int TapTapType();
int TapTapRealPlayResult(int, int, int, int);
int TapTapPracticeResult(int, int, int, int);
int TapTapSurvivalResult(int, int, int, int, int, int, int);
///////////////////////////////////////////All Function_inu

HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
COLORREF a;
/////////////////////////////////////////// Create Function
int gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	return 0;
}

/////////////////////////////////////////// Main Function
int main()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	SetConsoleTitleA("NinTenDo");
	mainscreen();

	return 0;
}

int mainscreen()
{
	int Loop = 0;
	system("mode con: cols=95 lines=44");

	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("¦­                                                                                          ¦­\n");
	printf("¦­                                                                                          ¦­\n");
	printf("¦­                   ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯                     ¦­\n");
	printf("¦­                   ¦­                                              ¦­                     ¦­\n");
	printf("¦­                   ¦­                                              ¦­                     ¦­\n");
	printf("¦­                   ¦­                                              ¦­                     ¦­\n");
	printf("¦­                   ¦­                                              ¦­                     ¦­\n");
	printf("¦­     ¢Á  ¢Á  ¢Á    ¦­                                              ¦­     ¢Á  ¢Á  ¢Á      ¦­\n");
	printf("¦­                   ¦­                                              ¦­                     ¦­\n");
	printf("¦­     ¢Á  ¢Á  ¢Á    ¦­                                              ¦­     ¢Á  ¢Á  ¢Á      ¦­\n");
	printf("¦­                   ¦­                                              ¦­                     ¦­\n");
	printf("¦­                   ¦­                                              ¦­                     ¦­\n");
	printf("¦­                   ¦­                                              ¦­                     ¦­\n");
	printf("¦­                   ¦­                                              ¦­                     ¦­\n");
	printf("¦­                   ¦­                                              ¦­                     ¦­\n");
	printf("¦­                   ¦­                                              ¦­                     ¦­\n");
	printf("¦­                   ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°                     ¦­\n");
	printf("¦­                                                                                          ¦­\n");
	printf("¦­                                                                                          ¦­\n");
	printf("¦²¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦´\n");
	printf("¦­   ¡Û   ¦­                          ON : O   OFF : F                            ¦­ |||||| ¦­\n");
	printf("¦²¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦´\n");
	printf("¦­                                                                                          ¦­\n");
	printf("¦­                                                                                          ¦­\n");
	printf("¦­                   ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯                     ¦­\n");
	printf("¦­                   ¦­                                              ¦­                     ¦­\n");
	printf("¦­                   ¦­                                              ¦­        ¦®¦¬¦¯       ¦­\n");
	printf("¦­      ¦®¦¬¦¯       ¦­                                              ¦­        ¦­¡â¦­       ¦­\n");
	printf("¦­      ¦­¡è¦­       ¦­                                              ¦­        ¦±¦¬¦°       ¦­\n");
	printf("¦­      ¦­  ¦­       ¦­                                              ¦­  ¦®¦¬¦¯      ¦®¦¬¦¯ ¦­\n");
	printf("¦­¦®¦¬¦¬¦°  ¦±¦¬¦¬¦¯ ¦­                                              ¦­  ¦­¡à¦­      ¦­¡Û¦­ ¦­\n");
	printf("¦­¦­¡ç          ¡æ¦­ ¦­                                              ¦­  ¦±¦¬¦°      ¦±¦¬¦° ¦­\n");
	printf("¦­¦±¦¬¦¬¦¯  ¦®¦¬¦¬¦° ¦­                                              ¦­        ¦®¦¬¦¯       ¦­\n");
	printf("¦­      ¦­  ¦­       ¦­                                              ¦­        ¦­¥¹¦­       ¦­\n");
	printf("¦­      ¦­¡é¦­       ¦­                                              ¦­        ¦±¦¬¦°       ¦­\n");
	printf("¦­      ¦±¦¬¦°       ¦­                                              ¦­                     ¦­\n");
	printf("¦­                   ¦­                                              ¦­¡Ü start             ¦­\n");
	printf("¦­                   ¦­                                              ¦­¡Ü select            ¦­\n");
	printf("¦­                   ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°                     ¦­\n");
	printf("¦­                                                                                          ¦­\n");
	printf("¦­                                                                                          ¦­\n");
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");

	while (1)
	{
		if (GetAsyncKeyState(0x4F) && 0x0001 == TRUE)
		{
			sndPlaySoundA("music\\on.wav", SND_ASYNC | SND_NODEFAULT);
			SetConsoleTextAttribute(hC, 14);
			gotoxy(5, 21);
			printf("¡Ü");
			for (Loop = 0; Loop < 6; Loop++)
			{
				gotoxy(85 + Loop, 21);
				printf("|");
			}
			SetConsoleTextAttribute(hC, 7);
			gameOn();
		}
		else if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
			ShutDown();
	}

	return 0;
}

int gameOn()
{
	int Loop = 0;
	int Pass = 0;

	SetConsoleTextAttribute(hC, 240);
	for (Loop = 0; Loop < 35; Loop++)
	{
		if (Pass == 0 && Loop > 12)
		{
			Pass = 1;
			Loop = 22;
		}
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}
	Sleep(1000);

	gotoxy(0, 42);
	SetConsoleTextAttribute(hC, 240);
	for (Loop = 0; Loop < 5; Loop++)
	{
		switch (Loop)
		{
		case 0:
			gotoxy(41, 8);
			printf("È¯");
			Sleep(200);
			gotoxy(41, 8);
			printf("  ");
			gotoxy(41, 9);
			printf("È¯");
			Sleep(200);
			gotoxy(41, 9);
			printf("  ");
			gotoxy(41, 10);
			printf("È¯");
			break;
		case 1:
			gotoxy(43, 8);
			printf("¿µ");
			Sleep(200);
			gotoxy(43, 8);
			printf("  ");
			gotoxy(43, 9);
			printf("¿µ");
			Sleep(200);
			gotoxy(43, 9);
			printf("  ");
			gotoxy(43, 10);
			printf("¿µ");
			break;
		case 2:
			gotoxy(45, 8);
			printf("ÇÕ");
			Sleep(200);
			gotoxy(45, 8);
			printf("  ");
			gotoxy(45, 9);
			printf("ÇÕ");
			Sleep(200);
			gotoxy(45, 9);
			printf("  ");
			gotoxy(45, 10);
			printf("ÇÕ");
			break;
		case 3:
			gotoxy(47, 8);
			printf("´Ï");
			Sleep(200);
			gotoxy(47, 8);
			printf("  ");
			gotoxy(47, 9);
			printf("´Ï");
			Sleep(200);
			gotoxy(47, 9);
			printf("  ");
			gotoxy(47, 10);
			printf("´Ï");
			break;
		case 4:
			gotoxy(49, 8);
			printf("´Ù");
			Sleep(200);
			gotoxy(49, 8);
			printf("  ");
			gotoxy(49, 9);
			printf("´Ù");
			Sleep(200);
			gotoxy(49, 9);
			printf("  ");
			gotoxy(49, 10);
			printf("´Ù");
			break;
		}
	}

	Sleep(500);

	while (1)
	{
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			break;
		}
		else if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			ShutDown();
		}
		else
		{
			gotoxy(32, 32);
			printf("°è¼ÓÇÏ·Á¸é '¡Û'¸¦ ´­·¯ÁÖ¼¼¿ä");
			Sleep(500);
			gotoxy(32, 32);
			printf("                               ");
			Sleep(500);
		}
	}

	for (Loop = 0; Loop < 5; Loop++)
	{
		switch (Loop)
		{
		case 0:
			gotoxy(41, 10);
			printf("  ");
			gotoxy(41, 9);
			printf("È¯");
			Sleep(100);
			gotoxy(41, 9);
			printf("  ");
			gotoxy(41, 8);
			printf("È¯");
			Sleep(100);
			gotoxy(41, 8);
			printf("  ");
			break;
		case 1:
			gotoxy(43, 10);
			printf("  ");
			gotoxy(43, 9);
			printf("¿µ");
			Sleep(100);
			gotoxy(43, 9);
			printf("  ");
			gotoxy(43, 8);
			printf("¿µ");
			Sleep(100);
			gotoxy(43, 8);
			printf("  ");
			break;
		case 2:
			gotoxy(45, 10);
			printf("  ");
			gotoxy(45, 9);
			printf("ÇÕ");
			Sleep(100);
			gotoxy(45, 9);
			printf("  ");
			gotoxy(45, 8);
			printf("ÇÕ");
			Sleep(100);
			gotoxy(45, 8);
			printf("  ");
			break;
		case 3:
			gotoxy(47, 10);
			printf("  ");
			gotoxy(47, 9);
			printf("´Ï");
			Sleep(100);
			gotoxy(47, 9);
			printf("  ");
			gotoxy(47, 8);
			printf("´Ï");
			Sleep(100);
			gotoxy(47, 8);
			printf("  ");
			break;
		case 4:
			gotoxy(49, 10);
			printf("  ");
			gotoxy(49, 9);
			printf("´Ù");
			Sleep(100);
			gotoxy(49, 9);
			printf("  ");
			gotoxy(49, 8);
			printf("´Ù");
			Sleep(100);
			gotoxy(49, 8);
			printf("  ");
			break;
		}
	}

	Pass = 0;
	for (Loop = 0; Loop < 35; Loop++)
	{
		if (Pass == 0 && Loop > 12)
		{
			Pass = 1;
			Loop = 22;
		}
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}
	Sleep(500);
	GameSelScr();

	return 0;
}

int GameSelScr()
{	
	struct tm *t;
	time_t timer;
	int Loop = 0;
	int Hour = 0, Min = 0, Sec = 0;
	int SelGame = 0;
	int KeyBCH = 0;

	gotoxy(23, 4);
	printf("ÇöÀç ½Ã°¢ ");
	gotoxy(32, 10);
	printf("ÇÃ·¹ÀÌÇÏ½Ç °ÔÀÓÀ» °ñ¶óÁÖ¼¼¿ä");

	gotoxy(24, 27);
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	gotoxy(24, 28);
	printf("¦­TapTap!                                 ¦­\n");
	gotoxy(24, 29);
	printf("¦­                                        ¦­\n");
	gotoxy(24, 30);
	printf("¦­Á¦ÀÛ: ¼Õ¿µÁø  Á¦ÀÛÀÏ: 2016 - 1 - 17     ¦­");
	gotoxy(24, 31);
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");

	gotoxy(24, 33);
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	gotoxy(24, 34);
	printf("¦­?                                       ¦­\n");
	gotoxy(24, 35);
	printf("¦­                                        ¦­\n");
	gotoxy(24, 36);
	printf("¦­Á¦ÀÛ: ?      Á¦ÀÛÀÏ: ? - ? - ?          ¦­");
	gotoxy(24, 37);
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");

	SetConsoleTextAttribute(hC, 9);
	gotoxy(24, 27);
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
	gotoxy(24, 28);
	printf("¦­");
	gotoxy(66, 28);
	printf("¦­");
	gotoxy(24, 29);
	printf("¦­");
	gotoxy(66, 29);
	printf("¦­");
	gotoxy(24, 30);
	printf("¦­");
	gotoxy(66, 30);
	printf("¦­");
	gotoxy(24, 31);
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
	SetConsoleTextAttribute(hC, 240);

	while (1)
	{
		KeyBCH = 0;
		if (GetAsyncKeyState(0x57) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			SelGame--;
			if (SelGame < 0)
				SelGame++;
			gotoxy(10, 29);
			SetConsoleTextAttribute(hC, 14);
			printf("¡è");
			Sleep(50);
			gotoxy(10, 29);
			SetConsoleTextAttribute(hC, 7);
			printf("¡è");
		}
		else if (GetAsyncKeyState(0x53) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			SelGame++;
			if (SelGame > 1)
				SelGame--;
			gotoxy(10, 35);
			SetConsoleTextAttribute(hC, 14);
			printf("¡é");
			Sleep(50);
			gotoxy(10, 35);
			SetConsoleTextAttribute(hC, 7);
			printf("¡é");
		}
		else if (GetAsyncKeyState(0x41) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(4, 32);
			SetConsoleTextAttribute(hC, 14);
			printf("¡ç");
			Sleep(50);
			gotoxy(4, 32);
			SetConsoleTextAttribute(hC, 7);
			printf("¡ç");
		}
		else if (GetAsyncKeyState(0x44) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(16, 32);
			SetConsoleTextAttribute(hC, 14);
			printf("¡æ");
			Sleep(50);
			gotoxy(16, 32);
			SetConsoleTextAttribute(hC, 7);
			printf("¡æ");
		}
		else if (GetAsyncKeyState(VK_LEFT) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(75, 31);
			SetConsoleTextAttribute(hC, 14);
			printf("¡à");
			Sleep(50);
			gotoxy(75, 31);
			SetConsoleTextAttribute(hC, 7);
			printf("¡à");
		}
		else if (GetAsyncKeyState(VK_UP) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(81, 28);
			SetConsoleTextAttribute(hC, 14);
			printf("¡â");
			Sleep(50);
			gotoxy(81, 28);
			SetConsoleTextAttribute(hC, 7);
			printf("¡â");
		}
		else if (GetAsyncKeyState(VK_DOWN) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(81, 34);
			SetConsoleTextAttribute(hC, 14);
			printf("¥¹");
			Sleep(50);
			gotoxy(81, 34);
			SetConsoleTextAttribute(hC, 7);
			printf("¥¹");
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(87, 31);
			SetConsoleTextAttribute(hC, 14);
			printf("¡Û");
			Sleep(50);
			gotoxy(87, 31);
			SetConsoleTextAttribute(hC, 7);
			printf("¡Û");
			SetConsoleTextAttribute(hC, 240);
			switch (SelGame)
			{
			case 0:
				fflush(stdin);
				TapTapMain_1();
				break;
			case 1:
				fflush(stdin);
				break;
			}
		}
		else if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			ShutDown();
		}

		if (KeyBCH == 1)
		{
			switch (SelGame)
			{
			case 0:
				SetConsoleTextAttribute(hC, 240);
				gotoxy(24, 33);
				printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
				gotoxy(24, 34);
				printf("¦­");
				gotoxy(66, 34);
				printf("¦­");
				gotoxy(24, 35);
				printf("¦­");
				gotoxy(66, 35);
				printf("¦­");
				gotoxy(24, 36);
				printf("¦­");
				gotoxy(66, 36);
				printf("¦­");
				gotoxy(24, 37);
				printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
				SetConsoleTextAttribute(hC, 9);
				gotoxy(24, 27);
				printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
				gotoxy(24, 28);
				printf("¦­");
				gotoxy(66, 28);
				printf("¦­");
				gotoxy(24, 29);
				printf("¦­");
				gotoxy(66, 29);
				printf("¦­");
				gotoxy(24, 30);
				printf("¦­");
				gotoxy(66, 30);
				printf("¦­");
				gotoxy(24, 31);
				printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
				SetConsoleTextAttribute(hC, 240);
				break;
			case 1:
				SetConsoleTextAttribute(hC, 240);
				gotoxy(24, 27);
				printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
				gotoxy(24, 28);
				printf("¦­");
				gotoxy(66, 28);
				printf("¦­");
				gotoxy(24, 29);
				printf("¦­");
				gotoxy(66, 29);
				printf("¦­");
				gotoxy(24, 30);
				printf("¦­");
				gotoxy(66, 30);
				printf("¦­");
				gotoxy(24, 31);
				printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
				SetConsoleTextAttribute(hC, 9);
				gotoxy(24, 33);
				printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
				gotoxy(24, 34);
				printf("¦­");
				gotoxy(66, 34);
				printf("¦­");
				gotoxy(24, 35);
				printf("¦­");
				gotoxy(66, 35);
				printf("¦­");
				gotoxy(24, 36);
				printf("¦­");
				gotoxy(66, 36);
				printf("¦­");
				gotoxy(24, 37);
				printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
				SetConsoleTextAttribute(hC, 240);
				break;
			}
		}

		timer = time(NULL);
		t = localtime(&timer);
		Hour = t->tm_hour;
		Min = t->tm_min;
		Sec = t->tm_sec;
		gotoxy(33, 4);
		printf("%d:%d:%d ", Hour, Min, Sec);
	}

	return 0;
}

int TapTapMain_1()
{
	int Loop = 0;
	int Pass = 0;

	SetConsoleTextAttribute(hC, 240);
	for (Loop = 0; Loop < 35; Loop++)
	{
		if (Pass == 0 && Loop > 12)
		{
			Pass = 1;
			Loop = 22;
		}
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}

	Pass = 0;
	sndPlaySoundA("MUSIC\\taptapmain_1.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	gotoxy(23, 6);
	printf("  ¡á¡á¡á¡á¡á¡á¡á¡á   ¡á¡á¡á     ¡á¡á¡á¡á¡á¡á");
	gotoxy(23, 7);
	printf(" ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á");
	gotoxy(23, 8);
	printf("      ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á        ¡á¡á");
	gotoxy(23, 9);
	printf("     ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á        ¡á¡á");
	gotoxy(23, 10);
	printf("    ¡á¡á       ¡á¡á¡á¡á¡á¡á ¡á¡á¡á¡á¡á¡á¡á¡á");
	gotoxy(23, 11);
	printf("   ¡á¡á       ¡á¡á¡á¡á¡á¡á ¡á¡á¡á¡á¡á¡á¡á");
	gotoxy(23, 12);
	printf("  ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á");
	gotoxy(23, 13);
	printf(" ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á");
	gotoxy(23, 14);
	printf("¡á¡á       ¡á¡á    ¡á¡á ¡á¡á");

	Sleep(1000);

	for (Loop = 0; Loop < 12; Loop++)
	{
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}

	gotoxy(23, 28);
	printf("  ¡á¡á¡á¡á¡á¡á¡á¡á   ¡á¡á¡á     ¡á¡á¡á¡á¡á¡á");
	gotoxy(23, 29);
	printf(" ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á");
	gotoxy(23, 30);
	printf("      ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á        ¡á¡á");
	gotoxy(23, 31);
	printf("     ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á        ¡á¡á");
	gotoxy(23, 32);
	printf("    ¡á¡á       ¡á¡á¡á¡á¡á¡á ¡á¡á¡á¡á¡á¡á¡á¡á");
	gotoxy(23, 33);
	printf("   ¡á¡á       ¡á¡á¡á¡á¡á¡á ¡á¡á¡á¡á¡á¡á¡á");
	gotoxy(23, 34);
	printf("  ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á");
	gotoxy(23, 35);
	printf(" ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á");
	gotoxy(23, 36);
	printf("¡á¡á       ¡á¡á    ¡á¡á ¡á¡á");

	Sleep(1000);

	for (Loop = 22; Loop < 35; Loop++)
	{
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}

	gotoxy(23, 6);
	printf("  ¡á¡á¡á¡á¡á¡á¡á¡á   ¡á¡á¡á     ¡á¡á¡á¡á¡á¡á");
	gotoxy(23, 36);
	printf("¡á¡á       ¡á¡á    ¡á¡á ¡á¡á");
	Sleep(100);
	gotoxy(23, 7);
	printf(" ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á");
	gotoxy(23, 35);
	printf(" ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á");
	Sleep(100);
	gotoxy(23, 8);
	printf("      ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á        ¡á¡á");
	gotoxy(23, 34);
	printf("  ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á");
	Sleep(100);
	gotoxy(23, 9);
	printf("     ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á        ¡á¡á");
	gotoxy(23, 33);
	printf("   ¡á¡á       ¡á¡á¡á¡á¡á¡á ¡á¡á¡á¡á¡á¡á¡á");
	Sleep(100);
	gotoxy(23, 10);
	printf("    ¡á¡á       ¡á¡á¡á¡á¡á¡á ¡á¡á¡á¡á¡á¡á¡á¡á");
	gotoxy(23, 32);
	printf("    ¡á¡á       ¡á¡á¡á¡á¡á¡á ¡á¡á¡á¡á¡á¡á¡á¡á");
	Sleep(100);
	gotoxy(23, 11);
	printf("   ¡á¡á       ¡á¡á¡á¡á¡á¡á ¡á¡á¡á¡á¡á¡á¡á");
	gotoxy(23, 31);
	printf("     ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á        ¡á¡á");
	Sleep(100);
	gotoxy(23, 12);
	printf("  ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á");
	gotoxy(23, 30);
	printf("      ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á        ¡á¡á");
	Sleep(100);
	gotoxy(23, 13);
	printf(" ¡á¡á       ¡á¡á    ¡á¡á ¡á¡á");
	gotoxy(23, 29);
	printf(" ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á");
	Sleep(100);
	gotoxy(23, 14);
	printf("¡á¡á       ¡á¡á    ¡á¡á ¡á¡á");
	gotoxy(23, 28);
	printf("  ¡á¡á¡á¡á¡á¡á¡á¡á   ¡á¡á¡á     ¡á¡á¡á¡á¡á¡á");

	Sleep(1000);

	SetConsoleTextAttribute(hC, 240);

	for (Loop = 22; Loop < 35; Loop++)
	{
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}
	while (1)
	{
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			break;
		}
		else if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			ShutDown();
		}
		else
		{
			gotoxy(32, 32);
			printf("°è¼ÓÇÏ·Á¸é '¡Û'¸¦ ´­·¯ÁÖ¼¼¿ä");
			Sleep(500);
			gotoxy(32, 32);
			printf("                               ");
			Sleep(500);
		}
	}

	Pass = 0;

	for (Loop = 0; Loop < 35; Loop++)
	{
		if (Pass == 0 && Loop > 12)
		{
			Pass = 1;
			Loop = 22;
		}
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}
	
	TapTapMain_2();

	return 0;
}

int TapTapMain_2()
{
	int SelMode = 0;
	int Loop = 0;
	int Pass = 0;
	int KeyHit = 0;
	int LastMode = 0;

	sndPlaySoundA("music\\taptapmain_2.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	for (Loop = 0; Loop < 35; Loop++)
	{
		if (Pass == 0 && Loop > 12)
		{
			Pass = 1;
			Loop = 22;
		}
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}
	Pass = 0;
	
	gotoxy(40, 6);
	printf("¸ð µå ¼± ÅÃ");

	gotoxy(39, 8);
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¯");
	gotoxy(39, 9);
	printf("¦­¼­¹Ù  ÀÌ¹ú¦­");
	gotoxy(39, 10);
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦°");
	
	gotoxy(27, 11);
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¯         ¦®¦¬¦¬¦¬¦¬¦¬¦¯");
	gotoxy(27, 12);
	printf("¦­¿¬½À  ¸ðµå¦­         ¦­½ÇÀü  ¸ðµå¦­");
	gotoxy(27, 13);
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦°         ¦±¦¬¦¬¦¬¦¬¦¬¦°");

	SetConsoleTextAttribute(hC, 224);
	gotoxy(27, 11);
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¯");
	gotoxy(27, 12);
	printf("¦­");
	SetConsoleTextAttribute(hC, 240);
	gotoxy(29, 12);
	printf("¿¬½À  ¸ðµå");
	SetConsoleTextAttribute(hC, 224);
	gotoxy(39, 12);
	printf("¦­");
	gotoxy(27, 13);
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦°");
	SetConsoleTextAttribute(hC, 240);
	gotoxy(25, 28);
	printf("¡Ý ¿¬½À¸ðµå´Â Ãæµ¹À» ¹«½ÃÇÕ´Ï´Ù");
	gotoxy(25, 31);
	printf("¡Ý ¿¬½À¸ðµå´Â µî±Þ È®ÀÎÀÌ ºÒ°¡´ÉÇÕ´Ï´Ù");
	gotoxy(25, 34);
	printf("¡Ý Ãæµ¹À» ¹«½ÃÇÏÁö¸¸ Ãæµ¹ÇÑ È½¼ö´Â");
	gotoxy(28, 35);
	printf("°á°úÃ¢¿¡¼­ º¼ ¼ö ÀÖ½À´Ï´Ù");
	gotoxy(25, 37);
	printf("¡Ý ¸ÊÀÌ ¾î·Á¿ï ¶§ ÇÏ±â ÁÁÀº ¸ðµåÀÔ´Ï´Ù");

	while (1)
	{
		if (GetAsyncKeyState(0x41) & 0x0001 == TRUE)
		{
			SelMode--;
			if (SelMode < 0)
				SelMode++;
			KeyHit = 1;
		}

		if (GetAsyncKeyState(0x44) & 0x0001 == TRUE)
		{
			SelMode++;
			if (SelMode > 2)
				SelMode--;
			KeyHit = 1;
		}
		
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			for (Loop = 0; Loop < 35; Loop++)
			{
				if (Pass == 0 && Loop > 12)
				{
					Pass = 1;
					Loop = 22;
				}
				gotoxy(23, 4 + Loop);
				printf("                                              ");
			}
			switch (SelMode)
			{
			case 0:
				TapTapPractice();
				break;
			case 1:
				TapTapSurvival();
				break;
			case 2:
				TapTapRealPlay();
				break;
			}
		}

		if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			ShutDown();
		}

		if (KeyHit == 1 && LastMode != SelMode)
		{
			for (Loop = 22; Loop < 35; Loop++)
			{
				gotoxy(23, 4 + Loop);
				printf("                                              ");
			}
			switch (SelMode)
			{
			case 0:
				SetConsoleTextAttribute(hC, 240);
				gotoxy(39, 8);
				printf("¦®¦¬¦¬¦¬¦¬¦¬¦¯");
				gotoxy(39, 9);
				printf("¦­¼­¹Ù  ÀÌ¹ú¦­");
				gotoxy(39, 10);
				printf("¦±¦¬¦¬¦¬¦¬¦¬¦°");
				SetConsoleTextAttribute(hC, 224);
				gotoxy(27, 11);
				printf("¦®¦¬¦¬¦¬¦¬¦¬¦¯");
				gotoxy(27, 12);
				printf("¦­");
				SetConsoleTextAttribute(hC, 240);
				gotoxy(29, 12);
				printf("¿¬½À  ¸ðµå");
				SetConsoleTextAttribute(hC, 224);
				gotoxy(39, 12);
				printf("¦­");
				gotoxy(27, 13);
				printf("¦±¦¬¦¬¦¬¦¬¦¬¦°");
				SetConsoleTextAttribute(hC, 240);
				gotoxy(25, 28);
				printf("¡Ý ¿¬½À¸ðµå´Â Ãæµ¹À» ¹«½ÃÇÕ´Ï´Ù");
				gotoxy(25, 31);
				printf("¡Ý ¿¬½À¸ðµå´Â µî±Þ È®ÀÎÀÌ ºÒ°¡´ÉÇÕ´Ï´Ù");
				gotoxy(25, 34);
				printf("¡Ý Ãæµ¹À» ¹«½ÃÇÏÁö¸¸ Ãæµ¹ÇÑ È½¼ö´Â");
				gotoxy(28, 35);
				printf("°á°úÃ¢¿¡¼­ º¼ ¼ö ÀÖ½À´Ï´Ù");
				gotoxy(25, 37);
				printf("¡Ý ¸ÊÀÌ ¾î·Á¿ï ¶§ ÇÏ±â ÁÁÀº ¸ðµåÀÔ´Ï´Ù");
				break;
			case 1:
				SetConsoleTextAttribute(hC, 240);
				gotoxy(50, 11);
				printf("¦®¦¬¦¬¦¬¦¬¦¬¦¯");
				gotoxy(50, 12);
				printf("¦­½ÇÀü  ¸ðµå¦­");
				gotoxy(50, 13);
				printf("¦±¦¬¦¬¦¬¦¬¦¬¦°");
				SetConsoleTextAttribute(hC, 240);
				gotoxy(27, 11);
				printf("¦®¦¬¦¬¦¬¦¬¦¬¦¯");
				gotoxy(27, 12);
				printf("¦­¿¬½À  ¸ðµå¦­");
				gotoxy(27, 13);
				printf("¦±¦¬¦¬¦¬¦¬¦¬¦°");
				SetConsoleTextAttribute(hC, 224);
				gotoxy(39, 8);
				printf("¦®¦¬¦¬¦¬¦¬¦¬¦¯");
				gotoxy(39, 9);
				printf("¦­");
				SetConsoleTextAttribute(hC, 240);
				gotoxy(41, 9);
				printf("¼­¹Ù  ÀÌ¹ú");
				SetConsoleTextAttribute(hC, 224);
				gotoxy(51, 9);
				printf("¦­");
				gotoxy(39, 10);
				printf("¦±¦¬¦¬¦¬¦¬¦¬¦°");
				SetConsoleTextAttribute(hC, 240);
				gotoxy(25, 28);
				printf("¡Ý ¼­¹ÙÀÌ¹ú¸ðµå´Â ¸ñ¼ûÀÌ 2°³ ÁÖ¾îÁý´Ï´Ù");
				gotoxy(25, 31);
				printf("¡Ý ¼­¹ÙÀÌ¹ú¸ðµå´Â Ã¼Å©Æ÷ÀÎÆ®°¡ Á¸ÀçÇÕ´Ï´Ù");
				gotoxy(25, 34);
				printf("¡Ý »ý¸íÀÌ 1ÀÌ»óÀÏ¶§ Á×À» °æ¿ì Ã¼Å©Æ÷ÀÎÆ®¿¡¼­");
				gotoxy(25, 35);
				printf("   ºÎÈ°ÇÕ´Ï´Ù");
				gotoxy(25, 37);
				printf("¡Ý ¼­¹ÙÀÌ¹ú ¸ðµå´Â »ý¸í¾ÆÀÌÅÛÀÌ Á¸ÀçÇÕ´Ï´Ù");
				break;
			case 2:
				SetConsoleTextAttribute(hC, 240);
				gotoxy(39, 8);
				printf("¦®¦¬¦¬¦¬¦¬¦¬¦¯");
				gotoxy(39, 9);
				printf("¦­¼­¹Ù  ÀÌ¹ú¦­");
				gotoxy(39, 10);
				printf("¦±¦¬¦¬¦¬¦¬¦¬¦°");
				SetConsoleTextAttribute(hC, 224);
				gotoxy(50, 11);
				printf("¦®¦¬¦¬¦¬¦¬¦¬¦¯");
				gotoxy(50, 12);
				printf("¦­");
				SetConsoleTextAttribute(hC, 240);
				gotoxy(52, 12);
				printf("½ÇÀü  ¸ðµå");
				SetConsoleTextAttribute(hC, 224);
				gotoxy(62, 12);
				printf("¦­");
				gotoxy(50, 13);
				printf("¦±¦¬¦¬¦¬¦¬¦¬¦°");
				SetConsoleTextAttribute(hC, 240);
				gotoxy(25, 28);
				printf("¡Ý ½ÇÀü¸ðµå´Â Ãæµ¹½Ã ¸ñ¼ûÀÌ 1 ÁÙ¾îµì´Ï´Ù");
				gotoxy(25, 31);
				printf("¡Ý ¸ñ¼ûÀº ½ÃÀÛ ½Ã 3°³·Î ÁÖ¾îÁý´Ï´Ù");
				gotoxy(25, 34);
				printf("¡Ý ½ÇÀü ¸ðµå´Â µî±ÞÀÌ Ç¥½ÃµË´Ï´Ù");
				gotoxy(25, 37);
				printf("¡Ý ¸Ê¿¡ ÀÍ¼÷ÇØÁö¸é ÇÏ±â ÁÁÀº ¸ðµåÀÔ´Ï´Ù");
				break;
			}
			SetConsoleTextAttribute(hC, 240);
			LastMode = SelMode;
		}
		KeyHit = 0;
	}

	return 0;
}

int TapTapPractice()
{
	FILE *ReadMapData;
	time_t startTime = 0, endTime = 0;
	int Loop = 0, Loop1 = 0, Loop2 = 0, Loop3 = 0;
	int Direction = 0;
	int Pass = 0;
	int CntTotalData = 0;
	int CntLineData = 0;
	int CntCollision = 0;
	int MapSize = 512;
	int MapData[13][512] = { 0, };  ///////¸Ê
	int PlusY = 0;
	int PlayerArr1 = 0;
	int PlayerArr2 = 0;
	int GageData = 0;
	int GageX = 0;  ///////////////////////°ÔÀÌÁö
	int Stage = 1;  ///////////////////////°ÔÀÓ½ºÅ×ÀÌÁö
	int GameSK = 100; /////////////////////°ÔÀÓ¼Óµµ
	int TapTapScore = 0;
	int Remainder = 22; ///////////////////³ª¸ÓÁö
	int PlayTime = 0;
	int LastStage = 0;

	// Tattap.txt¿¡¼­ ¸Êµ¥ÀÌÅÍ¸¦ ÀÐ¾î¿È
	ReadMapData = fopen("GameMap\\Taptap.txt", "r+");

	for (Loop1 = 0; Loop1 < 13; Loop1++)
	{
		for (Loop2 = 0; Loop2 < MapSize; Loop2++)
		{
			fscanf(ReadMapData, "%d", &MapData[Loop1][Loop2]);
			CntTotalData++;
			if (MapData[Loop1][Loop2] == 2)
			{
				PlayerArr1 = Loop1;
				PlayerArr2 = Loop2;
			}
		}
	}
	fclose(ReadMapData);

	CntLineData = CntTotalData / 13;

	gotoxy(24, 26);
	printf("Á¡¼ö : ");
	printf("%d      ", TapTapScore);
	gotoxy(43, 26);
	printf("ÇöÀç ½ºÅ×ÀÌÁö : ");
	printf("%d Stage", Stage);
	gotoxy(24, 28);
	printf("½Ã°£ : 0");
	gotoxy(24, 30);
	printf("Ãæµ¹ : 0");
	gotoxy(24, 35);
	printf(" 1       2       3       4       5         F");
	gotoxy(23, 36);
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
	gotoxy(23, 37);
	printf("¦­                                          ¦­");
	gotoxy(23, 38);
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");

	// Ä«¿îÆ®´Ù¿î È¿°úÀ½ Ãâ·Â
	sndPlaySoundA("music\\count.wav", SND_ASYNC | SND_NODEFAULT);
	Sleep(200);
	for (Loop1 = 0; Loop1 < 7; Loop1++)
	{
		gotoxy(41, 10);
		switch (Loop1)
		{
		case 0:
			printf("R e a d y");
			break;
		case 1:
			printf("    5    ");
			break;
		case 2:
			printf("    4    ");
			break;
		case 3:
			printf("    3    ");
			break;
		case 4:
			printf("    2    ");
			break;
		case 5:
			printf("    1    ");
			break;
		case 6:
			printf("S t a r t");
			break;
		}
		Sleep(1000);
	}
	
	// ÀÎ°ÔÀÓ ³ë·¡ Ãâ·Â
	PlaySound(NULL, 0, 0);
	sndPlaySoundA("music\\tobu.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	startTime = clock();

	for (Loop1 = 0; Loop1 != CntTotalData / 13;)
	{
		// À§Ä¡ È®ÀÎ ÈÄ Áö³ª°£ ½ºÅ×ÀÌÁö ¡Ü Ç¥½Ã
		if (LastStage + 2 == Stage)
		{
			LastStage = Stage - 1;
			switch (LastStage)
			{
			case 1:
				gotoxy(25, 35);
				printf("¡Ü");
				break;
			case 2:
				gotoxy(33, 35);
				printf("¡Ü");
				break;
			case 3:
				gotoxy(41, 35);
				printf("¡Ü");
				break;
			case 4:
				gotoxy(49, 35);
				printf("¡Ü");
				break;
			}
		}
		// 41ÃÊÀÌ»ó Áö¼ÓµÉ °æ¿ì °ÔÀÓ Å¬¸®¾î·Î ÆÇ´Ü
		if (PlayTime == 41)
		{
			gotoxy(57, 35);
			printf("¡Ü");
		}
		// À§Ä¡°ª È®ÀÎ ÈÄ °¡·Î¸·´ë¿¡ Áö³ª°£ ¸¸Å­ ¡á Ç¥½Ã 
		if (Loop1 != 0 && Loop1 % 24 == 0)
		{
			SetConsoleTextAttribute(hC, 12);
			GageX += 2;
			gotoxy(23 + GageX, 37);
			printf("¡á");
		}

		if (Loop1 != 0 && Loop1 % (CntLineData / 5) == 0)
		{
			GameSK -= 18;
			Stage++;
			if (Stage > 5)
				Stage = 5;
		}

		SetConsoleTextAttribute(hC, 240);
		gotoxy(31, 26);
		printf("%d      ", TapTapScore);
		gotoxy(59, 26);
		printf("%d", Stage);
		gotoxy(31, 28);
		printf("%d", PlayTime);
		gotoxy(31, 30);
		printf("%d", CntCollision);

		fflush(stdin);
		SetConsoleTextAttribute(hC, 7);

		if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			ShutDown();
		}

		// ½ÇÀü¸ðµåÀÇ ±¸Á¶
		// Å°ÀÔ·Â -> ¹è¿­¿¡¼­ ÇÃ·¹ÀÌ¾î À§Ä¡ ÀÌµ¿ -> ¹è¿­¿¡¼­ ÇÃ·¹ÀÌ¾î À§Ä¡ È®ÀÎ ÈÄ Ãæµ¹ÀÎÁö ¾Æ´ÑÁö ÆÇ´Ü -> Ãæµ¹ÀÏ °æ¿ì °ÔÀÓ Á¾·á, Ãæµ¹ÀÌ ¾Æ´Ò °æ¿ì ÇÃ·¹ÀÌ¾î À§Ä¡ Ãâ·Â
		if (GetAsyncKeyState(0x57) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			PlayerArr1--;
			if (PlayerArr1 < 0)
				PlayerArr1--;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
			TapTapScore += 5;
		}
		else if (GetAsyncKeyState(0x53) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			PlayerArr1++;
			if (PlayerArr1 > 13)
				PlayerArr1++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
			TapTapScore += 5;
		}
		else if (GetAsyncKeyState(0x41) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(0x44) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_LEFT) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_UP) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}

		PlusY = 4;

		if (Loop1 + Remainder > CntTotalData / 13)
			Remainder--;
		SetConsoleTextAttribute(hC, 240);

		// ½Ã°£º°·Î ¸Ê Ãâ·Â »ö ¹Ù²Þ
		for (Loop2 = 0; Loop2 != 13; Loop2++)
		{
			gotoxy(24, PlusY);
			for (Loop3 = Loop1; Loop3 != Loop1 + Remainder; Loop3++)
			{
				if (PlayTime <17)
					SetConsoleTextAttribute(hC, 192);
				else if (PlayTime < 11)
					SetConsoleTextAttribute(hC, 0);
				else if (PlayTime < 13)
					SetConsoleTextAttribute(hC, 192);
				else if (PlayTime < 17)
					SetConsoleTextAttribute(hC, 0);
				else if (PlayTime < 19)
					SetConsoleTextAttribute(hC, 176);
				else if (PlayTime < 21)
					SetConsoleTextAttribute(hC, 0);
				else if (PlayTime < 22)
					SetConsoleTextAttribute(hC, 176);
				else if (PlayTime < 24)
					SetConsoleTextAttribute(hC, 160);
				else if (PlayTime < 26)
					SetConsoleTextAttribute(hC, 224);
				else if (PlayTime < 28)
					SetConsoleTextAttribute(hC, 192);
				else if (PlayTime < 30)
					SetConsoleTextAttribute(hC, 224);
				else if (PlayTime < 33)
					SetConsoleTextAttribute(hC, 176);
				else if (PlayTime < 35)
					SetConsoleTextAttribute(hC, 192);
				else if (PlayTime < 37)
					SetConsoleTextAttribute(hC, 176);
				else if (PlayTime < 39)
					SetConsoleTextAttribute(hC, 192);
				else if (PlayTime < 41)
					SetConsoleTextAttribute(hC, 176);
				else
					SetConsoleTextAttribute(hC, 0);

				switch (MapData[Loop2][Loop3])
				{
				case 0:
					SetConsoleTextAttribute(hC, 240);
					printf("  ");
					break;
				case 1:
					printf("  ");
					break;
				case 2:
					SetConsoleTextAttribute(hC, 144);
					printf("  ");
					break;
				case 3:
					SetConsoleTextAttribute(hC, 96);
					printf("  ");
					break;
				case 4:
					SetConsoleTextAttribute(hC, 14);
					printf("¢Ã");
					break;
				case 5:
					SetConsoleTextAttribute(hC, 224);
					printf("  ");
					break;
				}
			}
			SetConsoleTextAttribute(hC, 240);
			PlusY++;
		}
		SetConsoleTextAttribute(hC, 240);
		Sleep(GameSK);
		TapTapScore += 3;
		Loop1++;
		endTime = clock();
		PlayTime = (endTime - startTime) / (CLOCKS_PER_SEC);
	}
	gotoxy(57, 35);
	printf("¡Ü");
	Sleep(300);

	for (Loop = 0; Loop < 13; Loop++)
	{
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}
	gotoxy(37, 10);
	printf("All Stage Clear!");

	Sleep(1000);

	TapTapPracticeResult(Stage, TapTapScore, PlayTime, CntCollision);

	return 0;
}

int TapTapRealPlay()
{
	FILE *ReadMapData;
	time_t startTime = 0, endTime = 0;
	int Loop = 0, Loop1 = 0, Loop2 = 0, Loop3 = 0;
	int Direction = 0;
	int Pass = 0;
	int CntTotalData = 0;
	int CntLineData = 0;
	int MapSize = 512;
	int MapData[13][512] = { 0, };  ///////¸Ê
	int PlusY = 0;
	int PlayerArr1 = 0;
	int PlayerArr2 = 0;
	int GageData = 0;
	int GageX = 0;  ///////////////////////°ÔÀÌÁö
	int GameEnd = 0;  /////////////////////°ÔÀÓ ¿À¹ö È®ÀÎ
	int Stage = 1;  ///////////////////////°ÔÀÓ½ºÅ×ÀÌÁö
	int GameSK = 100; /////////////////////°ÔÀÓ¼Óµµ
	int TapTapScore = 0;
	int Remainder = 22; ///////////////////³ª¸ÓÁö
	int PlayTime = 0;
	int LastStage = 0;
	int Life = 3;

	ReadMapData = fopen("GameMap\\Taptap.txt", "r+");

	for (Loop1 = 0; Loop1 < 13; Loop1++)
	{
		for (Loop2 = 0; Loop2 < MapSize; Loop2++)
		{
			fscanf(ReadMapData, "%d", &MapData[Loop1][Loop2]);
			CntTotalData++;
			if (MapData[Loop1][Loop2] == 2)
			{
				PlayerArr1 = Loop1;
				PlayerArr2 = Loop2;
			}
		}
	}
	fclose(ReadMapData);

	CntLineData = CntTotalData / 13;

	gotoxy(24, 26);
	printf("ÇöÀç Á¡¼ö : ");
	printf("%d      ", TapTapScore);
	gotoxy(43, 26);
	printf("ÇöÀç ½ºÅ×ÀÌÁö : ");
	printf("%d Stage", Stage);
	gotoxy(24, 28);
	printf("½Ã°£ : 0");
	gotoxy(24, 30);
	printf("¸ñ¼û : 3");
	gotoxy(24, 35);
	printf(" 1       2       3       4       5         F");
	gotoxy(23, 36);
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
	gotoxy(23, 37);
	printf("¦­                                          ¦­");
	gotoxy(23, 38);
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");

	sndPlaySoundA("music\\count.wav", SND_ASYNC | SND_NODEFAULT);
	Sleep(200);
	for (Loop1 = 0; Loop1 < 7; Loop1++)
	{
		gotoxy(41, 10);
		switch (Loop1)
		{
		case 0:
			printf("R e a d y");
			break;
		case 1:
			printf("    5    ");
			break;
		case 2:
			printf("    4    ");
			break;
		case 3:
			printf("    3    ");
			break;
		case 4:
			printf("    2    ");
			break;
		case 5:
			printf("    1    ");
			break;
		case 6:
			printf("S t a r t");
			break;
		}
		Sleep(1000);
	}
	PlaySound(NULL, 0, 0);
	sndPlaySoundA("music\\tobu.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	startTime = clock();

	for (Loop1 = 0; Loop1 != CntTotalData / 13;)
	{
		if (GameEnd == 1)
			break;

		if (LastStage + 2 == Stage)
		{
			LastStage = Stage - 1;
			switch (LastStage)
			{
			case 1:
				gotoxy(25, 35);
				printf("¡Ü");
				break;
			case 2:
				gotoxy(33, 35);
				printf("¡Ü");
				break;
			case 3:
				gotoxy(41, 35);
				printf("¡Ü");
				break;
			case 4:
				gotoxy(49, 35);
				printf("¡Ü");
				break;
			}
		}
		
		if (Loop1 != 0 && Loop1 % 24 == 0)
		{
			SetConsoleTextAttribute(hC, 12);
			GageX += 2;
			gotoxy(23 + GageX, 37);
			printf("¡á");
		}

		if (Loop1 != 0 && Loop1 % (CntLineData / 5) == 0)
		{
			GameSK -= 18;
			Stage++;
			if (Stage > 5)
				Stage = 5;
		}

		SetConsoleTextAttribute(hC, 240);
		gotoxy(35, 26);
		printf("%d      ", TapTapScore);
		gotoxy(59, 26);
		printf("%d", Stage);
		gotoxy(31, 28);
		printf("%d", PlayTime);

		fflush(stdin);
		SetConsoleTextAttribute(hC, 240);

		if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			ShutDown();
		}

		if (GetAsyncKeyState(0x57) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			PlayerArr1--;
			if (PlayerArr1 < 0)
				PlayerArr1--;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				SetConsoleTextAttribute(hC, 240);
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
			TapTapScore += 5;
		}
		else if (GetAsyncKeyState(0x53) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			PlayerArr1++;
			if (PlayerArr1 > 13)
				PlayerArr1++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
			TapTapScore += 5;
		}
		else if (GetAsyncKeyState(0x41) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(0x44) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_LEFT) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_UP) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}

		PlusY = 4;

		if (Loop1 + Remainder > CntTotalData / 13)
			Remainder--;
		SetConsoleTextAttribute(hC, 240);

		for (Loop2 = 0; Loop2 != 13; Loop2++)
		{
			gotoxy(24, PlusY);
			for (Loop3 = Loop1; Loop3 != Loop1 + Remainder; Loop3++)
			{
				if (PlayTime <17)
					SetConsoleTextAttribute(hC, 192);
				else if (PlayTime < 11)
					SetConsoleTextAttribute(hC, 0);
				else if (PlayTime < 13)
					SetConsoleTextAttribute(hC, 192);
				else if (PlayTime < 17)
					SetConsoleTextAttribute(hC, 0);
				else if (PlayTime < 19)
					SetConsoleTextAttribute(hC, 176);
				else if (PlayTime < 21)
					SetConsoleTextAttribute(hC, 0);
				else if (PlayTime < 22)
					SetConsoleTextAttribute(hC, 176);
				else if (PlayTime < 24)
					SetConsoleTextAttribute(hC, 160);
				else if (PlayTime < 26)
					SetConsoleTextAttribute(hC, 224);
				else if (PlayTime < 28)
					SetConsoleTextAttribute(hC, 192);
				else if (PlayTime < 30)
					SetConsoleTextAttribute(hC, 224);
				else if (PlayTime < 33)
					SetConsoleTextAttribute(hC, 176);
				else if (PlayTime < 35)
					SetConsoleTextAttribute(hC, 192);
				else if (PlayTime < 37)
					SetConsoleTextAttribute(hC, 176);
				else if (PlayTime < 39)
					SetConsoleTextAttribute(hC, 192);
				else if (PlayTime < 41)
					SetConsoleTextAttribute(hC, 176);
				else
					SetConsoleTextAttribute(hC, 0);

				switch (MapData[Loop2][Loop3])
				{
				case 0:
					SetConsoleTextAttribute(hC, 240);
					printf("  ");
					break;
				case 1:
					printf("  ");
					break;
				case 2:
					SetConsoleTextAttribute(hC, 144);
					printf("  ");
					break;
				case 3:
					SetConsoleTextAttribute(hC, 96);
					printf("  ");
					break;
				case 4:
					SetConsoleTextAttribute(hC, 14);
					printf("¢Ã");
					break;
				case 5:
					SetConsoleTextAttribute(hC, 224);
					printf("  ");
					break;
				}
			}
			SetConsoleTextAttribute(hC, 240);
			PlusY++;
		}
		SetConsoleTextAttribute(hC, 240);
		Sleep(GameSK);
		TapTapScore += 3;
		Loop1++;
		endTime = clock();
		PlayTime = (endTime - startTime) / (CLOCKS_PER_SEC);
	}
	if (GameEnd == 0)
	{
		gotoxy(57, 35);
		printf("¡Ü");
	}

	Sleep(300);

	if (GameEnd == 1)
	{
		sndPlaySoundA("music\\gameover.wav", SND_ASYNC | SND_NODEFAULT );
		for (Loop = 0; Loop < 13; Loop++)
		{
			gotoxy(23, 4 + Loop);
			printf("                                              ");
		}
		gotoxy(42, 10);
		printf("Game Over");
	}
	else if (GameEnd == 0)
	{
		for (Loop = 0; Loop < 13; Loop++)
		{
			gotoxy(23, 4 + Loop);
			printf("                                              ");
		}
		gotoxy(37, 10);
		printf("All Stage Clear!");
	}

	Sleep(1000);

	TapTapRealPlayResult(Stage, TapTapScore, PlayTime, GameEnd);

	return 0;
}

int TapTapSurvival()
{
	FILE *ReadMapData;
	time_t startTime = 0, endTime = 0;
	int Loop = 0, Loop1 = 0, Loop2 = 0, Loop3 = 0, Loop4 = 0, Loop5 = 0, Loop6 = 0;
	int Direction = 0;
	int Pass = 0;
	int CntTotalData = 0;
	int CntLineData = 0;
	int MapSize = 512;
	int MapData[13][512] = { 0, };  ///////¸Ê
	int BackUpMapData[13][512] = { 0, };
	int PlusY = 0;
	int PlayerArr1 = 0;
	int PlayerArr2 = 0;
	int GageData = 0;
	int GageX = 0;  ///////////////////////°ÔÀÌÁö
	int GameEnd = 0;  /////////////////////°ÔÀÓ ¿À¹ö È®ÀÎ
	int TapTapScore = 0;
	int CP5Score = 0, CP6Score = 0, CP7Score = 0, CP8Score = 0, CP9Score = 0;
	int Remainder = 22; ///////////////////³ª¸ÓÁö
	float PlayTime = 0;
	int CheckPoint = 5;
	int LastCheckPoint = 4;
	int CP5_1 = 0, CP5_2 = 0, CP6_1 = 0, CP6_2 = 0, CP7_1 = 0, CP7_2 = 0, CP8_1 = 0, CP8_2 = 0, CP9_1 = 0, CP9_2 = 0;	// Ã¼Å©Æ÷ÀÎÆ® 1~5
	int Life = 2;	// »ý¸í

	ReadMapData = fopen("GameMap\\Taptap_2.txt", "r+");		// Taptap_2.txt¿¡¼­ ¸ÊÀ» ÀÐ¾î¿È

	for (Loop1 = 0; Loop1 < 13; Loop1++)
	{
		for (Loop2 = 0; Loop2 < MapSize; Loop2++)
		{
			fscanf(ReadMapData, "%d", &MapData[Loop1][Loop2]);
			CntTotalData++;
		}
	}
	fclose(ReadMapData);

	// ÀÐ¾î¿Â ¸Ê¿¡ ÀÖ´Â Ã¼Å©Æ÷ÀÎÆ®¸¦ ¹è¿­¿¡ ³Ö¾îÁÜ
	for (Loop1 = 0; Loop1 < 13; Loop1++)
	{
		for (Loop2 = 0; Loop2 < MapSize; Loop2++)
		{
			BackUpMapData[Loop1][Loop2] = MapData[Loop1][Loop2];
			switch (MapData[Loop1][Loop2])
			{
			case 5:
				CP5_1 = Loop1;
				CP5_2 = Loop2;
				break;
			case 6:
				CP6_1 = Loop1;
				CP6_2 = Loop2;
				break;
			case 7:
				CP7_1 = Loop1;
				CP7_2 = Loop2;
				break;
			case 8:
				CP8_1 = Loop1;
				CP8_2 = Loop2;
				break;
			case 9:
				CP9_1 = Loop1;
				CP9_2 = Loop2;
				break;
			}
		}
	}

	MapData[6][2] = 2;
	PlayerArr1 = 6;
	PlayerArr2 = 2;

	CntLineData = CntTotalData / 13;

	gotoxy(24, 26);
	printf("ÇöÀç Á¡¼ö : ");
	printf("%d      ", TapTapScore);
	gotoxy(24, 28);
	printf("¸ñ¼û : 2");
	gotoxy(24, 30);
	printf("Ã¼Å©Æ÷ÀÎÆ® 1 : ?");
	gotoxy(24, 32);
	printf("Ã¼Å©Æ÷ÀÎÆ® 2 : ?");
	gotoxy(24, 34);
	printf("Ã¼Å©Æ÷ÀÎÆ® 3 : ?");
	gotoxy(24, 36);
	printf("Ã¼Å©Æ÷ÀÎÆ® 4 : ?");
	gotoxy(24, 38);
	printf("Ã¼Å©Æ÷ÀÎÆ® 5 : ?");

	// ³ë·¡ Ãâ·Â
	PlaySound(NULL, 0, 0);
	sndPlaySoundA("music\\count.wav", SND_ASYNC | SND_NODEFAULT);
	Sleep(200);

	// Ä«¿îÆ®´Ù¿î
	for (Loop1 = 0; Loop1 < 7; Loop1++)
	{
		gotoxy(41, 10);
		switch (Loop1)
		{
		case 0:
			printf("R e a d y");
			break;
		case 1:
			printf("    5    ");
			break;
		case 2:
			printf("    4    ");
			break;
		case 3:
			printf("    3    ");
			break;
		case 4:
			printf("    2    ");
			break;
		case 5:
			printf("    1    ");
			break;
		case 6:
			printf("S t a r t");
			break;
		}
		Sleep(1000);
	}

	// ÀÎ°ÔÀÓ ³ë·¡ Ãâ·Â
	sndPlaySoundA("music\\Hello.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);

	// °ÔÀÓ½ÃÀÛ
	startTime = clock();
	for (Loop1 = 0; Loop1 != CntTotalData / 13;)
	{
		if (GameEnd == 1)
			break;

		SetConsoleTextAttribute(hC, 240);
		gotoxy(35, 26);
		printf("%d      ", TapTapScore);

		fflush(stdin);
		SetConsoleTextAttribute(hC, 240);

		if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			ShutDown();
		}

		// »ç¿ëÀÚ¿¡°Ô Å°¸¦ ÀÔ·Â¹Þ¾Æ À§Ä¡ °ª ¾÷µ¥ÀÌÆ®
		if (GetAsyncKeyState(0x57) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			PlayerArr1--;
			switch (MapData[PlayerArr1][PlayerArr2])
			{
			case 1:
				MapData[PlayerArr1][PlayerArr2] = 1;
				SetConsoleTextAttribute(hC, 240);
				Life--;
				switch (Life)
				{
				case 0:
					GameEnd = 1;
					gotoxy(31, 28);
					printf("%d  ", Life);
					break;
				default:
					switch (CheckPoint)
					{
					case 5:
						Loop1 = CP5_2 - 2;
						PlayerArr1 = CP5_1;
						PlayerArr2 = CP5_2;
						TapTapScore = CP5Score;
						break;
					case 6:
						Loop1 = CP6_2 - 2;
						PlayerArr1 = CP6_1;
						PlayerArr2 = CP6_2;
						TapTapScore = CP6Score;
						break;
					case 7:
						Loop1 = CP7_2 - 2;
						PlayerArr1 = CP7_1;
						PlayerArr2 = CP7_2;
						TapTapScore = CP7Score;
						break;
					case 8:
						Loop1 = CP8_2 - 2;
						PlayerArr1 = CP8_1;
						PlayerArr2 = CP8_2;
						TapTapScore = CP8Score;
						break;
					case 9:
						Loop1 = CP9_2 - 2;
						PlayerArr1 = CP9_1;
						PlayerArr2 = CP9_2;
						TapTapScore = CP9Score;
						break;
					}
					break;
				}
				gotoxy(35, 26);
				printf("%d      ", TapTapScore);
				gotoxy(31, 28);
				printf("%d  ", Life);
				if (GameEnd != 1)
				{
					for (Loop6 = 0; Loop6 < 4; Loop6++)
					{
						gotoxy(41, 10);
						switch (Loop6)
						{
						case 0:
							printf("    3    ");
							break;
						case 1:
							printf("    2    ");
							break;
						case 2:
							printf("    1    ");
							break;
						case 3:
							printf("S t a r t");
							break;
						}
						Sleep(1000);
					}
				}
				break;
			case 4:
				Life++;
				gotoxy(31, 28);
				printf("%d  ", Life);
				break;
			case 5:
				CheckPoint = 5;
				if (LastCheckPoint != CheckPoint)
				{
					CP5Score = TapTapScore;
					gotoxy(39, 30);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 6:
				CheckPoint = 6;
				if (LastCheckPoint != CheckPoint)
				{
					CP6Score = TapTapScore;
					gotoxy(39, 32);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 7:
				CheckPoint = 7;
				if (LastCheckPoint != CheckPoint)
				{
					CP7Score = TapTapScore;
					gotoxy(39, 34);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 8:
				CheckPoint = 8;
				if (LastCheckPoint != CheckPoint)
				{
					CP8Score = TapTapScore;
					gotoxy(39, 36);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 9:
				CheckPoint = 9;
				if (LastCheckPoint != CheckPoint)
				{
					CP9Score = TapTapScore;
					gotoxy(39, 38);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			default:
				break;
			}
			MapData[PlayerArr1][PlayerArr2] = 2;
			TapTapScore += 5;
		}
		else if (GetAsyncKeyState(0x53) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			PlayerArr1++;
			switch (MapData[PlayerArr1][PlayerArr2])
			{
			case 1:
				MapData[PlayerArr1][PlayerArr2] = 1;
				Life--;
				switch (Life)
				{
				case 0:
					GameEnd = 1;
					gotoxy(31, 28);
					printf("%d  ", Life);
					break;
				default:
					switch (CheckPoint)
					{
					case 5:
						Loop1 = CP5_2 - 2;
						PlayerArr1 = CP5_1;
						PlayerArr2 = CP5_2;
						TapTapScore = CP5Score;
						break;
					case 6:
						Loop1 = CP6_2 - 2;
						PlayerArr1 = CP6_1;
						PlayerArr2 = CP6_2;
						TapTapScore = CP6Score;
						break;
					case 7:
						Loop1 = CP7_2 - 2;
						PlayerArr1 = CP7_1;
						PlayerArr2 = CP7_2;
						TapTapScore = CP7Score;
						break;
					case 8:
						Loop1 = CP8_2 - 2;
						PlayerArr1 = CP8_1;
						PlayerArr2 = CP8_2;
						TapTapScore = CP8Score;
						break;
					case 9:
						Loop1 = CP9_2 - 2;
						PlayerArr1 = CP9_1;
						PlayerArr2 = CP9_2;
						TapTapScore = CP9Score;
						break;
					}
					break;
				}
				gotoxy(35, 26);
				printf("%d      ", TapTapScore);
				gotoxy(31, 28);
				printf("%d  ", Life);
				if (GameEnd != 1)
				{
					for (Loop6 = 0; Loop6 < 4; Loop6++)
					{
						gotoxy(41, 10);
						switch (Loop6)
						{
						case 0:
							printf("    3    ");
							break;
						case 1:
							printf("    2    ");
							break;
						case 2:
							printf("    1    ");
							break;
						case 3:
							printf("S t a r t");
							break;
						}
						Sleep(1000);
					}
				}
				break;
			case 4:
				Life++;
				gotoxy(31, 28);
				printf("%d  ", Life);
				break;
			case 5:
				CheckPoint = 5;
				if (LastCheckPoint != CheckPoint)
				{
					CP5Score = TapTapScore;
					gotoxy(39, 30);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 6:
				CheckPoint = 6;
				if (LastCheckPoint != CheckPoint)
				{
					CP6Score = TapTapScore;
					gotoxy(39, 32);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 7:
				CheckPoint = 7;
				if (LastCheckPoint != CheckPoint)
				{
					CP7Score = TapTapScore;
					gotoxy(39, 34);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 8:
				CheckPoint = 8;
				if (LastCheckPoint != CheckPoint)
				{
					CP8Score = TapTapScore;
					gotoxy(39, 36);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 9:
				CheckPoint = 9;
				if (LastCheckPoint != CheckPoint)
				{
					CP9Score = TapTapScore;
					gotoxy(39, 38);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			default:
				break;
			}
			MapData[PlayerArr1][PlayerArr2] = 2;
			TapTapScore += 5;
		}
		else
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			switch (MapData[PlayerArr1][PlayerArr2])
			{
			case 1:
				MapData[PlayerArr1][PlayerArr2] = 1;
				Life--;
				gotoxy(31, 28);
				printf("%d  ", Life);
				switch (Life)
				{
				case 0:
					GameEnd = 1;
					gotoxy(31, 28);
					printf("%d  ", Life);
					break;
				default:
					switch (CheckPoint)
					{
					case 5:
						Loop1 = CP5_2 - 2;
						PlayerArr1 = CP5_1;
						PlayerArr2 = CP5_2;
						TapTapScore = CP5Score;
						break;
					case 6:
						Loop1 = CP6_2 - 2;
						PlayerArr1 = CP6_1;
						PlayerArr2 = CP6_2;
						TapTapScore = CP6Score;
						break;
					case 7:
						Loop1 = CP7_2 - 2;
						PlayerArr1 = CP7_1;
						PlayerArr2 = CP7_2;
						TapTapScore = CP7Score;
						break;
					case 8:
						Loop1 = CP8_2 - 2;
						PlayerArr1 = CP8_1;
						PlayerArr2 = CP8_2;
						TapTapScore = CP8Score;
						break;
					case 9:
						Loop1 = CP9_2 - 2;
						PlayerArr1 = CP9_1;
						PlayerArr2 = CP9_2;
						TapTapScore = CP9Score;
						break;
					}
					break;
				}
				gotoxy(35, 26);
				printf("%d      ", TapTapScore);
				gotoxy(31, 28);
				printf("%d  ", Life);
				if (GameEnd != 1)
				{
					for (Loop6 = 0; Loop6 < 4; Loop6++)
					{
						gotoxy(41, 10);
						switch (Loop6)
						{
						case 0:
							printf("    3    ");
							break;
						case 1:
							printf("    2    ");
							break;
						case 2:
							printf("    1    ");
							break;
						case 3:
							printf("S t a r t");
							break;
						}
						Sleep(1000);
					}
				}
				break;
			case 4:
				Life++;
				gotoxy(31, 28);
				printf("%d  ", Life);
				break;
			case 5:
				CheckPoint = 5;
				if (LastCheckPoint != CheckPoint)
				{
					CP5Score = TapTapScore;
					gotoxy(39, 30);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 6:
				CheckPoint = 6;
				if (LastCheckPoint != CheckPoint)
				{
					CP6Score = TapTapScore;
					gotoxy(39, 32);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 7:
				CheckPoint = 7;
				if (LastCheckPoint != CheckPoint)
				{
					CP7Score = TapTapScore;
					gotoxy(39, 34);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 8:
				CheckPoint = 8;
				if (LastCheckPoint != CheckPoint)
				{
					CP8Score = TapTapScore;
					gotoxy(39, 36);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 9:
				CheckPoint = 9;
				if (LastCheckPoint != CheckPoint)
				{
					CP9Score = TapTapScore;
					gotoxy(39, 38);
					printf("%d", TapTapScore);
					LastCheckPoint = CheckPoint;
				}
				break;
			default:
				break;
			}
			MapData[PlayerArr1][PlayerArr2] = 2;
		}

		PlusY = 4;

		if (Loop1 + Remainder > CntTotalData / 13)
			Remainder--;
		SetConsoleTextAttribute(hC, 240);

		endTime = clock();
		PlayTime = endTime - startTime;

		// ¸ÊÀ» Ãâ·Â
		for (Loop2 = 0; Loop2 != 13; Loop2++)
		{
			gotoxy(24, PlusY);
			for (Loop3 = Loop1; Loop3 != Loop1 + Remainder; Loop3++)
			{
				switch (MapData[Loop2][Loop3])
				{
				case 0:                                       //±æ
					SetConsoleTextAttribute(hC, 240);
					printf("  ");
					break;
				case 1:                                       //º®
					SetConsoleTextAttribute(hC, 64);
					printf("  ");
					break;
				case 2:                                       //ÇÃ·¹ÀÌ¾î
					SetConsoleTextAttribute(hC, 144);
					printf("  ");
					break;
				case 3:                                       //µðÀÚÀÎ
					SetConsoleTextAttribute(hC, 96);
					printf("  ");
					break;
				case 4:                                       //»ý¸í¾ÆÀÌÅÛ
					SetConsoleTextAttribute(hC, 192);
					printf("  ");
					break;
				case 5:                                       //Ã¼Å©Æ÷ÀÎÆ®1
					SetConsoleTextAttribute(hC, 224);
					printf("  ");
					break;
				case 6:                                       //Ã¼Å©Æ÷ÀÎÆ®2
					SetConsoleTextAttribute(hC, 224);
					printf("  ");
					break;
				case 7:                                       //Ã¼Å©Æ÷ÀÎÆ®3
					SetConsoleTextAttribute(hC, 224);
					printf("  ");
					break;
				case 8:                                       //Ã¼Å©Æ÷ÀÎÆ®4
					SetConsoleTextAttribute(hC, 224);
					printf("  ");
					break;
				case 9:                                       //Ã¼Å©Æ÷ÀÎÆ®5
					SetConsoleTextAttribute(hC, 224);
					printf("  ");
					break;
				}
			}
			PlusY++;
		}
		Sleep(100);
		TapTapScore += 3;
		Loop1++;
		SetConsoleTextAttribute(hC, 240);
	}

	Sleep(300);

	if (GameEnd == 1)
	{
		sndPlaySoundA("music\\gameover.wav", SND_ASYNC | SND_NODEFAULT);
		for (Loop = 0; Loop < 13; Loop++)
		{
			gotoxy(23, 4 + Loop);
			printf("                                              ");
		}
		gotoxy(42, 10);
		printf("Game Over");
	}
	else if (GameEnd == 0)
	{
		for (Loop = 0; Loop < 13; Loop++)
		{
			gotoxy(23, 4 + Loop);
			printf("                                              ");
		}
		gotoxy(37, 10);
		printf("All Stage Clear!");
	}

	Sleep(1000);

	TapTapSurvivalResult(TapTapScore, CP5Score, CP6Score, CP7Score, CP8Score, CP9Score, Life);	// ¼­¹ÙÀÌ¹ú ¸ðµå °á°úÃ¢À¸·Î ³Ñ¾î°¨

	return 0;
}

int TapTapRealPlayResult(int ResultStage, int ResultTapTapScore, int ResultPlayTime, int ResultGameEnd)  // ½ÇÀü¸ðµå °á°úÃ¢
{
	int Loop = 0, Loop1 = 0, Loop2 = 0;
	int ResultRank = 1;
	int ResultTotalScore = 0;
	int Pass = 0;
	int LastSel = 0;
	int SelNext = 0;
	char NickName[20] = { 0, };

	for (Loop = 0; Loop < 35; Loop++)
	{
		if (Pass == 0 && Loop > 12)
		{
			Pass = 1;
			Loop = 22;
		}
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}

	gotoxy(41, 27);
	printf("°Ô ÀÓ °á °ú");
	gotoxy(36, 30);
	Sleep(300);
	printf("Á¡¼ö : %d", ResultTapTapScore);
	Sleep(300);
	gotoxy(29, 32);
	printf("ÇÃ·¹ÀÌ ½Ã°£ : %d", ResultPlayTime);
	Sleep(300);
	gotoxy(27, 34);
	printf("¿Ï·á ½ºÅ×ÀÌÁö :");
	switch (ResultStage)
	{
	case 1:
		gotoxy(43, 34);
		printf("1");
		break;
	case 2:
		gotoxy(43, 34);
		printf("1");
		Sleep(500);
		gotoxy(43, 34);
		printf("2");
		break;
	case 3:
		gotoxy(43, 34);
		printf("1");
		Sleep(500);
		gotoxy(43, 34);
		printf("2");
		Sleep(500);
		gotoxy(43, 34);
		printf("3");
		break;
	case 4:
		gotoxy(43, 34);
		printf("1");
		Sleep(500);
		gotoxy(43, 34);
		printf("2");
		Sleep(500);
		gotoxy(43, 34);
		printf("3");
		Sleep(500);
		gotoxy(43, 34);
		printf("4");
		break;
	case 5:
		gotoxy(43, 34);
		printf("1");
		Sleep(500);
		gotoxy(43, 34);
		printf("2");
		Sleep(500);
		gotoxy(43, 34);
		printf("3");
		Sleep(500);
		gotoxy(43, 34);
		printf("4");
		Sleep(500);
		gotoxy(43, 34);
		printf("5");
		break;
	}
	if (ResultGameEnd == 0)
	{
		gotoxy(43, 34);
		printf("All Stage Clear!");
	}
	Sleep(300);
	ResultTotalScore = ResultTapTapScore + ResultStage * 50;
	if (ResultGameEnd == 0)
		ResultTotalScore += 100;

	gotoxy(36, 36);
	printf("µî±Þ : ¡Ù ¡Ù ¡Ù ¡Ù ¡Ù");

	if (ResultTotalScore < 1100)
	{
		ResultRank = 1;
	}
	else if (ResultTotalScore < 1500)
	{
		ResultRank = 2;
	}
	else if (ResultTotalScore < 1900)
	{
		ResultRank = 3;
	}
	else if (ResultTotalScore < 2100 || ResultTotalScore > 2100 && ResultStage == 4)
	{
		ResultRank = 4;
	}
	else if (ResultTotalScore >= 2200 && ResultStage == 5)
	{
		ResultRank = 5;
	}

	switch (ResultRank)
	{
	case 1:
		PlaySound(NULL, 0, 0);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(43, 36);
		printf("¡Ú");
		break;
	case 2:
		PlaySound(NULL, 0, 0);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(43, 36);
		printf("¡Ú");
		Sleep(300);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(46, 36);
		printf("¡Ú");
		break;
	case 3:
		PlaySound(NULL, 0, 0);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(43, 36);
		printf("¡Ú");
		Sleep(300);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(46, 36);
		printf("¡Ú");
		Sleep(300);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(49, 36);
		printf("¡Ú");
		break;
	case 4:
		PlaySound(NULL, 0, 0);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(43, 36);
		printf("¡Ú");
		Sleep(300);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(46, 36);
		printf("¡Ú");
		Sleep(300);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(49, 36);
		printf("¡Ú");
		Sleep(300);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(52, 36);
		printf("¡Ú");
		break;
	case 5:
		if (ResultGameEnd == 1)
		{
			PlaySound(NULL, 0, 0);
			sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
			gotoxy(43, 36);
			printf("¡Ú");
			Sleep(300);
			sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
			gotoxy(46, 36);
			printf("¡Ú");
			Sleep(300);
			sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
			gotoxy(49, 36);
			printf("¡Ú");
			Sleep(300);
			sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
			gotoxy(52, 36);
			printf("¡Ú");
			Sleep(300);
			sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
			gotoxy(55, 36);
			printf("¡Ú");
		}
		else
		{
			gotoxy(43, 36);
			printf("¡Ú");
			Sleep(300);
			gotoxy(46, 36);
			printf("¡Ú");
			Sleep(300);
			gotoxy(49, 36);
			printf("¡Ú");
			Sleep(300);
			gotoxy(52, 36);
			printf("¡Ú");
			Sleep(300);
			gotoxy(55, 36);
			printf("¡Ú");
		}
		break;
	}

	while (1)
	{
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			break;
		}
	}
	TapTapMain_2();

	return 0;
}	   // 

int TapTapPracticeResult(int ResultStage, int ResultTapTapScore, int ResultPlayTime, int ResultCollision)	// ¿¬½À¸ðµå °á°úÃ¢
{
	int Loop = 0, Loop1 = 0, Loop2 = 0;
	int ResultTotalScore = 0;
	int Pass = 0;

	for (Loop = 0; Loop < 35; Loop++)
	{
		if (Pass == 0 && Loop > 12)
		{
			Pass = 1;
			Loop = 22;
		}
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}

	gotoxy(41, 27);
	printf("¿¬ ½À °á °ú");
	gotoxy(36, 30);
	Sleep(300);
	printf("Á¡¼ö : %d", ResultTapTapScore);
	Sleep(300);
	gotoxy(29, 32);
	printf("ÇÃ·¹ÀÌ ½Ã°£ : %d", ResultPlayTime);
	Sleep(300);
	gotoxy(27, 34);
	printf("¿Ï·á ½ºÅ×ÀÌÁö :");

	gotoxy(43, 34);
	printf("Practice Mode Clear!");

	Sleep(300);
	ResultTotalScore = ResultTapTapScore + ResultStage * 50;

	ResultTotalScore += 100;

	gotoxy(31, 36);
	printf("Ãæµ¹ È½¼ö : %d", ResultCollision);
	Sleep(300);

	while (1)
	{
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			break;
		}
	}
	TapTapMain_2();

	return 0;
}

int TapTapSurvivalResult(int ResultScore, int ResultCP5, int ResultCP6, int ResultCP7, int ResultCP8, int ResultCP9, int ResultLife)  // ¼­¹ÙÀÌ¹ú ¸ðµå °á°úÃ¢
{
	int Loop = 0, Loop1 = 0, Loop2 = 0;
	int ResultRank = 1;
	int ResultTotalScore = 0;
	int Pass = 0;
	int LastSel = 0;
	int SelNext = 0;
	char NickName[20] = { 0, };

	for (Loop = 0; Loop < 35; Loop++)
	{
		if (Pass == 0 && Loop > 12)
		{
			Pass = 1;
			Loop = 22;
		}
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}

	gotoxy(41, 27);
	printf("°Ô ÀÓ °á °ú");
	gotoxy(35, 30);
	Sleep(300);
	printf("Á¡¼ö : %d", ResultScore);
	Sleep(300);
	gotoxy(30, 32);
	printf("³²Àº ¸ñ¼û : %d", ResultLife);
	Sleep(300);
	if (ResultCP9 != 0)
	{
		gotoxy(27, 34);
		printf("Ã¼Å©Æ÷ÀÎÆ® 1 : %d", ResultCP5);
		Sleep(300);
		gotoxy(27, 35);
		printf("Ã¼Å©Æ÷ÀÎÆ® 2 : %d", ResultCP6);
		Sleep(300);
		gotoxy(27, 36);
		printf("Ã¼Å©Æ÷ÀÎÆ® 3 : %d", ResultCP7);
		Sleep(300);
		gotoxy(27, 37);
		printf("Ã¼Å©Æ÷ÀÎÆ® 4 : %d", ResultCP8);
		Sleep(300);
		gotoxy(27, 38);
		printf("Ã¼Å©Æ÷ÀÎÆ® 5 : %d", ResultCP9);
	}
	else if (ResultCP8 != 0)
	{
		gotoxy(27, 34);
		printf("Ã¼Å©Æ÷ÀÎÆ® 1 : %d", ResultCP5);
		Sleep(300);
		gotoxy(27, 35);
		printf("Ã¼Å©Æ÷ÀÎÆ® 2 : %d", ResultCP6);
		Sleep(300);
		gotoxy(27, 36);
		printf("Ã¼Å©Æ÷ÀÎÆ® 3 : %d", ResultCP7);
		Sleep(300);
		gotoxy(27, 37);
		printf("Ã¼Å©Æ÷ÀÎÆ® 4 : %d", ResultCP8);
		Sleep(300);
		gotoxy(27, 38);
		printf("Ã¼Å©Æ÷ÀÎÆ® 5 : X");
	}
	else if (ResultCP7 != 0)
	{
		gotoxy(27, 34);
		printf("Ã¼Å©Æ÷ÀÎÆ® 1 : %d", ResultCP5);
		Sleep(300);
		gotoxy(27, 35);
		printf("Ã¼Å©Æ÷ÀÎÆ® 2 : %d", ResultCP6);
		Sleep(300);
		gotoxy(27, 36);
		printf("Ã¼Å©Æ÷ÀÎÆ® 3 : %d", ResultCP7);
		Sleep(300);
		gotoxy(27, 37);
		printf("Ã¼Å©Æ÷ÀÎÆ® 4 : X");
		Sleep(300);
		gotoxy(27, 38);
		printf("Ã¼Å©Æ÷ÀÎÆ® 5 : X");
	}
	else if (ResultCP6 != 0)
	{
		gotoxy(27, 34);
		printf("Ã¼Å©Æ÷ÀÎÆ® 1 : %d", ResultCP5);
		Sleep(300);
		gotoxy(27, 35);
		printf("Ã¼Å©Æ÷ÀÎÆ® 2 : %d", ResultCP6);
		Sleep(300);
		gotoxy(27, 36);
		printf("Ã¼Å©Æ÷ÀÎÆ® 3 : X");
		Sleep(300);
		gotoxy(27, 37);
		printf("Ã¼Å©Æ÷ÀÎÆ® 4 : X");
		Sleep(300);
		gotoxy(27, 38);
		printf("Ã¼Å©Æ÷ÀÎÆ® 5 : X");
	}
	else if (ResultCP5 != 0)
	{
		gotoxy(27, 34);
		printf("Ã¼Å©Æ÷ÀÎÆ® 1 : %d", ResultCP5);
		Sleep(300);
		gotoxy(27, 35);
		printf("Ã¼Å©Æ÷ÀÎÆ® 2 : X");
		Sleep(300);
		gotoxy(27, 36);
		printf("Ã¼Å©Æ÷ÀÎÆ® 3 : X");
		Sleep(300);
		gotoxy(27, 37);
		printf("Ã¼Å©Æ÷ÀÎÆ® 4 : X");
		Sleep(300);
		gotoxy(27, 38);
		printf("Ã¼Å©Æ÷ÀÎÆ® 5 : X");
	}

	while (1)
	{
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			break;
		}
	}
	TapTapMain_2();

	return 0;
}

int ShutDown()  // FÅ° ÀÔ·Â½Ã ½ÇÇà - ÇÁ·Î±×·¥ Á¾·á
{
	int Loop = 0;
	int Pass = 0;

	SetConsoleTextAttribute(hC, 7);
	gotoxy(5, 21);
	printf("¡Û");
	for (Loop = 0; Loop < 6; Loop++)
	{
		gotoxy(85 + Loop, 21);
		printf("|");
	}
	SetConsoleTextAttribute(hC, 0);
	for (Loop = 0; Loop < 35; Loop++)
	{
		if (Pass == 0 && Loop > 12)
		{
			Pass = 1;
			Loop = 22;
		}
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}
	SetConsoleTextAttribute(hC, 7);
	gotoxy(0, 43);
	exit(1);

	return 0;
}