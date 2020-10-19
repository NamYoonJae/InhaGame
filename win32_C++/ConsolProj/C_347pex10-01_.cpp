
#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 348p 다시하기
int GetData(int num1, int num2, int num3);
int getMax(int aList, int aList1, int aList2);
void printfData(int aList, int aList1, int aList2, int nMax);

int main(void) {
	
	int aList[3] = { 0 };
	int nMax = -9999, i = 0;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num5 = 0;

	int nnInput(int aList);

	for (i = 0; i < 3; ++i) 
	{
		aList[i] = GetData(num1, num2, num3);
	}

	getMax(aList[0], aList[1], aList[2]);

	printfData(aList[0], aList[1], aList[2], nMax);
	

	return 0;
}

int GetData(int num1, int num2, int num3)
{
	printf("정수를 입력하세요. :");
	scanf("%d %d %d", num1,num2, num3);
	return num1, num2, num3;
}

int getMax(int aList, int aList1, int aList2)
{
	int nMax = aList;
	if (aList1 > nMax) nMax = aList1;
	if (aList2 > nMax) nMax = aList2;
	return 0;
}

void printfData(int aList, int aList1, int aList2, int nMax)
{
	printf("%d %d %d 중 가장 큰 수는 %d 입니다\n", aList, aList1, aList2, nMax);
}

