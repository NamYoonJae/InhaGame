#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//�׳� ����
int main(void) {

	/*
		���� �ڵ带 �̿� �������� ���� ���·� ��µǵ��� ���α׷��� �ۼ�.
		char* string [2] = {"I Love C", "Hello World"};

		��� >
			I Love C world


	*/

	char* string[2] = { "I Love C", "Hello World" };
	
	printf("%s", string[0]);
	printf("%s", string[1] + 5);



	return 0;
}