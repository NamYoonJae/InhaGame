#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� 225p �ʼ��ǽ����� 07-01
int main(void) {

	int nInput = 0;
	int i = 0;

	scanf("%d", &nInput);

	if (1 > nInput) //���� �Է��� ���� �������
		nInput = 1; //1�� ����

	else if (nInput > 10) //���� �Է��� ���� 10 �ʰ���
		nInput = 9; //9�� ����

	while (nInput>i) //�Է��� �� > i �� ������
	{
		putchar('*');
		i++;
	}

	putchar('\n');

	return 0;
}