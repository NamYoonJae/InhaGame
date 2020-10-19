#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//교재 438p 과제 카페에 올리기
/*
char*를 몇 개 생성할지 입력 받기
입력할 문자열 최대 길이 입력받기

그리고 char*에 입력한 만큼 동적할당
문자열 길이만큼 할 수 있는 동적할당해서 입력받은 문자열 저장
그 후 출력

*/


//char를 몇개 할지 입력하기 input
//length -> 입력받은 문자열 strlen으로 길이 구해 넣기
//arr[i] = (char*)malloc(sizeof(char)*length); 배열 크기만큼 메모리 할당


int getChar();
int getLength();

int main(void) {

	int inputChar = 0;
	int strMaxLength = 0;
	char inputString;
	char **pCharBuffer = NULL;

	int i = 0;
	//char 갯수 입력 받고 동적할당 // 세로크기
	inputChar = getChar();
	pCharBuffer = (char**)malloc(sizeof(char*)*inputChar);

	//문자 최대 길이 입력 받고 동적할당 //가로크기
	strMaxLength = getLength();
	for (i = 0; i < inputChar; i++)
	{
		pCharBuffer[i] = (char*)malloc(sizeof(char)*strMaxLength);
		printf("%d번째 문자열을 입력하세요\n", i + 1);
		scanf("%s", pCharBuffer[i]);
		if (strlen(pCharBuffer[i]) > strMaxLength)
		{
			printf("문자열 최대길이는 %d 입니다\n\n", strMaxLength);
			i--;
		}
	}

	putchar('\n');
	putchar('\n');

	for (i = 0; i < inputChar; i++)
	{
		printf("%d 문자열 %s\n", i + 1, pCharBuffer[i]);
		free(pCharBuffer[i]);
	}

	free(pCharBuffer);

	return 0;
}

int getChar()
{
	int inputChar = 0;

	printf("char를 몇 개 생성하시겠습니까 ? : ");
	scanf("%d", &inputChar);

	return inputChar;
}

int getLength()
{
	int inputLength = 0;

	printf("문자열 최대 길이를 입력하세요");
	scanf("%d", &inputLength);
	return inputLength;
}
