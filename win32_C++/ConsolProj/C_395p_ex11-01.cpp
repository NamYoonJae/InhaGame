#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

// ���� 395p �ʼ� �ǽ� ���� 11-01
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