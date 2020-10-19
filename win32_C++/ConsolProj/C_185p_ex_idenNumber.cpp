
#include "stdafx.h"
#include <conio.h>

//교재 185p 제어문과 스코프
//연습문제 if문을 사용하여 양수 음수 구별하기

int main(void) {

	int num = 0;

	scanf("%d", &num);

	if (num < 0)
		printf("음수입니다\n", num);

	if (num > 0)
		printf("양수입니다\n", num);

	return 0;
}

