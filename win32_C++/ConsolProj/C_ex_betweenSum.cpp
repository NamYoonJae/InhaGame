#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//개인 과제
/*사용자에게서 두 개의 정수를 입력받아 두 정수를 포함해서
그 사이에 존재하는 정수들의 합을 계산하는 프로그램을 작성*/

int main(void) {

	int num1 = 0;
	int num2 = 0;
	int temp = 0;
	int i = 0;
	int total = 0;

	scanf("%d%d", &num1, &num2);

	 if (num1 > num2) 
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	for (num1; num1 < num2 +1; num1++) 
	{
		total += num1;
	}

	printf("%d", total);

	return 0;
}