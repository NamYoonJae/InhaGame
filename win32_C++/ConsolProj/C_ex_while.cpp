#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//개인 과제 제출
/*
사용자로부터 계속해서 정수를 입력받는다.
그 값을 계속 더해 나간다
사용자가 0을 입력할 떄까지 계속 되어야하며,
0이 입력되면 입력된 모든 정수의 합을출력하고 프로그램을 종료한다
*/


int main(void) {

	int nInput = 0;
	int result = 0;

	scanf("%d", &nInput);

	while (nInput!=0)
	{
		result = nInput + result;
		scanf("%d", &nInput);
	}

	printf("총 합은 %d 입니다", result);


}