#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 275p
int main(void) {
	
	int aList[5] = { 30, 40, 10, 50, 20 };
	char szBuffer[6] = { 'H','e','l','l','o','\0', };
	//\0은 문장의 끝을 나타낸다.
	//e와 \0의 자리를 바꾸면 H만 출력된다.

	char szData[8] = {"Hello"};
	char *pszBuffer = "Hello";

	puts(szBuffer);
	puts(szData);
	puts(pszBuffer);

	return 0;

}