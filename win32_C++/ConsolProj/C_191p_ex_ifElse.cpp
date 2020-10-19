
#include "stdafx.h"
#include <conio.h>


/* 문제 두 개의 정수를 입력 받아서 두 수의 차를 출력하는 프로그램을 작성.
단, 무조건 큰수에서 작은 수를 뺀 결과를 출력.
즉, 결과는 무조건 0 이상이어야한다*/

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

	printf("두 수의 차는 : %d\n", result);

	return 0;

}