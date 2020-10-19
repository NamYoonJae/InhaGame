#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

/*
문자를 입력받아서 그 중 문자가 아닌 숫자 들이 포함되어 있으면 경고를 출력하는 코드 작성.0
*/

int main(void) {

	char *inputString = NULL;
	int i = 0;
	int result = 1;
	inputString = (char*)malloc(sizeof(char) * 128);
	printf("문자를 입력하세요 : ");
	scanf("%s", inputString);


	//isalpha() 알파벳이 아니라면 0을 알파벳이라면 정수를 리턴한다

	for (i = 0; i < strlen(inputString); i++)
	{
		if (isalpha(inputString[i]) == 0)
		{
			printf("문자만 입력 가능합니다.\n\n");
			free(inputString);
			return 0;
		}
	}

	free(inputString);

	return 0;
}
