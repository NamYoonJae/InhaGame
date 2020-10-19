#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
#include <malloc.h>
#include <string.h>

/*
입력개수를 미리 지정하지 않고 숫자를 입력받아서
숫자를 입력받을 때마다 메모리를 늘려가면서 처리하는 코드를
이용해 프로그램을 짠다.입력받는 숫자는 자연수이며,
-1이 입력되면 입력받은 숫자들과 그 합을 출력하고 프로그램을 종료한다.
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


	printf("숫자를 입력하세요\n");
	while (1)
	{

		scanf_s("%d", &szBuffer[i], sizeof(szBuffer[i]));

		if (szBuffer[i] == -1) break;

		totalSum += szBuffer[i];

		memcpy(szNewBuffer, szBuffer, _msize(szBuffer)); //szBuffer를 szNewBuffer에 복사
		free(szBuffer); //szBuffer 할당 해제


		//이제 다음 값을 추가로 받을 수 있게 메모리 한칸 더 키워서 다시 할당하기
		szBuffer = (int*)malloc(sizeof(int) * (i + 2));
		memset(szBuffer, 0, _msize(szBuffer));

		//이전 값을 메모리 크기 늘린 곳에 다시 복사하기
		memcpy(szBuffer, szNewBuffer, _msize(szNewBuffer));
		free(szNewBuffer);

		//szNewBuffer 메모리 크기 키워서 다시 할당
		szNewBuffer = (int*)malloc(sizeof(int) * (i + 2));
		memset(szNewBuffer, 0, _msize(szNewBuffer));

		nCnt++;
		i++;

	}

	printf("입력한 수는 ");
	for (i = 0; i < nCnt; i++)
	{
		printf(" %d ", szBuffer[i]);
	}
	putchar('\n');

	printf("총 합은 %d 입니다\n", totalSum);

	if (szBuffer != NULL) free(szBuffer);
	if (szNewBuffer != NULL) free(szNewBuffer);

}