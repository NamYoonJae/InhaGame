
#include "stdafx.h"
#include <conio.h>


//���� 129p �⺻ ����
int main(void) {

	int nInput = 0;
	int nTotal = 0;

	scanf("%d", &nInput);
	nTotal = nInput;

	scanf("%d", &nInput);
	nTotal += nInput;

	scanf("%d", &nInput);
	nTotal += nInput;


	printf("Total : %d\n", nTotal);

	return 0;
}

