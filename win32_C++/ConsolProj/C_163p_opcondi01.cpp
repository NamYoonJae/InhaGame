
#include "stdafx.h"
#include <conio.h>

//���� 163p ���ǿ����� (���׿�����)
int main(void) {

	int nInput = 0, nSelect = 0;
	scanf("%d", &nInput);

	nSelect = nInput < +10 ? 10 : 20;
	printf("%d\n", nSelect);

	return 0;
}

