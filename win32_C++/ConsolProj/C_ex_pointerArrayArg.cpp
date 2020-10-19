#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//그냥 연습
int main(void) {

	/*
		다음 코드를 이용 실행결과와 같은 형태로 출력되도록 프로그램을 작성.
		char* string [2] = {"I Love C", "Hello World"};

		결과 >
			I Love C world


	*/

	char* string[2] = { "I Love C", "Hello World" };
	
	printf("%s", string[0]);
	printf("%s", string[1] + 5);



	return 0;
}