#include "stdafx.h"
#include <stdlib.h>
#include <string.h>



void main(void) {

	int nData = 0;
	char szBuffer[128] = { 0 };
	FILE *fp = NULL;

	fp = fopen("fscanfTest.txt", "w");
	fprintf(fp, "%d,%s\n", 20, "Test");
	fclose(fp);

	fp = fopen("fscanfTest.txt", "r");
	fscanf(fp, "%d,%s", &nData, szBuffer);
	fclose(fp);

	printf("%d, %s\n", nData, szBuffer);


}