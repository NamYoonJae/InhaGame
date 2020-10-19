#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct USERDATA 
{
	int nAge;
	char szName[32];
	char szPhone[32];
} USERDATA;

void main(void) {

	USERDATA *pUser = NULL;

	pUser = (USERDATA*)malloc(sizeof(USERDATA));

	pUser->nAge = 10;
	strcpy(pUser->szName, "Hoon");
	strcpy(pUser->szPhone, "9876");

	printf("%d»ì\t%s\t\%s\n",
		pUser->nAge, pUser->szName, pUser->szPhone);

	free(pUser);

}