#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//과제 X모양 별 출력하기 제출
int main(void) {

	int x = 0;
	int y = 0;
	int z = 0;

	int nInput = 0;

	printf("숫자를 입력하시오");
	scanf("%d", &nInput);

	for (x = 0; x < nInput; x++) 
	{
		for (y = 0; y < nInput; ++y) 
		{
			if (x == y)
			{
				printf("*");
			}

			else if (nInput == x + y + 1)
			{
				printf("*");
			}

			else
				printf("  ");

		}

		printf("\n");
	}


}