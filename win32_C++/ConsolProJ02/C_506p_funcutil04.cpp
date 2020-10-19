#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main(void) {


	int i = 0;
	srand((unsigned)time(NULL)); //현재 시간이 계속 흘러가니 시간 값은 계속 변한다
	//srand(1) 로 하면 같은 시간이 나온다

	for (i = 0; i < 10; i++) 
		printf("%6d\n", rand());

	for (i = 0; i < 10; i++)
	{
		printf("%6d\n", rand() % 10);
	}

}