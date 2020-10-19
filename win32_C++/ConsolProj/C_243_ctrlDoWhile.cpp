#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 243p do While문
/*
	do while문은 for문과 while문과는 달리 일단 한번은 실행 한 후 조건을 비교한다

	*주의사항*
	문법적으로 조건식괄호뒤에 ;이 붙는다 -<문법 문제 단골 손님
*/
int main(void) {

	char ch = 0;

	do {
		ch = getchar();
		putchar(ch);
	} while (ch != '\n'); // <- 조건식 뒤 ;(세미콜론)이 붙는다


}