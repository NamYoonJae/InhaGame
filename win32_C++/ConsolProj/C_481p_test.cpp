#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

/*
���ڸ� �Է¹޾Ƽ� �� �� ���ڰ� �ƴ� ���� ���� ���ԵǾ� ������ ��� ����ϴ� �ڵ� �ۼ�.0
*/

int main(void) {

	char *inputString = NULL;
	int i = 0;
	int result = 1;
	inputString = (char*)malloc(sizeof(char) * 128);
	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%s", inputString);


	//isalpha() ���ĺ��� �ƴ϶�� 0�� ���ĺ��̶�� ������ �����Ѵ�

	for (i = 0; i < strlen(inputString); i++)
	{
		if (isalpha(inputString[i]) == 0)
		{
			printf("���ڸ� �Է� �����մϴ�.\n\n");
			free(inputString);
			return 0;
		}
	}

	free(inputString);

	return 0;
}
