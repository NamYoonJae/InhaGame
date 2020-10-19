#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

void main(void) {

	char szBuffer[128] = { "nData = x+ y;\nnResult = a * b" };

	char *pszSep = "*+=;\n";
	char *pszToken = NULL;

	pszToken = strtok(szBuffer, pszSep);

	while (pszToken != NULL)
	{
		puts(pszToken);

		pszToken = strtok(NULL, pszSep);

	}

	printf("\nszBuffer : %s\n", szBuffer);


}