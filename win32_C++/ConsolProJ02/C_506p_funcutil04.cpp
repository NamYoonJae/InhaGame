#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main(void) {


	int i = 0;
	srand((unsigned)time(NULL)); //���� �ð��� ��� �귯���� �ð� ���� ��� ���Ѵ�
	//srand(1) �� �ϸ� ���� �ð��� ���´�

	for (i = 0; i < 10; i++) 
		printf("%6d\n", rand());

	for (i = 0; i < 10; i++)
	{
		printf("%6d\n", rand() % 10);
	}

}