#include "stdafx.h"
#include <conio.h>
#include <windows.h>


//���� 277p
/*
	\0�� ����ؾ��ϴ� ����
	1. ���� ���� �ȿ� \0�� ���ٸ�. ��ĩ ���� ������ �߻��� �� �ִ�.
	2. ���α׷��Ӱ� ����ؾ��� �迭�� ũ��� �� �����̴�.
	������ ������� �Է��� �� �����̴�. �� ���� ������ �� NULL���ڴ� �����ڰ� �Ǿ��ش�
*/
int main(void) {

	char szBuffer[32] = { 0 };
	int nLength = 0;

	//�̸��� �Է¹޾� ���ۿ� �����Ѵ�.
	printf("Input your name : ");
	gets_s(szBuffer);

	//�迭�� ���ۺ��� '\0'�� ���ö����� ��� �������� �ѱ�� Ȯ���Ѵ�
	while (szBuffer[nLength] != '\0')
		nLength++;

	printf("Your name is %s(%d). \n", szBuffer, nLength);

	return 0;

}