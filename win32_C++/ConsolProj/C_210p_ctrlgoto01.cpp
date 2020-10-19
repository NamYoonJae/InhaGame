
#include "stdafx.h"
#include <conio.h>


//교재 210p goto 문 그냥 해보고 기억에서 지우기. 위험해서 잘 안쓴다
//동작만 확인해보자

int main(void) {

	int nInput;

INPUT:
	printf("Input number : ");
	scanf("%d", &nInput);

	if (nInput < 0 || nInput > 10)
		goto INPUT;

	puts("End");
	return 0;


}