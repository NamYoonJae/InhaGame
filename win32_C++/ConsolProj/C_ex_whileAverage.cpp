#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//개인 과제 제출
/*
입력받은 정수의 평균을 출력하는 프로그램을 작성
1. 먼저 몇 개의 정수를 입력 할 것인지 물어보고, 그 수 만큼 입력 받는다.
2. 평균 값은 소수점 이하 2자리까지 출력한다.
*/

int main(void) {

	int howNum = 0;
	int nInput = 0;
	int i = 0;
	int total = 0;

	printf("몇 개의 정수를 입력하시겠습니까 ? ");
	scanf("%d", &howNum);	//값을 입력받는다.

	while (i < howNum)	//입력한 값만큼 반복한다
	{
		scanf("%d", &nInput);
		i++;
		total += nInput; //반복하면서 total에 모두 더한다
	}

	printf("%.2f", double(total / i));


	return 0;
}