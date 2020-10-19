#include "stdafx.h"
#include <conio.h>


// 교재 59p
int main(void) {

	char ch = 0;	// 자료형이 char 형식이고 이름이 ch인 변수 선언

	ch = getchar(); //인자값 없이 설정

	putchar(ch);
	putchar('Z');

	return 0;	//메인 한수가 int 형이기에 리턴값 0 부여
}
