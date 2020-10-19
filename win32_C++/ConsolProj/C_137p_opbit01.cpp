
#include "stdafx.h"
#include <conio.h>

int main(void) {


	//교재 137p 비트 연산자

	int x = 20;
	int y = 15;

	printf("%08X\n", x & y);
	printf("%08X\n", x | y);
	printf("%08X\n", x ^ y);
	printf("%08X\n", ~x);
	printf("%08X\n", x >> 8);
	printf("%08X\n", x << 16);

	return 0;
}

