#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
	프로그램 상에서 파일 99.txt 를 만들어서 이 파일에 구구단을 저장하는 프로그램을 작성하라.
	fprintf()함수를 이용할 것

	-fseek() 함수를 이용해서 원하는 단의 내용만 찾아서 출력하는 프로그램을 작성하라.

*/



void main(void) {

	FILE * fp = NULL;
	FILE * fp2 = NULL;
	int i = 0;
	int j = 0;
	int input = 0;
	char szBuffer[32];
	/*
	int num1, num2, num3;
	char ch1, ch2;
	*/
	fp = fopen("99.txt","w");

	
	if (fp == NULL)
	{
		printf("fp 실행 실패");
		return;
	}

	for (i = 2; i < 10; i++) 
	{
		for (j = 1; j < 10; j++) 
		{
			fprintf(fp, "%d * %d = %2d\n", i, j, i*j);
		}
	}

	fclose(fp);

	printf("원하는 단을 입력하세요 : ");
	scanf("%d",&input);

	fp = fopen("99.txt", "r");

	fseek(fp, (input-2)*12*9, SEEK_CUR);

	for (i = 0; i < 9; i++) 
	{
		fprintf(stdout, "%s\n", fgets(szBuffer, sizeof(szBuffer), fp));
	}

	//system("notepad.exe 99.txt");


}