#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

int main(void) {

	char szBuffer[12] = { "TestString" };
	char *pszData = "TestString";

	printf("%d\n", memcmp(szBuffer, pszData, 10));

	printf("%d\n", memcmp("teststring", pszData, 10));

	printf("%d\n", memcmp("DataString", pszData, 10));




	return 0;
}