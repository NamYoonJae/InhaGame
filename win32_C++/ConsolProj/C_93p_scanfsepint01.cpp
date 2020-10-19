
#include "stdafx.h"
#include <conio.h>

//교재93p
int main(void) {

	int x = 0, y = 0;

	printf("두 정수를 입력하세요. : ");

	//%d와 %d에 공백이 없다는 점에 주의한다
	scanf("%d%d", &x, &y);

	printf("두 수의 합은 %d입니다. \n", x + y);

	return 0;
}
