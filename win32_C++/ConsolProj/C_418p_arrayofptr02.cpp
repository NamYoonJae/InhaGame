#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[]) {

	int i = 0;

	for (i = 0; i < argc; ++i)

		puts(argv[i]);

	puts("END");

	return 0;
}