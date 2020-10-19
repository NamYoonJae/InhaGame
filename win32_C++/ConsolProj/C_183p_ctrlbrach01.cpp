
#include "stdafx.h"
#include <conio.h>


//교재 183p if문
int main(void) {

	int nAge = 0;

	printf("나이를 입력하세요 : ");
	scanf("%d", &nAge);

	if (nAge >= 20)
		printf("당신의 나이는 %d세입니다.\n", nAge);

	puts("End");

	return 0;

}

