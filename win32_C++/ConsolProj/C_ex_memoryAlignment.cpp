#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
#include <malloc.h>
#include <string.h>

//개인과제 카페에 올리기
/*
Q. 입력 갯수가 정해지지 않은 상태에서
-1을 입력할 때까지 입력한 모든 수들을 출력하고,
선택정렬 혹은 버블정렬의 방법으로 오름차순 혹은 내림차순으로
정렬한 모든 수들을 다시 출력하는 프로그램을 작성하세요.
* 주의) 반드시 포인터와 메모리 할당을 이용해서 프로그램을 구성해야 합니다.
*/




int main(void) {

	int *szBuffer = NULL;
	int i = 0;
	int j = 0;
	int nCnt = 0;
	int temp = 0;

	szBuffer = (int*)malloc(sizeof(int));

	while (1)
	{
		printf("숫자를 입력하세요\n");
		scanf_s("%d", &szBuffer[i], sizeof(szBuffer[i]));

		if (szBuffer[i] == -1) break;

		realloc(szBuffer, sizeof(int)*(i + 2));

		i++;
		nCnt++;

	}

	printf("입력한 수는 ");
	for (i = 0; i < nCnt; i++)
	{
		printf("%d, ", szBuffer[i]);
	}
	putchar('\n');


	//오름차순
	for (i = 0; i < nCnt; i++)
	{
		for (j = i + 1; j < nCnt; j++)
		{
			if (szBuffer[i] > szBuffer[j])
			{
				temp = szBuffer[i];
				szBuffer[i] = szBuffer[j];
				szBuffer[j] = temp;
			}

		}
	}

	printf("오름차순 정렬 : ");
	for (i = 0; i < nCnt; i++)
	{
		printf("%d, ", szBuffer[i]);
	}

	free(szBuffer);
	return 0;
}