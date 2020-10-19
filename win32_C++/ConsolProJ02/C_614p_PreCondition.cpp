#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MYUNICODE

#ifdef MYUNICODE
typedef wchar_t TCHAR;
#define _T(string) L##string
#define PRINT	wprintf

#else
typedef char TCHAR;
#define _T(string)string
#define PRINT	printf

#endif


void main(void) {

	TCHAR szData[16] = _T("Test string");
	PRINT(_T("%s\n"), szData);
	PRINT(_T("%d,%d\n"), sizeof(TCHAR), sizeof(szData));
}