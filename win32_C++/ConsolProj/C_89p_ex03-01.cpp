#include "stdafx.h"
#include <conio.h>

//교재 89p

//나이와 이름을 입력받아 한 행으로 출력하는 프로그램
int main(void) {

	char name[32] = { 0 };
	int nAge;

	printf("이름을 입력하세요. : ");
	gets_s(name);

	printf("나이를 입력하세요 : ");
	scanf("%d%*c", &nAge);

	printf("당신의 나이는 %d세 이고 이름은 '%s'입니다\n", nAge, name);

	return 0;
}

