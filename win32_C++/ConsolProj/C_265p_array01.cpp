#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 265p 배열
int main(void) {

	int aList[5] = { 0 };
	int i = 0;

	for (i = 0; i < 5; ++i)
		scanf("%d", &aList[i]);

	for (i = 0; i < 5; ++i)
		printf("%d\n", aList[i]);

	return 0;
}