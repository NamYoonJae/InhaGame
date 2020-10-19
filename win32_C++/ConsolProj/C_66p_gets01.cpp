#include "stdafx.h"
#include <conio.h>

//교재 66p
int main(void) {

	char szname[32];	// szname 영역 크기 32로 설정

	int nsize = sizeof(szname); // sizeof - 사이즈 측정 함수
	printf("szname size : %d %c\n", nsize, 65);	//nsize 크기 출력 // %c 아스키 코드를 표현 a가 아스키 코드 65이므로 화면에는 a가 출력된다


	printf("이름을 입력하세요");

	gets_s(szname, sizeof(szname));

	printf("당신의 이름은");

	puts(szname);
	puts("입니다");

	return 0;

}

