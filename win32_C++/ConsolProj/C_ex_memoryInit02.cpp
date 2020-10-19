#include <stdio.h>
#include <stdlib.h>
#include <stdafx.h>
#include <malloc.h>

/*
입력 값은 자연수 이다
입력 받는 대로 버퍼 늘리고 -1 입력시 총 합을 구한다
*/


void nInput();

int main(void) {

	nInput();

	return 0;
}

void nInput() {

	int i = 0;
	int x = 0;
	int totalSum = 0;
	int nInput = 0;

	int  *szBuffer = NULL;
	int *szNewBuffer = NULL;
	int nCnt = 0;


	szBuffer = (int*)malloc(sizeof(int));
	szNewBuffer = (int*)malloc(sizeof(int));

	printf("숫자를 입력하세요.\n");
	while (1)
	{
		scanf("%d", szBuffer[x++], sizeof(szBuffer[x++]));

		if (nInput == -1) break;
		nCnt++;
		totalSum += szBuffer[x++];

		memcpy(szNewBuffer, szBuffer, _msize(szBuffer));
		free(szBuffer);


	}

	printf("nCnt 값은 %d\n", nCnt);

	for (i = 0; i<nCnt; i++)
	{
		printf("szBuffer 값은%d\n", szBuffer[i]);
	}

	memcpy(szNewBuffer, szBuffer, nCnt);
	free(szBuffer);

	//포인터를 사용하는 이유 : 메모리에 직접 접근이 가능하다
	//포인터를 사용함으로써 복사본을 만들지않고 주소에 바로 접근해서 메모리가 한정적이거나 처리시간이 중요한 시스템에 쓰인다.
	//너무 하이리스크인데 이렇게까지 직접 접근하는 이유는 ?
	//쓰임새 어떤경우에 많이쓰이는지 비교설명이 필요


	free(szNewBuffer);






}