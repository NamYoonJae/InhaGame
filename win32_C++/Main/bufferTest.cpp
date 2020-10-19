#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main(void) {

	HANDLE hBuffer[2]; // 버퍼를 저장할 핸들
	//HANDLE g_hScreen[2];
	int nScreenIndex; //현재 선택된 버퍼가 무엇인지 저장

	//1. 버퍼 생성
	{
		COORD size = { 80, 25 }; //버퍼크기관련 구조체
		SMALL_RECT rect; //창 크기 관련 구조체
		rect.Left = 0;
		rect.Right = 80 - 1;
		rect.Top = 0;
		rect.Bottom = 25 - 1;
		//버퍼를 생성하기 전에 버퍼의 크기와 창의 크기를 설정할 구조체 COORD와 SMALL_RECT를 선언해주고 원하는 크기 할당

		//첫번째 버퍼 생성
		hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);//버퍼 생성 함수이다
		SetConsoleScreenBufferSize(hBuffer[0], size); //콘솔 버퍼의 크기 설정 //버퍼 크기관련 구조체의 사이즈만큼
		SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);//콘솔 창 크기 설정

		//두번째 버퍼 생성
		hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);//버퍼 생성 함수이다
		SetConsoleScreenBufferSize(hBuffer[1], size);
		SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);


	}

	//2. 버퍼 쓰기
	{
		int x = 0;
		int y = 0;
		char a[20] = "입력할 문자열";

		DWORD dw; //좌표를 저장하기 위한 구조체 선언
		COORD CursorPosition = { x ,y }; //좌표 설정
		SetConsoleCursorPosition(hBuffer[nScreenIndex], CursorPosition);	//좌표 이동 //첫번째 값은 표준콘솔핸들값이면 두번째 값은 위치값이다
		//WriteFile(hBuffer[nScreenIndex], a, strlen(a), &dw, NULL); //버퍼에 씀
		//윈도우 환경에서 파일에 출력할 때 사용
		//

	}

	//3. 버퍼 전환
	{
		Sleep(33);
		SetConsoleActiveScreenBuffer(hBuffer[nScreenIndex]);//버퍼를 활성화 함으로써 화면에 버퍼내용을 한번에 출력
		nScreenIndex = !nScreenIndex;//nScreenIndex값이 0과 1로 체인지
	}

	//4. 버퍼 내용 지우기
	{
		DWORD dw; //세번째 줄의 함수를 위한 구조체
		COORD Coor = { 0, 0 }; //좌표설정
		FillConsoleOutputCharacter(hBuffer[nScreenIndex], ' ', 80 * 25, Coor, &dw);
		//버퍼의 모든 공간에 스페이스 바를 넣어 화면이 지워 진 것 처럼 만든다

	}

	//5. 버퍼 해제
	{
		CloseHandle(hBuffer[0]);//버퍼 해제
		CloseHandle(hBuffer[1]);//버퍼 해제
	}




}
