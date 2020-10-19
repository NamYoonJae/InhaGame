
#include "stdafx.h"
#include <conio.h>

int main(void) {


	//교재 117~118p

	//나머지 연산은 정수로 나오기때문에 실수연산을 쓰면 안된다

	int x = 0;

	scanf("%d", &x);

	printf("몫 : %d\n", x / 3);
	printf("나머지 : %d\n", x % 3);

	return 0;

}

