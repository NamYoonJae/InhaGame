#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� break�� continue�� �̿��Ͽ� ¦���� ����غ���
int main(void) {

	int i = 0;

	for (i = 1; i <20; ++i) 
	{
		if (i % 2 == 1)
			continue;//for������ �ٷ� ���ư���. ��, Ȧ�� �� ��� ��� ����

		printf("%dth\n", i);
	}

	printf("END : i ++ %d\n", i);
}