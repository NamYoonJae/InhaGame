#include "stdafx.h"
#include <string.h>
#include <malloc.h>

int main(void) {

	char * pszBuffer = NULL, *pszNewBuffer = NULL;


	pszBuffer = (char*)malloc(12);

	sprintf(pszBuffer, "%s", "TestString");

	printf("[%p] %d %s\n", pszBuffer, _msize(pszBuffer), pszBuffer);

	pszNewBuffer = (char*)realloc(pszBuffer, 32);	
	//realloc을 성공했을 떄 같은 주소를 같는다 
	//만약 메모리가 부족하여 새로운 공간에 값을 이동시킨다면 주소는 서로 다를것이다 -> 책에는 일단 없는데 주의하고 나중에 해결방법 모색하기
	if (pszNewBuffer == NULL)
		free(pszBuffer);

	sprintf(pszNewBuffer, "%s", "TestStringData");

	printf("[%p] %d %s\n", pszNewBuffer, _msize(pszNewBuffer), pszNewBuffer);

	free(pszNewBuffer);

	return 0;
}