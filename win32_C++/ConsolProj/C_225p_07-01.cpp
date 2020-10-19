#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 225p 필수실습문제 07-01
int main(void) {

	int nInput = 0;
	int i = 0;

	scanf("%d", &nInput);

	if (1 > nInput) //만약 입력한 값이 음수라면
		nInput = 1; //1로 고정

	else if (nInput > 10) //만약 입력한 값이 10 초과면
		nInput = 9; //9로 고정

	while (nInput>i) //입력한 수 > i 번 돌린다
	{
		putchar('*');
		i++;
	}

	putchar('\n');

	return 0;
}