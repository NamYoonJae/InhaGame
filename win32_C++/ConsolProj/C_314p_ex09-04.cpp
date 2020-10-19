#include "stdafx.h"
#include <conio.h>
#include <windows.h>

int main(void) {

	int aList[5][5];

	int i = 0;
	int j = 0;

	int x = 0;
	int y = -1;

	int num = 1;
	int ndata = 1; //행 혹은 열 인덱스에 더해갈 숫자(증가할 때는 1, 감소할 때는 - 1)
	int flag = 5; //한쪽으로 이동할 수 있는 숫자

	while (1)
	{
		for ( i = 0; i < flag; i++) 
		{
			y = y + ndata;
			aList[x][y] = num;
			num++;
		}

		flag--;

		if (flag < 0) break;

		for(i = 0; i < flag; i ++)
		{
			x = x + ndata;
			aList[x][y] = num;
			num++;
		}

		ndata = -ndata;
	}

	for (i = 0; i < 5; i++) 
	{
		for (j = 0; j < 5; j++) 
		{
			printf("%d\t", aList[i][j]);
		}
		putchar('\n');
	}


	return 0;
}