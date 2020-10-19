#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main(void) {


	char ch;
	printf("Do you want to EXIT? (Y/N)\n");
	ch = _getch();

	if (ch == 'y' || ch == 'Y') 
	{
		puts("EXIT");
		exit(1);
	}

	puts("End of main()");
}