#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//교재 575p 연습문제 2번
/*
	현재 경로에서 "TestFile.txt" 텍스트 파일을 연 후, 사용자가 입력한 문자열을 뒤에 이어서
	추가한 후 다시 저장하는 프로그램을 작성하세요

*/

void main(void) {

	FILE *fp = NULL;

	fp = fopen("TestFile.txt", "a");

	char inputString[64];
	printf("추가할 문자열을 입력하세요 : ");
	scanf("%s", inputString);
	fprintf(fp, "%s", inputString);

	fclose(fp);
}