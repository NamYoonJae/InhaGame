#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

int GetLength(const char *pszParam) 
{
	int nLength = 0;
	while (pszParam[nLength] != '\0')
		nLength++;

	return nLength;
}


int main(int argc, char* argv[]) {

	char *pszData = "Hello";

	printf("%d\n", GetLength("hi"));
	printf("%d\n", GetLength(pszData));

	return 0;
}