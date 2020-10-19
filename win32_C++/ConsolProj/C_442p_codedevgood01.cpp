#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//442~445p 합친내용이다 다시해보기 (입력 받을때 터짐
/*
1. line43 에 있는 aList[]를 *pList 로 바꿀 것
2. InitList 함수
	2.1 입력받는대로 메모리 재할당하고 크기를 계산하는 형태로 바꾸기
	2.2 무한 입력, 양의 정수만 받도록하고 음수가 입력되면 종료
3. 각 함수 호출 시 두 번째 인자 5는 변수로 바꾸어 줄 것

*/


int InitList(int *pList, int nSize);
void SortList(int *pList, int nSize);
void printList(int *pList, int nSize);


int main(void) {

	int *pList = (int*)malloc(sizeof(int));
	int nSize = 0;

	nSize = InitList(pList, nSize);
	SortList(pList, nSize);
	printList(pList, nSize); //넘겨줄 때는 주소값을 넘겨줘야한다

	return 0;
}

int InitList(int *pList, int nSize) {

	int i = 0;
	int x = 0;
	while (1) {

		printf("정수를 입력하세요 : ");
		scanf("%d", &pList[i]); // i 0부터 시작
		if (pList[i] < 0) break;

		i++;// i 하나 증가
		pList = (int*)realloc(pList, sizeof(int)*(i+1));// pList의 공간을 sizeof(int)*i만큼 늘려주겠다는 뜻 
														// 만약 41번째에서 i증가가면 원래자리
														// 그리고 이어 붙여야하니까 다음자리를 +1을 해야한다
		
		
		nSize++;
	}
	return nSize;
}

void SortList(int *pList, int nSize) {

	int i = 0, j = 0, nTmp = 0;

	for (i = 0; i <nSize; ++i) 
	{
		for (j = i + 1; j < nSize; ++j) 
			if(pList[j] < pList[i])
		{
				nTmp = pList[j];
				pList[j] = pList[i];
				pList[i] = nTmp;
		}
	}

}

void printList(int *pList, int nSize) {
	
	int i = 0;
	for (i = 0; i < nSize; ++i)
		printf("%d\t", pList[i]);
	putchar('\n');
	
}