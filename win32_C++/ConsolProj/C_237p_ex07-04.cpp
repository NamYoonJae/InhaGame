#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� 237p �ʼ� �ǽ� ���� 07-04

int main(void) {

	int nInput = 0;
	int i = 1;
	int result = 0;

	scanf("%d", &nInput);

	if (nInput < 0) 
	{
		printf("ERROR\n");
	}
	else if (nInput > 0) 
	{
		while (i < 10)
		{
			result = nInput * i;
			printf("%d * %d = %d\n", nInput, i, result);
			i++;
		}
	
	}

	return 0;
}