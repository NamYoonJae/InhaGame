
#include "stdafx.h"
#include <conio.h>

int main(void) {


	//교재 123p 두 변수 교환(swap)

	int x = 10, y = 20, nTemp = 0;

	printf("Before: %d, %d\n", x, y);

	nTemp = x;

	x = y;

	y = nTemp;

	printf("Before: %d, %d\n", x, y);

	return 0;
}

