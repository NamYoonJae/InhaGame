#include "stdafx.h"
#include <conio.h>



//���� 171p �ʼ� �ǽ� ����
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

