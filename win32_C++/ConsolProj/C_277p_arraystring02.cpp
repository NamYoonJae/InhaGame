#include "stdafx.h"
#include <conio.h>
#include <windows.h>


//교재 277p
/*
	\0을 사용해야하는 이유
	1. 만약 베열 안에 \0가 없다면. 자칫 무한 루프가 발생할 수 있다.
	2. 프로그래머가 기술해야할 배열의 크기는 늘 고정이다.
	하지만 사용자의 입력은 늘 가변이다. 이 둘을 합쳤을 때 NULL문자는 구분자가 되어준다
*/
int main(void) {

	char szBuffer[32] = { 0 };
	int nLength = 0;

	//이름을 입력받아 버퍼에 저장한다.
	printf("Input your name : ");
	gets_s(szBuffer);

	//배열의 시작부터 '\0'가 나올때까지 계속 다음으로 넘기고 확인한다
	while (szBuffer[nLength] != '\0')
		nLength++;

	printf("Your name is %s(%d). \n", szBuffer, nLength);

	return 0;

}