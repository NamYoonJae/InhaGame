#include "stdafx.h"
#include <conio.h>


//���� 241p �ʼ� �ǽ����� 07-05
int main(void) {

	int x = 0;
	int y = 0;

	for (x = 0; x < 5; ++x)
	{
		for (y = 0; y < x * 1 + 1; ++y)
			printf("*\t");

	putchar('\n');
	}

	return 0;

}
/*
x = 0; y�� 1���� ���Ƽ� *�ϳ��� �Է�
x = 0' y�� 2�϶� y<1�̹Ƿ� 1�� ����
x = 1 �� �� y3�� ������ 2�� ���� **�� �Է��ϰ� ����
.
.
.
*/