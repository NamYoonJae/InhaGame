
#include "stdafx.h"
#include <conio.h>

int main(void) {

	//교재 119p 필수 실습문제 04 -02

	int watch = 0;
	scanf("%d", &watch);
	printf("입력 예 : %d\n", watch);

	int h = watch / 3600;
	int m = watch % 3600 / 60;
	int s = watch % 3600 % 60;

	printf("%02d시 %02d분 %02d분", h, m, s);
}

