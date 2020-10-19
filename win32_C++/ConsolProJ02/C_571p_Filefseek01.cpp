#include <stdio.h>
#include "stdafx.h"
#include <stdlib.h>



void main() 
{
	FILE *fp = NULL;
	/*
	fp = fopen("Test.dat", "rb");

	fseek(fp, 0, SEEK_END);

	printf("size of Test.dat : %u\n", ftell(fp));
	*/

	fp = fopen("seek.txt", "r");

	fprintf(fp, "%s", "ABCDEFGHIJ");
	
	
	fseek(fp, 0, SEEK_SET);
	fprintf(stdout, "%c\n", fgetc(fp));
	
	fseek(fp, 2, SEEK_SET);
	fprintf(stdout, "%c\n", fgetc(fp));

	fseek(fp, -1, SEEK_END);
	fprintf(stdout, "%c\n", fgetc(fp));

	fseek(fp, -2, SEEK_END);
	fprintf(stdout, "%c\n", fgetc(fp));
	

	fclose(fp);
	//system("notepad.exe seek.txt");

}