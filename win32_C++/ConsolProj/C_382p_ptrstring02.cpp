#include "stdafx.h"
#include <conio.h>
#include <windows.h>

int main(void) {

	char szBuffer[16] = { "Hello" };

	char *pszData = szBuffer;

	while (*pszData != '\0')

		pszData++;

	//���ڰ� ����� �ּҿ��� �����ּҸ� ���� ���ڿ��� ���̸� �˼��ִ�.
	printf("Length : %d\n", pszData - szBuffer);
	

	return 0;
}