
#include "stdafx.h"
#include <conio.h>


/* ���� �� ���� ������ �Է� �޾Ƽ� �� ���� ���� ����ϴ� ���α׷��� �ۼ�.
��, ������ ū������ ���� ���� �� ����� ���.
��, ����� ������ 0 �̻��̾���Ѵ�*/

int main(void) {

	int x = 0;
	int y = 0;
	int result = 0;

	scanf("%d%d", &x, &y);

	if (x > y) {
		result = x - y;
	}
	else {
		result = y - x;
	}

	printf("�� ���� ���� : %d\n", result);

	return 0;

}