
#include "stdafx.h"
#include <conio.h>

//���� 185p ����� ������
//�������� if���� ����Ͽ� ��� ���� �����ϱ�

int main(void) {

	int num = 0;

	scanf("%d", &num);

	if (num < 0)
		printf("�����Դϴ�\n", num);

	if (num > 0)
		printf("����Դϴ�\n", num);

	return 0;
}

