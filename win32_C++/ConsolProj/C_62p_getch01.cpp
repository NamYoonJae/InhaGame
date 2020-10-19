#include "stdafx.h"
#include <conio.h>	//콘솔io 콘솔창 입력이 필요해서 사용

//교재 62p
int main(void) {

	int i = 0;
	char ch = 0;

	printf("아무 키나 누르면 다음으로 넘어갑니다.\n");

	ch = _getch();

	printf("입력한 키는");
	putchar(ch);

	printf("입니다\n");

	return 0;
}


