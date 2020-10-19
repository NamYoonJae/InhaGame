#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

void main(void) {

	wchar_t *pwszData = L"String";

	char szData[32];
	size_t nConverted = 0;

	nConverted = wcstombs(NULL, pwszData, 32);
	printf("%d\n",nConverted);

	nConverted = wcstombs(szData, pwszData, 32);

	printf("%s (%d)\n", szData, nConverted);

}