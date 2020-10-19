#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>


//교재 437p 4번 문제 카페 제출하기 
int getLngth(char *input);
void myStrrev(char *input, int length, char *result);

int main(void) {

	char *input = NULL;
	char * result = NULL;

	input = (char*)malloc(sizeof(char)*128);

	printf("문자를 입력해주시오. : ");
	scanf("%s", input);

	int length = getLngth(input);

	result = (char*)malloc(sizeof(char)*length + 1);
	myStrrev(input, length, result);

	return 0;
}

int getLngth(char *input)
{
	int i = 0;
	while (input[i] != '\0')
	{
		i++;
	}

	return i;
}

void myStrrev(char *input, int length, char *result){

	int i = 0;
	int x = 0;
	//input 배열 length-1 부터 0까지 돌리면서 result[0]부터 넣으면 된다
	printf("input 값 %s\n", input);
	printf("length 값 %d\n", length);

	result[length] = '\0';
	for (i = length-1 ; i > -1; i-- ) 
	{
		result[x++] = input[i];
	}
	
	printf("%s", result);


}