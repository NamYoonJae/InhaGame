#include "stdafx.h"
#include <conio.h>



//교재 171p 필수 실습 문제
int main(void) {


	int nMax = -1000;
	int nInput = 0;

	scanf("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	scanf("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	scanf("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	printf("MAX : %d\n", nMax);

	return 0;
}

