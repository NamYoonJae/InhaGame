#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 279p
int main(void) {

	int aList[3][4] = { 
		{ 10, 20, 30, 40 },
		{ 50, 60, 70, 80 }, 
		{90, 100, 110, 120} };

	int i = 0, j = 0;

	//행 단위 처리를 위한 바깥쪽 반복문
	for (i = 0; i < 3; ++i) 
	{	
		//열단위 처리를 위한 안쪽 반복문
		for (j = 0; j < 4; j++) 
		{
			printf("%d\t", aList[i][j]);
		}

		//한 행을 출력 할 때마다 개항한다.
		putchar('\n');
	}

	return 0;
}