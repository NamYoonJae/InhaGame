#include <stdio.h>
#include "stdafx.h"

typedef struct _USERDATA 
{
	char szName[16];
	char szPhone[16];
} USERDATA;


void main() 
{
	FILE *fp = NULL;
	USERDATA UserData = { "Ho-sung", "123-1234" };

	fp = fopen("Test.dat", "wb");
	if (fp == NULL) return;

	fwrite(&UserData, sizeof(USERDATA), 1, fp);
	fclose(fp);


}