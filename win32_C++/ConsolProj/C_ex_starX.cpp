#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� X��� �� ����ϱ� ����
int main(void) {

	int x = 0;
	int y = 0;
	int z = 0;

	int nInput = 0;

	printf("���ڸ� �Է��Ͻÿ�");
	scanf("%d", &nInput);

	for (x = 0; x < nInput; x++) 
	{
		for (y = 0; y < nInput; ++y) 
		{
			if (x == y)
			{
				printf("*");
			}

			else if (nInput == x + y + 1)
			{
				printf("*");
			}

			else
				printf("  ");

		}

		printf("\n");
	}


}