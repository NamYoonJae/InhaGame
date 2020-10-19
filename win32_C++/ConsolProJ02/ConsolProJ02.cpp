#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

struct USERDATA
{
	int nAge;
	char szName[32];
	char szPhone[32];
};

void main(void) {

	struct USERDATA user = { 0, "","" };
	
	user.nAge = 10;
	strcpy(user.szName, "Hoon");
	strcpy(user.szName, "010,1234,1234");

	printf("%d »ì, %s, %s\n", user.nAge, user.szName, user.szPhone);

}
