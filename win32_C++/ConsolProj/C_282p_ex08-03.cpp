#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//±³Àç 282p
int main(void) {

	int aList[3][4] = { {10, 20, 30},{40, 50, 60} };

	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;

	
	for (i = 0; i < 3; ++i) 
	{
		aList[2][i] = aList[0][i] + aList[1][i];

		for (j = 0; j <4; ++j) 
		{
			printf("%d\t", aList[i][j]);
			aList[j][3] = aList[j][0] + aList[j][1] + aList[j][2];

		}

		putchar('\n');

	}
	

		putchar('\n');

	}

}