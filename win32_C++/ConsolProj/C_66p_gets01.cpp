#include "stdafx.h"
#include <conio.h>

//���� 66p
int main(void) {

	char szname[32];	// szname ���� ũ�� 32�� ����

	int nsize = sizeof(szname); // sizeof - ������ ���� �Լ�
	printf("szname size : %d %c\n", nsize, 65);	//nsize ũ�� ��� // %c �ƽ�Ű �ڵ带 ǥ�� a�� �ƽ�Ű �ڵ� 65�̹Ƿ� ȭ�鿡�� a�� ��µȴ�


	printf("�̸��� �Է��ϼ���");

	gets_s(szname, sizeof(szname));

	printf("����� �̸���");

	puts(szname);
	puts("�Դϴ�");

	return 0;

}

