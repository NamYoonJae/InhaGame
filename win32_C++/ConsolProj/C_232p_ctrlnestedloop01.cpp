#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//±³Àç 232p while¹®
int main(void) {

	int i = 0, j = 0;

	i = 2;
	while (i <= 9)
	{
		j = 1;
		while (j<=9)
		{
			printf("%d * %d = %d\n", i, j, i*j);
			++j;
		}

		putchar('\n');
		++i;
	}


	return 0;
}