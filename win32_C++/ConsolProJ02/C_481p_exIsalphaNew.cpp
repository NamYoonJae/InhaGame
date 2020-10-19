#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>


/*

알파벳이 아닌 것이 있으면 제거하고 새로운 문자열로 만들어서 출력하는 코드작성
isalpha() 알파벳이면 정수 출력 아니면 0 출력
*/

int main(void) {

	char arrInput[128] = { 0 };
	char arrNew[128] = { 0 };
	int i = 0;
	int j = 0;

	printf("입력하세요");
	scanf("%s", arrInput);

	for (i = 0; i < strlen(arrInput); i++)
	{
		if (isalpha(arrInput[i]) != 0)
		{
			arrNew[j] = arrInput[i];
			j++;
		}
	}

	printf("%s", arrNew);

	return 0;
}
