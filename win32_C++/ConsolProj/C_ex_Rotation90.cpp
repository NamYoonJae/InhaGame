#include "stdafx.h"
#include <conio.h>
#include <windows.h>

/*
1 2 3 4
5 6 7 8

5 1
6 2
7 3
8 4

*/

int main(void) {

	int aList[2][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8}
	};

	int temp[4][2];

	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i < 4; i++) 
	{
		temp[i][1] = aList[0][i];
		temp[i][0] = aList[1][i];
		printf("%d %d\n", temp[i][0], temp[i][1]);
	}

}