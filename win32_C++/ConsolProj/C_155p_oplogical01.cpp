
#include "stdafx.h"
#include <conio.h>


//교재 155p 논리합(OR) 논리곱(AND) 연산자
int main(void) {

	int nInput = 0, bResult = 0;

	scanf("%d", &nInput);
	bResult = nInput < 4 || nInput >= 60;
	printf("Result : %d(1: True0: False)\n", bResult);

	return 0;
}

