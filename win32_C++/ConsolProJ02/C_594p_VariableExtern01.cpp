#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void InitCounter(int nData);
void IncreaseCounter();


extern int g_nCounter;


void main(void) {

	InitCounter(10);
	printf("%d\n",g_nCounter);
	IncreaseCounter();
	printf("%d\n",g_nCounter);

}