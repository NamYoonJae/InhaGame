
#include "stdafx.h"
#include <conio.h>


//교재 131~132p 형변환 연산자
int main(void) {


	int x = 5;
	printf("%d\n", 5 / 2);
	printf("%f\n", 5.0 / 2);
	printf("%f\n", 5 / 2.0);
	printf("%f\n", (double)5 / 2);
	printf("%f\n", (double)x / 2);
	printf("%f\n", x / (double)2);
	printf("%f\n", (double)(x / 2));

	return 0;
}

