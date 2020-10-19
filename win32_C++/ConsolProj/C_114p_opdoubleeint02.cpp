
#include "stdafx.h"
#include <conio.h>

int main(void) {


	//교재 114~115p

	int x = 10;

	//int*int -> %d
	printf("%d\n", x * 10);

	//int * double ->출력 불가능 왜냐하면 형승격에 의하여 double형으로 따라가기 때문에 
	printf("%d\n", x * 10.0);

	//int * int 는 int형이며 소수점은 절사된다
	printf("%d\n", x / 10);

	//소수점 이하가 절사되므로 사실상 정수 2를 %f로 출력하는 것이다
	printf("%d\n", 5 / 2);

	//int / int 는 int형이므로 %f로 출력할 수 없다
	printf("%f\n", 5 / 2);

	//double / int 는 double형이다
	printf("%f\n", 5.0 / 2);

	return 0;
}

