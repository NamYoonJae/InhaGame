#include "stdafx.h"
#include <conio.h>


//교재 241p 필수 실습문제 07-05
int main(void) {

	int x = 0;
	int y = 0;

	for (x = 0; x < 5; ++x)
	{
		for (y = 0; y < x * 1 + 1; ++y)
			printf("*\t");

	putchar('\n');
	}

	return 0;

}
/*
x = 0; y는 1까지 돌아서 *하나만 입력
x = 0' y는 2일때 y<1이므로 1행 종료
x = 1 일 떄 y3이 됨으로 2번 돌아 **개 입력하고 종료
.
.
.
*/