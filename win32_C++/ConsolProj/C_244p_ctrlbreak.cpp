#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� 244p break��
int main(void) {
	
	int i = 0;

	for (i = 0; i < 10; ++i) 
	{
		if (i > 4)
			break;
		printf("%dth\n", i);
	}

	printf("END : i == %d\n", i);

}