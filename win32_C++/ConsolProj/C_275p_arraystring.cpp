#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� 275p
int main(void) {
	
	int aList[5] = { 30, 40, 10, 50, 20 };
	char szBuffer[6] = { 'H','e','l','l','o','\0', };
	//\0�� ������ ���� ��Ÿ����.
	//e�� \0�� �ڸ��� �ٲٸ� H�� ��µȴ�.

	char szData[8] = {"Hello"};
	char *pszBuffer = "Hello";

	puts(szBuffer);
	puts(szData);
	puts(pszBuffer);

	return 0;

}