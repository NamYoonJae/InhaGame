#include "stdafx.h"
#include <conio.h>

//���� 89p

//���̿� �̸��� �Է¹޾� �� ������ ����ϴ� ���α׷�
int main(void) {

	char name[32] = { 0 };
	int nAge;

	printf("�̸��� �Է��ϼ���. : ");
	gets_s(name);

	printf("���̸� �Է��ϼ��� : ");
	scanf("%d%*c", &nAge);

	printf("����� ���̴� %d�� �̰� �̸��� '%s'�Դϴ�\n", nAge, name);

	return 0;
}

