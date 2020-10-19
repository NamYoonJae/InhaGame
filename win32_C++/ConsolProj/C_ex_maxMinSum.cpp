#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//개인 과제
/*
int aList[5] = {0};
scanf("%d",&aList[2])

길이가 7인 int형 배열을 선언하고, 사용자로부터 총 7개의 정수를 입력받아
1. 입력된 정수 중 최댓값
2. 입력된 정수 중 최솟값
3. 입력된 정의의 총 합
*/

int main(void) {

	int aList[7] = { 0 };
	int i = 0;
	int nMax = 0;
	int nSum = 0;

	for (i = 0; i < 7; i++) 
	{
		scanf("%d", &aList[i]);
		
	}

	for (i = 0; i < 7; i++) 
	{
		nSum += aList[i];

		if (aList[i] > nMax)
		{
			nMax = aList[i];
		}

		else if (aList[i] < aList[0])
		{
			aList[0] = aList[i];
		}
	}

	printf("최댓값은 %d\n", nMax);
	printf("최솟값은 %d\n", aList[0]);
	printf("총 합은  %d\n", nSum);


	return 0;
}