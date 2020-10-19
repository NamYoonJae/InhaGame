#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 237p 필습 실습 문제 07-03
int main(void) {

	int i = 0;
	int j = 0;
	int forNum = 0;
	int forTotal = 0;
	int whileTotal = 0;

	for (i = 0; i <= 10; ++i) 
	{
		forTotal += i;
	}

	printf("%d\n", forTotal);

	while (j<=10)
	{
		whileTotal += j;
		++j;
	}

	printf("%d\n", whileTotal);


	return 0;
}