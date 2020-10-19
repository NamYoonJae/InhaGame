#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

int main(void) {

	char szBuffer[12] = { "TestString" };
	char *pszData = "TestString";

	printf("%d\n", szBuffer == pszData);
	printf("%d\n", "TestString" == pszData);
	printf("%d\n", "DataString" == pszData);


	return 0;
}