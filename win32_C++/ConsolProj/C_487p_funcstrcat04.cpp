#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//���� 487p �ٽ� �ڵ� �ٽ��غ��� ���� ����
char *mystrcat(char *pszDst, char *pszSrc) {

	while (*pszDst != '\0')
		++pszDst;

	while (*pszSrc != '\0')
		*pszDst++ = *pszSrc++;

	*++pszDst = '\0';

	return --pszDst = '\0';

}


int main(void) {

	char szPath[128] = { 0 };
	char *pszEnd = NULL;

	pszEnd = mystrcat(szPath, "C:\\Program File\\");
	pszEnd = mystrcat(pszEnd, "CHS\\");
	pszEnd = mystrcat(pszEnd, "C programing");

	puts(szPath);


	return 0;
}