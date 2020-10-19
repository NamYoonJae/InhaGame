
#include "stdafx.h"
#include <conio.h>

//교재 105p 연습문제 1번
int main(void) {

	printf("입력 :");	 //Test를 입력한다고 가정하면 버퍼에 Test글자가 각각 저장됨
	getchar();	// 버퍼에서 첫번째 글자인 T를 가져옴
	printf("출력 :%c\n", getchar()); //버퍼 남은 글자는 est중 앞글자 e를 출력하게된다

	return 0;

}