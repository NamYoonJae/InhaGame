#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//���� 437p 2������ ī�� �����ϱ�

void GetLength(char *input);

int main(void) {

	char *input = NULL;
	input = (char*)malloc(sizeof(char)*128);
	printf("���ڿ��� �Է��Ͻÿ�. : ");
	scanf("%s", input);

	GetLength(input);

	return 0;
}

void GetLength(char *input) {
	int i = 0;
	while (input[i] != '\0')
		i++;

	printf("%d\n",i);

}