#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>

//개인 과제 카페 제출하기 완료
/*
	사용자로부터 단어 하나를 입력 받은 뒤,
	그 문자열 내에 A부터 Z까지의 알파벳이 각각 몇 개씩 등장하는지 세어 출력하시오.
	대소문자는 같이 처리, 등장하지 않는 알파벳을 출력하지 않는다.
	알파벳 이외의 문자는 무시한다.
	ex) Test
		e : 1
		s : 1
		t : 1
*/

void search(char *inputString);

int main(void) {

	char *inputString = NULL;
	int cnt = 0;

	inputString = (char*)malloc(sizeof(char)*128);
	printf("문자열을 입력하세요. : ");
	scanf("%s", inputString);

	search(inputString);

	return 0;
}

void search(char *inputString) {
	int length = 0;
	int i = 0;
	char number[128] = { 0 };
	length = strlen(inputString);


	for (i = 0; i <length; i++)
	{
		inputString[i] = toupper(inputString[i]);
	}

	printf("%s\n", inputString);

	for (i = 0; i < length; i++) 
	{
		number[inputString[i]]++;
		//printf("%d\n", inputString[i]);
		//A의 아스키 코드는 65이다 
		//number[A]라면 number[65]인 경우인데 이때 A를 만날때마다 number의 65번 방의 숫자를 증가시키는 방식
		//즉, 해당 알파벳마다 각 방이 존재하며 그 방의 숫자가 그 알파벳 갯수를 뜻한다.
	}
	
	
	for (i = 'A'; i <='Z'; i++) 
	{
		if (number[i]>0) 
		printf("%c:%d\n", i, number[i]);
	}
	
	free(inputString);
}