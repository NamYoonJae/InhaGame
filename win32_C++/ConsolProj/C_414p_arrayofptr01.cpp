#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>


//±³Àç 414p
int main(void) {

	char *astList[3] = { "Hello","World","Strin" };


	printf("%s\n", astList[0]); // = *(astList+0)
	printf("%s\n", astList[1]);
	printf("%s\n", astList[2]);

	printf("%s\n", astList[0] + 1);// = *(astList + 0) + 1
	printf("%s\n", astList[1] + 2);
	printf("%s\n", astList[2] + 3);

	printf("%c\n", astList[0][3]);// = *(*(astList + 0) + 1)
	printf("%c\n", astList[1][3]);
	printf("%c\n", astList[2][3]);

	return 0;
}