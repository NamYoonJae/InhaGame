#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

//카페에 올리기
/*
사용자로부터 최대 10개의 단어를 입력받아 정렬하는 프로그램을 작성한다.
사전식 순서대로 작은 단어가 앞에 와야한다.
단, 각각의 단어는 15글자를 넘지 않는다고 가정한다.
입력은 소문자로만 한다.

ex>
입력 종료는 그냥 엔터를 입력하시오.
1번째 ? black
2번째 ? apple
3번째 ? block
4번째 ? <enter>

apple black block
--------------------------------------------------
문제를 풀었다면 단어 입력 10개가 아닌 임의의 수로 바꿔서 풀기
즉, 동적할당해서 풀기

*/
int lowerFilter(char inputString[][15], int nSize);

void main(void) {

	char inputString[10][15] = { 0 };

	int i = 0;
	int j = 0;
	int lower = 0;
	int loFilResult = 0;
	char temp[10];

	while (i<10)
	{
		printf("%d 문자열을 입력하세요. : ", i + 1);
		if (scanf("%[^\n]s", inputString[i]) == 0) break;
		rewind(stdin);


		if (strlen(inputString[i]) > 15)
		{
			printf("문자 길이 한도 15자 입니다\n\n");
			continue;
		}


		loFilResult = lowerFilter(inputString, 15);

		if (loFilResult == 0)
		{
			printf("소문자만 입력 가능합니다\n\n");
			continue;
		}

		i++;
	}

	//strcmp (char1, char2)
	//두 문자열이 같다면 0
	//0보다 큰 수면 string2가 string1보다 앞에 있다
	//0보다 작으면 string2가 string1보다 뒤에 있다

	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j <10; j++)
		{
			if (strcmp(inputString[i], inputString[j]) > 0)
			{

				strcpy(temp, inputString[i]);
				strcpy(inputString[i], inputString[j]);
				strcpy(inputString[j], temp);

			}
		}
	}

	for (i = 0; i <10; i++)
	{
		printf("%s\n", inputString[i]);
	}


}

int lowerFilter(char inputString[][15], int nSize)
{
	int x = 0;
	int y = 0;
	int lower = 0;
	int result = 1;

	//islower() 소문자 판별 함수
	//소문자면 정수반환 소문자가 아니면 0 반환

	for (x = 0; x < 10; x++)
	{
		for (y = 0; y <strlen(inputString[x]); y++)
		{
			lower = islower(inputString[x][y]);
			if (lower == 0)
			{
				result = 0;
				return result;
			}
		}
	}

	return result;
}
