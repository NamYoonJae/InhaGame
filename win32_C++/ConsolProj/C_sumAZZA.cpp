#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//개인 과제
/*
	A Z
+	Z A
-----------
	9 9
*/

int main(void) {
	
	int x = 0;
	int y = 0;

	int A = 0;
	int Z = 0;

	int AZ;
	int ZA;

	int nInput = 0;

	scanf("%d", &nInput);

	for (x = 0; x < 10; x++) 
	{
		for (y = 0; y < 10; y++) 
		{
			AZ = x * 10 + y;
			ZA = y * 10 + x;

			if (AZ+ZA == nInput) 
			{
				printf("%d %d\n", x, y);
			}
		}
	}



	return 0;
}