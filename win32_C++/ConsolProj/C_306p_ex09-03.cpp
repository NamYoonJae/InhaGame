#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 306p 선택정렬
/*
선택 정렬과정중 값이 작은경우 자리를 바로 교환하는게 아닌 인덱스에 저장 후
현재 선택된 인덱스와 뒤의 값이랑 비교하고 더 작은게 있으면 그것을 인덱스에 저장
비교가 끝난 후 현재 인덱스와 제일 작은 인덱스와 교환
*/
int main() {

	int aList[5] = { 30, 40, 10, 50, 20 };
	int i = 0;
	int j = 0;
	int nTemp = 0;
	int nMinIndex = 0;


	for (j =0; j < 4; j++) 
	{
		nMinIndex = j;	//현재 선택된 배열의 인덱스 값을 nMinIndex에 저장
		for (i = j + 1; i < 5; i++)	//현재 선택된 인덱스와 인접한 인접한 뒤 인덱스 비교

			if (aList[nMinIndex] > aList[i])	//만약 뒤의 인덱스 값이 더 작으면
				nMinIndex = i;	//뒤의 인덱스 값을 nMinIndex에 저장

		//뒤의 인덱스가 더 작으면 nMinIndex가 수정됐을테니 j와 nMin값이 다르게 된다
		//그래서 서로 같지 않다면 뒤의 인덱스 값이 더 작은경우이다.

		if (nMinIndex != j) 
		{
			nTemp = aList[nMinIndex];
			aList[nMinIndex] = aList[j];
			aList[j] = nTemp;
		}

	}
	//출력문
	for (i = 0; i < 5; ++i)

		printf("%d\t", aList[i]);
	putchar('\n');


	

}