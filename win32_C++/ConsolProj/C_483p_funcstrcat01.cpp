#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//±³Àç 483p
int main(void) {

	char szPath[128] = {"C:\\Program Files\\"};
	char szBuffer[128] = { 0 };

	printf("Input path : ");
	gets_s(szBuffer);

	strcat(szPath, szBuffer);
	puts(szPath);

	return 0;
}