#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

// 교재 395p 필수 실습 문제 11-01
int main(void) {
	
	char szBuffer[12] = { "HelloWorld" };
	char *pszData = NULL;

	pszData = (char*)malloc(sizeof(char) * 12);
	//pszData = szBuffer;
	memcpy(pszData, szBuffer, 12);
	puts(pszData);

	free(pszData);


	return 0;
}