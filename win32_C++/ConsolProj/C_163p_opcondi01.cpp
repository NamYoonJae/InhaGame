
#include "stdafx.h"
#include <conio.h>

//교재 163p 조건연산자 (삼항연산자)
int main(void) {

	int nInput = 0, nSelect = 0;
	scanf("%d", &nInput);

	nSelect = nInput < +10 ? 10 : 20;
	printf("%d\n", nSelect);

	return 0;
}

