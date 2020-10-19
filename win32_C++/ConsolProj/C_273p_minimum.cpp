#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 273p 최소값 구하기
int main(void){
	
	int aList[5] = { 30, 40, 10, 50, 20 };
	int i = 0, nTemp = 0;

	for (i = 0; i < 5; i ++) 
	{
		if (aList[i]<aList[0]) 
		{
			nTemp = aList[0];
			aList[0] = aList[i];
			aList[i] = nTemp;
		}
	}

	for (i = 0; i < 5; i++)

		printf("%d\t", aList[i]);
	putchar('\n');

	printf("MAX : %d\n", aList[0]);



	return 0;
}