#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//포인터 배열과 배열 포인터 비교인데 제대로 이해 못함 다시 공부하기
int main(void) {
	int a = 10, b = 20, c = 30;
	int *pA[3] = { NULL, NULL, NULL }; //포인터 배열

	int arr[2][3] = { 10,20,30,40,50,60 };
	int(*pArr)[3] = NULL;

	pA[0] = &a;
	pA[1] = &b;
	pA[2] = &c;

	printf("%x %x %x \n", &a, &b, &c);
	printf("%x %x %x \n", pA[0], &pA[1], &pA[2]);
	printf("%x %x %x \n", *(pA+ 0), *(pA+1),*(pA+2));
	//위의 3개가 같은 값이 나와야한다 //두번째꺼가 다르게나옴... 수정하기

	//아래꺼는 수정하다가 멈춤
	printf("%d %d %d \n", &a, &b, &c);
	printf("%d %d %d \n", pA[0], &pA[1], &pA[2]);
	printf("%d %d %d \n", **(pA + 0), **(pA + 1), **(pA + 2));


	pArr = arr;

	printf("%d %d %d \n", pArr[0][0], pArr[0][1], pArr[0][2]);
	printf("%d %d %d \n", pArr[0][0], pArr[0][1], pArr[0][2]);


	return 0;
}