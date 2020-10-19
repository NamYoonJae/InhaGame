#include "stdafx.h"
#include <conio.h>
#include <windows.h>

int main(void) {

	char szBuffer[16] = { "Hello" };

	char *pszData = szBuffer;

	while (*pszData != '\0')

		pszData++;

	//문자가 저장된 주소에서 시작주소를 빼면 문자열의 길이를 알수있다.
	printf("Length : %d\n", pszData - szBuffer);
	

	return 0;
}