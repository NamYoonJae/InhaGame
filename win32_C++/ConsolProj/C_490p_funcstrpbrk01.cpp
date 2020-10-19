#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

void main(void) {


	char szBuffer[128] = { 0 };
	char szSet[128] = { 0 };
	char *pszStart = szBuffer;

	printf("Input string : ");
	gets_s(szBuffer);

	printf("Input character set : ");
	gets_s(szSet);

	while ((pszStart = strpbrk(pszStart, szSet)) != NULL) 
	{
		printf("[%p] Index : %d, %c\n", pszStart, pszStart - szBuffer, *pszStart);

		pszStart++;
	}
	
}