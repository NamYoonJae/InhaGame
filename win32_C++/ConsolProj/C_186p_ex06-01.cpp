
#include "stdafx.h"
#include <conio.h>

int main(void) {


	//���� 186p �ʼ� �ǽ� ���� 06-01

	int x = 0;
	int y = 0;
	int z = 0;
	int temp = 0;
	int nMax = 0;

	scanf("%d %d %d", &x, &y, &z);

	if (x > y ? temp = x : temp = y);

	if (z > temp ? nMax = z : nMax = temp);

	printf("Max ���� %d �Դϴ�", nMax);

	return 0;

}

