
#include "stdafx.h"
#include <conio.h>

int main(void) {

	//���� 119p �ʼ� �ǽ����� 04 -02

	int watch = 0;
	scanf("%d", &watch);
	printf("�Է� �� : %d\n", watch);

	int h = watch / 3600;
	int m = watch % 3600 / 60;
	int s = watch % 3600 % 60;

	printf("%02d�� %02d�� %02d��", h, m, s);
}

