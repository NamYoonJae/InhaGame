#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� ���� ī�� ����
/*
ȭ���� ����� ��ɾ�
#include <windows.h>
system("cls"); C���� ����
_tsystem("cls"); C++���� ����

_kbhit(); //Ű���尡 ���ȴ��� üũ���ִ� //�Լ� �Է��� ������ 1 ������ 0�� ���
getch(): //���۸� ���� ��ɾ�
Sleep(); //�ý����� ��� �����ִ� ��ɾ�

Ű���� ĥ ������
H e l l o
e l l o   H
l l o   H e
*/

int main(void) {

	char szBuffer[7] = { 'H','e','l','l','o',' ','\0' };
	int i = 0;
	char temp;

	printf("%s\n", szBuffer);
	Sleep(1000);

	while (1)
	{
		system("cls");
		temp = szBuffer[0];

		for (i = 0; i < 5; i++)
		{
			szBuffer[i] = szBuffer[i + 1];
		}

		szBuffer[5] = temp;
		printf("%s\n", szBuffer);

		Sleep(1000);
		system("cls");

	}

	return 0;
}