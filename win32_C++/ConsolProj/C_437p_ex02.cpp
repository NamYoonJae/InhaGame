#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//교재 437p 2번문제 카페 제출하기

void GetLength(char *input);

int main(void) {

	char *input = NULL;
	input = (char*)malloc(sizeof(char)*128);
	printf("문자열을 입력하시오. : ");
	scanf("%s", input);

	GetLength(input);

	return 0;
}

void GetLength(char *input) {
	int i = 0;
	while (input[i] != '\0')
		i++;

	printf("%d\n",i);

}