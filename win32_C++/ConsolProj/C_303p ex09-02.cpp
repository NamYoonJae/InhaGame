#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 302p 버블 정렬
int main(void) {

	int aList[5] = { 30, 40, 10, 50, 20 };
	int i = 0, j = 0, nTemp = 0;

	for (j = 0; j < 4; j++) 
	{
		for (i = 0; i < 5-j; i++) 
		{
			if (aList[i] < aList[i+1])
			{
			nTemp = aList[i + 1];
			aList[i + 1] = aList[i];
			aList[i] = nTemp;
			}
		}
	}

	for (i = 0; i < 5; ++i)
		printf("%d\t", aList[i]);
	putchar('\n');

	return 0;

}