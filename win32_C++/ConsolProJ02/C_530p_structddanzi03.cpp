#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct UserData 
{
	char szName[32];
	char szPhone[32];

	struct UserData *pNext;
} UserData;


void main(void) {

	UserData user1 = {"±è¾îÁØ", "1234", NULL};
	UserData user2 = {"Á¤ºÀÁÖ", "6666", NULL};
	UserData user3 = {"ÁÖÁø¿ì","3333", NULL};

	user1.pNext = &user2;
	user2.pNext = &user3;
	UserData* pUser = &user1;

	while (pUser != NULL) 
	{
		printf("%s %s \n", pUser->szName, pUser->szPhone);
		pUser = pUser->pNext;
	}

}