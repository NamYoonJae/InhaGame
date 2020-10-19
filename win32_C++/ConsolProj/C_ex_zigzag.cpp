#include "stdafx.h"
#include <conio.h>
#include <windows.h>

void making();


//메인
int main(void) {

	int aList[5][5] = { 0 };
	making();

}

//함수
void making()
{
	int x = 0;
	int y = 5;

	int aList[5][5] = { 0 };
	int num = 1;
	int i = 0;
	int j = 0;

	aList[0][0] = num++;

	for (i = 1; i >= 0; i--)
		aList[x++][i] = num++;
	x++;

	for (i = 0; i < 3; i++)
		aList[--x][i] = num++;

	for (i = 3; i >= 0; i--)
		aList[x++][i] = num++;
	x++;

	for (i = 0; i < 5; i++)
		aList[--x][i] = num++;

	for (i = 1; i < 5; i++)
		aList[i][--y] = num++;

	for (i = 4; i > 1; i--)
		aList[i][++y] = num++;

	for (i = 3; i < 5; i++)
		aList[i][y--] = num++;

	aList[4][4] = num;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", aList[i][j]);
		}
		printf("\n");
	}

}
