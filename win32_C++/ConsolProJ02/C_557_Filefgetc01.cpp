#include <stdio.h>
#include "stdafx.h"

void main()
{
	FILE *fp = NULL;
	char ch;

	fp = fopen("Test.txt", "w");
	fputs("Test string!", fp);
	fclose(fp);

	fp = fopen("Test.txt", "r");
	if (fp == NULL)
		return;

	while ((ch = fgetc(fp)) != EOF)
		putchar(ch);
	fclose(fp);
}