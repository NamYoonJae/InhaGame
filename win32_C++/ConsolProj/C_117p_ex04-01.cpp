#include "stdafx.h"
#include <conio.h>

int main(void) {


	//교재 117p 필수 실습문제 04-01

	float x = 0; //소수점 두 번째 까지 표현할 것이기에 실수형으로 선언
	float y = 0;

	printf("첫번째 정수를 입력하세요");

	scanf("%f*c", &x); //실수형이기에 %f 사용 / *c 엔터 입력 날리기 위해 사용

	printf("두번째 정수를 입력하세요");

	scanf("%f*c", &y);


	printf("%0.2f\n", x + y); //소수점 두 번째 까지 표현하기위해 0.2 또는 .2를 붙임
	printf("%0.2f\n", x - y);
	printf("%0.2f\n", x * y);
	printf("%0.2f\n", x / y);

	return 0;
}

