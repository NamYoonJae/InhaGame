#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void PrintString(const char *pszParam);

void main(void) {

	char szBuffer[32] = { "I am a boy." };

	PrintString(szBuffer);
	PrintString("You are a girl");

}

void PrintString(const char *pszParam) 
{
	puts(pszParam);

}