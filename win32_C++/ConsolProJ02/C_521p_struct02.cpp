#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef  struct USERDATA
{
	int nAge;
	char szName[32];
	char szPhone[32];

} USERDATA;

void main(void) {

	USERDATA user = { 0, "", "" };

	user.nAge = 10;
	strcpy(user.szName, "Hoon");
	strcpy(user.szPhone, "010-1234-1234");

	printf("%d »ì, %s, %s\n", user.nAge, user.szName, user.szPhone);
}