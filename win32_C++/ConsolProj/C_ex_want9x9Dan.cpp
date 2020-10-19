#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//개인 과제
/*
[9][9] 99단을 배열에 넣는다 //다시하기
출력원하는 구구단 ? x
x단 띄우기
*/

int main() {
	
	int aList[9][9]; // 9단
	int nInput = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	int k = 2;
	int i = 0;

	printf("원하는 구구단은 ?\n");

	scanf("%d", &nInput);

	for (x = 0; x < 9; x++) 
	{

		for (y = 0; y < 9; y++) 
			aList[y][x] = k*(y + 1);
		k++;
	}
	
	for (x = 0; x < 9; x++) 
	{
		printf("%d x %d = %d\n", nInput, x+1, aList[x][nInput-2]);
	}

	return 0;
}