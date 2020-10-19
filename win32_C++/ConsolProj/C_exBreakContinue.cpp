#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//과제 break와 continue를 이용하여 짝수만 출력해보자
int main(void) {

	int i = 0;

	for (i = 1; i <20; ++i) 
	{
		if (i % 2 == 1)
			continue;//for문으로 바로 돌아간다. 즉, 홀수 일 경우 출력 생략

		printf("%dth\n", i);
	}

	printf("END : i ++ %d\n", i);
}