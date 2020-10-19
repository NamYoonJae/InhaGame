#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//개인 과제 카페 제출
/*
화면을 지우는 명령어
#include <windows.h>
system("cls"); C에서 가능
_tsystem("cls"); C++에서 가능

_kbhit(); //키보드가 눌렸는지 체크해주는 //함수 입력이 있으면 1 없으면 0을 출력
getch(): //버퍼를 비우란 명령어
Sleep(); //시스템을 잠시 멈춰주는 명령어

키보드 칠 때마다
H e l l o
e l l o   H
l l o   H e
*/

int main(void) {

	char szBuffer[7] = { 'H','e','l','l','o',' ','\0' };
	int i = 0;
	char temp;

	printf("%s\n", szBuffer);
	Sleep(1000);

	while (1)
	{
		system("cls");
		temp = szBuffer[0];

		for (i = 0; i < 5; i++)
		{
			szBuffer[i] = szBuffer[i + 1];
		}

		szBuffer[5] = temp;
		printf("%s\n", szBuffer);

		Sleep(1000);
		system("cls");

	}

	return 0;
}