#include "stdafx.h"
#include <string.h>

int main(void) {

	char szBuffer[32] = { "I am a boy" };

	printf("%p\n", szBuffer);;

	printf("%p\n", strstr(szBuffer, "am"));
	printf("%p\n", strstr(szBuffer, "boy"));

	printf("Index: %d\n", strstr(szBuffer,"am") - szBuffer);
	printf("Index: %d\n", strstr(szBuffer, "boy") - szBuffer);

	//boy �޸� ��ġ ã�� boy�޸� ��ġ�� 7
	//cat�̶� ���ڷ� �����


	char *pStr = strstr(szBuffer, "boy"); //boy�� �ּҰ� �̾ƿ�

	if (pStr != NULL) 
	{
		memcpy(pStr, "cat", 3);//boy�� 3�����̱⿡ 3����Ʈ�� �ٲٰڴٴ� ��
	}
	printf("%s",szBuffer);
	




	return 0;
}