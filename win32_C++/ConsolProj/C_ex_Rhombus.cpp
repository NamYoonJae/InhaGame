
#include "stdafx.h"
#include <conio.h>



int main(void) {


	//개인 과제 마름모 만들기
	int x = 0;
	int y = 0;

	for (x = 0; x < 5; x++) {

		for (y = 0; y < 5; y++) {
			if (x + y == 2)
			{
				printf("*");
			}

			else if (x + y == 3 && x * y != 0) {
				printf("*");
			}
			else if (x + y == 4 && x * y != 0)
			{
				printf("*");
			}
			else if (x + y == 5 && x * y != 4)
			{
				printf("*");
			}

			else if (x + y == 6)
			{
				printf("*");
			}

			else
				printf(" ");

		}
		printf("\n");
	}


	return 0;
}