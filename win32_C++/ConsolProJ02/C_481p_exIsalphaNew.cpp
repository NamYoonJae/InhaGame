#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>


/*

���ĺ��� �ƴ� ���� ������ �����ϰ� ���ο� ���ڿ��� ���� ����ϴ� �ڵ��ۼ�
isalpha() ���ĺ��̸� ���� ��� �ƴϸ� 0 ���
*/

int main(void) {

	char arrInput[128] = { 0 };
	char arrNew[128] = { 0 };
	int i = 0;
	int j = 0;

	printf("�Է��ϼ���");
	scanf("%s", arrInput);

	for (i = 0; i < strlen(arrInput); i++)
	{
		if (isalpha(arrInput[i]) != 0)
		{
			arrNew[j] = arrInput[i];
			j++;
		}
	}

	printf("%s", arrNew);

	return 0;
}
