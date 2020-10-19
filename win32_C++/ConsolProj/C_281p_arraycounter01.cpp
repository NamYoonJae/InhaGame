#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//±³Àç 281p
int main(void) {
	
	int aList[3][4] = { 0 };
	int i = 0;
	int j = 0;
	int nCounter = 0;

	for (i = 0; i < 3; ++i) 
	{
		for (j = 0; j < 4; ++j) 
		
			aList[i][j] = ++nCounter;
		
	}

	for (i = 0; i < 3; ++i) 
	{
		for (j = 0; j < 4; j++) 
			printf("%d\t", aList[i][j]);
		putchar('\n');
	}


	return 0;
}