
#include "stdafx.h"
#include <conio.h>

//���� 99p
int main(void) {

	char szName[32] = { 0 };
	int nAge = 0;

	printf("���̸� �Է��ϼ���. :");
	scanf_s("%d", &nAge);

	printf("�̸��� �Է��ϼ���. :");


	rewind(stdin);	//fflush�� ���� �����༭ rewind�� �����
	gets_s(szName, sizeof(szName));

	printf("%d, %s\n", nAge, szName);

	return 0;
}

