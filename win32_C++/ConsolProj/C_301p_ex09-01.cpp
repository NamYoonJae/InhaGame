#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� 301p �������ķ� �˷��� �������� //�������� ����
int main(void) {

	int aList[5] = { 30, 40, 10, 50, 20 };
	int i = 0, j = 0, nTemp = 0;

	for (j = 0; j < 4; j++) 
	{
		for (i = j; i < 5; i++) 
		{
			if (aList[j] > aList[i]) 
			{
				nTemp = aList[i];
				aList[i] = aList[j];
				aList[j] = nTemp;
			}
		}
	}



	//��¹�
	for (i = 0; i < 5; ++i)

		printf("%d\t", aList[i]);
	putchar('\n');

}