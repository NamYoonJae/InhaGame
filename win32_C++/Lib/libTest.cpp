#include <stdio.h>
#include "stdafx.h"

void PrintData(int nParam)
{
	printf("PrintData() : %d\n",nParam);
}

void PrintString(const char* pszParam)
{
	printf("PrintData() : %s\n", pszParam);
}