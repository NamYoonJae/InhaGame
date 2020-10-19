#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

//±³Àç 392p
int main() {

	char szBuffer[12] = { "HelloWolrd" };
	char szNewBuffer[12] = { 0 };

	memcpy(szNewBuffer, szBuffer, 4);
	puts(szNewBuffer);

	memcpy(szNewBuffer, szBuffer, 6);
	puts(szNewBuffer);

	memcpy(szNewBuffer, szBuffer, sizeof(szBuffer));
	puts(szNewBuffer);

	return 0;
}