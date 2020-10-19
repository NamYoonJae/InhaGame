#include "stdafx.h"
#include <conio.h>
#include <windows.h>

int nInput = 100;

void TestFunc(void)
{
	printf("TestFunc() : %d\n", nInput);

}


int main(void) 
{

	int nInput = 0;
	printf("%d\n", nInput);
	{
		int nInput = 20;
		printf("%d\n",nInput);
	}
	TestFunc();
	return 0;
}