#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>

//���� ���� ī�� �����ϱ� �Ϸ�
/*
	����ڷκ��� �ܾ� �ϳ��� �Է� ���� ��,
	�� ���ڿ� ���� A���� Z������ ���ĺ��� ���� �� ���� �����ϴ��� ���� ����Ͻÿ�.
	��ҹ��ڴ� ���� ó��, �������� �ʴ� ���ĺ��� ������� �ʴ´�.
	���ĺ� �̿��� ���ڴ� �����Ѵ�.
	ex) Test
		e : 1
		s : 1
		t : 1
*/

void search(char *inputString);

int main(void) {

	char *inputString = NULL;
	int cnt = 0;

	inputString = (char*)malloc(sizeof(char)*128);
	printf("���ڿ��� �Է��ϼ���. : ");
	scanf("%s", inputString);

	search(inputString);

	return 0;
}

void search(char *inputString) {
	int length = 0;
	int i = 0;
	char number[128] = { 0 };
	length = strlen(inputString);


	for (i = 0; i <length; i++)
	{
		inputString[i] = toupper(inputString[i]);
	}

	printf("%s\n", inputString);

	for (i = 0; i < length; i++) 
	{
		number[inputString[i]]++;
		//printf("%d\n", inputString[i]);
		//A�� �ƽ�Ű �ڵ�� 65�̴� 
		//number[A]��� number[65]�� ����ε� �̶� A�� ���������� number�� 65�� ���� ���ڸ� ������Ű�� ���
		//��, �ش� ���ĺ����� �� ���� �����ϸ� �� ���� ���ڰ� �� ���ĺ� ������ ���Ѵ�.
	}
	
	
	for (i = 'A'; i <='Z'; i++) 
	{
		if (number[i]>0) 
		printf("%c:%d\n", i, number[i]);
	}
	
	free(inputString);
}