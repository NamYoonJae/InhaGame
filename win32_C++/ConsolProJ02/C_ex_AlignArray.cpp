#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

//ī�信 �ø���
/*
����ڷκ��� �ִ� 10���� �ܾ �Է¹޾� �����ϴ� ���α׷��� �ۼ��Ѵ�.
������ ������� ���� �ܾ �տ� �;��Ѵ�.
��, ������ �ܾ�� 15���ڸ� ���� �ʴ´ٰ� �����Ѵ�.
�Է��� �ҹ��ڷθ� �Ѵ�.

ex>
�Է� ����� �׳� ���͸� �Է��Ͻÿ�.
1��° ? black
2��° ? apple
3��° ? block
4��° ? <enter>

apple black block
--------------------------------------------------
������ Ǯ���ٸ� �ܾ� �Է� 10���� �ƴ� ������ ���� �ٲ㼭 Ǯ��
��, �����Ҵ��ؼ� Ǯ��

*/
int lowerFilter(char inputString[][15], int nSize);

void main(void) {

	char inputString[10][15] = { 0 };

	int i = 0;
	int j = 0;
	int lower = 0;
	int loFilResult = 0;
	char temp[10];

	while (i<10)
	{
		printf("%d ���ڿ��� �Է��ϼ���. : ", i + 1);
		if (scanf("%[^\n]s", inputString[i]) == 0) break;
		rewind(stdin);


		if (strlen(inputString[i]) > 15)
		{
			printf("���� ���� �ѵ� 15�� �Դϴ�\n\n");
			continue;
		}


		loFilResult = lowerFilter(inputString, 15);

		if (loFilResult == 0)
		{
			printf("�ҹ��ڸ� �Է� �����մϴ�\n\n");
			continue;
		}

		i++;
	}

	//strcmp (char1, char2)
	//�� ���ڿ��� ���ٸ� 0
	//0���� ū ���� string2�� string1���� �տ� �ִ�
	//0���� ������ string2�� string1���� �ڿ� �ִ�

	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j <10; j++)
		{
			if (strcmp(inputString[i], inputString[j]) > 0)
			{

				strcpy(temp, inputString[i]);
				strcpy(inputString[i], inputString[j]);
				strcpy(inputString[j], temp);

			}
		}
	}

	for (i = 0; i <10; i++)
	{
		printf("%s\n", inputString[i]);
	}


}

int lowerFilter(char inputString[][15], int nSize)
{
	int x = 0;
	int y = 0;
	int lower = 0;
	int result = 1;

	//islower() �ҹ��� �Ǻ� �Լ�
	//�ҹ��ڸ� ������ȯ �ҹ��ڰ� �ƴϸ� 0 ��ȯ

	for (x = 0; x < 10; x++)
	{
		for (y = 0; y <strlen(inputString[x]); y++)
		{
			lower = islower(inputString[x][y]);
			if (lower == 0)
			{
				result = 0;
				return result;
			}
		}
	}

	return result;
}
