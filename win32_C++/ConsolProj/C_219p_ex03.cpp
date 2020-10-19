#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 219p 연습문제 3 지역변수 nInput 값 확인 및 비교
int main(void) {

	int nInput = 0;
	scanf("%d", &nInput);

	if (nInput>10) 
	{
		int nInput = 20;
		printf("%d\n", nInput);

		if (nInput > 20) 
		{
			int nInput = 30;
			printf("%d\n", nInput);
		}
	}

	printf("%d\n", nInput);

	return 0;
}