#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

//±³Àç 387p
int main(void) {

	int *pList = NULL, *pNewList = NULL;

	int aList[3] = { 0 };

	pList = (int*)malloc(sizeof(int) * 3);
	memset(pList, 0, sizeof(int) * 3);
	pNewList = (int*)calloc(3, sizeof(int));

	free(pList);
	free(pNewList);

	return 0;
}