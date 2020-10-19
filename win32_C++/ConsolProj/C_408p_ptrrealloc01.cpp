#include "stdafx.h"
#include <string.h>
#include <malloc.h>

int main(void) {

	char * pszBuffer = NULL, *pszNewBuffer = NULL;


	pszBuffer = (char*)malloc(12);

	sprintf(pszBuffer, "%s", "TestString");

	printf("[%p] %d %s\n", pszBuffer, _msize(pszBuffer), pszBuffer);

	pszNewBuffer = (char*)realloc(pszBuffer, 32);	
	//realloc�� �������� �� ���� �ּҸ� ���´� 
	//���� �޸𸮰� �����Ͽ� ���ο� ������ ���� �̵���Ų�ٸ� �ּҴ� ���� �ٸ����̴� -> å���� �ϴ� ���µ� �����ϰ� ���߿� �ذ��� ����ϱ�
	if (pszNewBuffer == NULL)
		free(pszBuffer);

	sprintf(pszNewBuffer, "%s", "TestStringData");

	printf("[%p] %d %s\n", pszNewBuffer, _msize(pszNewBuffer), pszNewBuffer);

	free(pszNewBuffer);

	return 0;
}