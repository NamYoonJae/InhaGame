#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
int filter(char *inputString);

void main(void) {
	//97~122 �� �ҹ���
	char *inputString = NULL;
	char *inputArray = NULL;
	int i = 0;
	int inStrLength = 0;
	int filterResult = 0;
	int length = 0;
	int key;
	inputString = (char*)malloc(sizeof(char));
	inputArray = (char*)malloc(sizeof(char));
	
	while (i<10)
	{
		printf("���ڸ� �Է��ϼ���.: ");
		scanf("%s", inputString);
		length = strlen(inputString);
		

		filterResult  = filter(inputString);
		i++;

		if (filterResult == 0) 
		{
			printf("�ҹ��ڸ� �Է� �����մϴ�.\n\n");
			i--;
		}
		else if (filterResult == 2) 
		{
			printf("15���ڱ����� �Է� �����մϴ�.\n\n");
			i--;
		}


	}




	
		


}

int filter(char * inputString)
{
	int i = 0;
	int length = 0;

	length = strlen(inputString);
	int filterResult = 0;

	if (length < 16) 
	{
		for (i = 0; i < length; i++)
		{
			if (inputString[i] >= 'a' && inputString[i] <= 'z')
			{
				filterResult = 1;
			}
			else
			{
				filterResult = 0;
				return filterResult;
			}
		}
	}
	else
	{
		filterResult = 2;
		return filterResult;
	}

	return filterResult;
}
