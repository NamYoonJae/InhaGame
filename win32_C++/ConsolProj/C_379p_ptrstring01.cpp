#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//±³Àç 379p
int main (void){

	char szBuffer[16] = {"Hello"};

	char *pszData = szBuffer;
	int nLength = 0;

	while (*pszData != '\0')
	{
		pszData++;
		nLength++;
	}

	printf("Length : %d\n", nLength);
	printf("Length : %d\n", strlen(szBuffer));
	printf("Length : %d\n", strlen("world"));

	return 0;
}