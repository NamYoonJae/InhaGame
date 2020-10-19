#include "stdafx.h"
#include <string.h>

int main(void) {

	char szBuffer[32] = { "I am a boy" };

	printf("%p\n", szBuffer);;

	printf("%p\n", strstr(szBuffer, "am"));
	printf("%p\n", strstr(szBuffer, "boy"));

	printf("Index: %d\n", strstr(szBuffer,"am") - szBuffer);
	printf("Index: %d\n", strstr(szBuffer, "boy") - szBuffer);

	//boy 메모리 위치 찾기 boy메모리 위치는 7
	//cat이란 문자로 덮어쓰기


	char *pStr = strstr(szBuffer, "boy"); //boy의 주소값 뽑아옴

	if (pStr != NULL) 
	{
		memcpy(pStr, "cat", 3);//boy가 3글자이기에 3바이트를 바꾸겠다는 뜻
	}
	printf("%s",szBuffer);
	




	return 0;
}