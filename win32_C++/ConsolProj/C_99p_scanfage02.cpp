
#include "stdafx.h"
#include <conio.h>

//교재 99p
int main(void) {

	char szName[32] = { 0 };
	int nAge = 0;

	printf("나이를 입력하세요. :");
	scanf_s("%d", &nAge);

	printf("이름를 입력하세요. :");


	rewind(stdin);	//fflush를 지원 안해줘서 rewind를 사용함
	gets_s(szName, sizeof(szName));

	printf("%d, %s\n", nAge, szName);

	return 0;
}

