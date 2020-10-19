
#include "stdafx.h"
#include <conio.h>

int main(void) {


	//±³Àç 157p

	int nInput = 0, bResult = 0;
	scanf("%d", &nInput);
	bResult = nInput > 3 && nInput < 20;
	printf("Result : %d(1: True0: False)\n", bResult);
	return 0;
}

