
#include "stdafx.h"
#include <conio.h>


//���� 126p ���� ���� ������
int main(void) {

	int nResult = 0, nData = 10;

	nResult += 3;
	printf("%d\n", nResult);

	nResult *= nData;
	printf("%d\n", nResult);

	nResult /= 2;
	printf("%d\n", nResult);

	nResult -= 5;
	printf("%d\n", nResult);

	nResult %= 3;
	printf("%d\n", nResult);

	return 0;
}

