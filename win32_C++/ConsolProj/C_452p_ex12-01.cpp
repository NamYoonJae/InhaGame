#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>


//���� 452p ���� �ٽ� Ǯ���
int main(void) {

	char szBufferSrc[12] = { "TestString" };
	char szBufferDst[12] = { 0 };






	MyStrcpy(szBufferDst, sizeof(szBufferDst), szBufferSrc);
	puts(szBufferDst);

	return 0;
}