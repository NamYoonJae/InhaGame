
#include "stdafx.h"
#include <conio.h>


//교재 206p switch-case 문
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

		puts("Error: 알 수 없는 산술 연산입니다.");
		break;
	}

	printf("Result: %d\n", nResult);
	return 0;

}