#include "stdafx.h"
#include <stdlib.h>
#include <string.h>



void main(void) {
	
	FILE *fp = NULL;

	fp = fopen("Test.txt", "w");

	fprintf(fp, "%s\n", "Test String");
	fprintf(fp, "%s\n", "Hello World");


	fclose(fp);
	system("notepad.exe test.txt");

}