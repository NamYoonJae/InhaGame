
#include "stdafx.h"
#include <conio.h>


//���� 206p switch-case ��
int main(void) {

	char cOperator = 0;
	int x = 0, y = 0, nResult = 0;

	scanf("%d%c%d", &x, &cOperator, &y);

	switch (cOperator)
	{
	case '+':
		nResult = x + y;
		break;

	case '-':
		nResult = x - y;
		break;

	case '*':
		nResult = x * y;
		break;

	case '/':
		nResult = x / y;
		break;

	default:

		puts("Error: �� �� ���� ��� �����Դϴ�.");
		break;
	}

	printf("Result: %d\n", nResult);
	return 0;

}