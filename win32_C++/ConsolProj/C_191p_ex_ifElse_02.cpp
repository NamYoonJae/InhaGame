
#include "stdafx.h"
#include <conio.h>

//문제 학점구하기
int main(void) {

	int total = 0;
	int result = 0;

	scanf("%d", &total);

	if (90 <= total) {
		result = 'A';
	}
	else if (80 <= total && total <= 89) {
		result = 'B';
	}
	else if (70 <= total && total <= 79) {
		result = 'C';
	}
	else if (60 <= total && total <= 69) {
		result = 'D';
	}
	else {
		result = 'F';
	}
	printf("홍길동의 학점은 : %c입니다\n", result);

	return 0;

}

