#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//���� 438p ���� ī�信 �ø���
/*
char*�� �� �� �������� �Է� �ޱ�
�Է��� ���ڿ� �ִ� ���� �Է¹ޱ�

�׸��� char*�� �Է��� ��ŭ �����Ҵ�
���ڿ� ���̸�ŭ �� �� �ִ� �����Ҵ��ؼ� �Է¹��� ���ڿ� ����
�� �� ���

*/


//char�� � ���� �Է��ϱ� input
//length -> �Է¹��� ���ڿ� strlen���� ���� ���� �ֱ�
//arr[i] = (char*)malloc(sizeof(char)*length); �迭 ũ�⸸ŭ �޸� �Ҵ�


int getChar();
int getLength();

int main(void) {

	int inputChar = 0;
	int strMaxLength = 0;
	char inputString;
	char **pCharBuffer = NULL;

	int i = 0;
	//char ���� �Է� �ް� �����Ҵ� // ����ũ��
	inputChar = getChar();
	pCharBuffer = (char**)malloc(sizeof(char*)*inputChar);

	//���� �ִ� ���� �Է� �ް� �����Ҵ� //����ũ��
	strMaxLength = getLength();
	for (i = 0; i < inputChar; i++)
	{
		pCharBuffer[i] = (char*)malloc(sizeof(char)*strMaxLength);
		printf("%d��° ���ڿ��� �Է��ϼ���\n", i + 1);
		scanf("%s", pCharBuffer[i]);
		if (strlen(pCharBuffer[i]) > strMaxLength)
		{
			printf("���ڿ� �ִ���̴� %d �Դϴ�\n\n", strMaxLength);
			i--;
		}
	}

	putchar('\n');
	putchar('\n');

	for (i = 0; i < inputChar; i++)
	{
		printf("%d ���ڿ� %s\n", i + 1, pCharBuffer[i]);
		free(pCharBuffer[i]);
	}

	free(pCharBuffer);

	return 0;
}

int getChar()
{
	int inputChar = 0;

	printf("char�� �� �� �����Ͻðڽ��ϱ� ? : ");
	scanf("%d", &inputChar);

	return inputChar;
}

int getLength()
{
	int inputLength = 0;

	printf("���ڿ� �ִ� ���̸� �Է��ϼ���");
	scanf("%d", &inputLength);
	return inputLength;
}
