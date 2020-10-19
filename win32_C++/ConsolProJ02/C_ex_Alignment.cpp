#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
int filter(char *inputString);

void main(void) {
	//97~122 가 소문자
	char *inputString = NULL;
	char *inputArray = NULL;
	int i = 0;
	int inStrLength = 0;
	int filterResult = 0;
	int length = 0;
	int key;
	inputString = (char*)malloc(sizeof(char));
	inputArray = (char*)malloc(sizeof(char));
	
	while (i<10)
	{
		printf("문자를 입력하세요.: ");
		scanf("%s", inputString);
		length = strlen(inputString);
		

		filterResult  = filter(inputString);
		i++;

		if (filterResult == 0) 
		{
			printf("소문자만 입력 가능합니다.\n\n");
			i--;
		}
		else if (filterResult == 2) 
		{
			printf("15글자까지만 입력 가능합니다.\n\n");
			i--;
		}


	}




	
		


}

int filter(char * inputString)
{
	int i = 0;
	int length = 0;

	length = strlen(inputString);
	int filterResult = 0;

	if (length < 16) 
	{
		for (i = 0; i < length; i++)
		{
			if (inputString[i] >= 'a' && inputString[i] <= 'z')
			{
				filterResult = 1;
			}
			else
			{
				filterResult = 0;
				return filterResult;
			}
		}
	}
	else
	{
		filterResult = 2;
		return filterResult;
	}

	return filterResult;
}
