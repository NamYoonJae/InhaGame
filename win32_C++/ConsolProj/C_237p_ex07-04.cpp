#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 237p 필수 실습 문제 07-04

int main(void) {

	int nInput = 0;
	int i = 1;
	int result = 0;

	scanf("%d", &nInput);

	if (nInput < 0) 
	{
		printf("ERROR\n");
	}
	else if (nInput > 0) 
	{
		while (i < 10)
		{
			result = nInput * i;
			printf("%d * %d = %d\n", nInput, i, result);
			i++;
		}
	
	}

	return 0;
}