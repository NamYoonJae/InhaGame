#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>


//���� 437p 4�� ���� ī�� �����ϱ� 
int getLngth(char *input);
void myStrrev(char *input, int length, char *result);

int main(void) {

	char *input = NULL;
	char * result = NULL;

	input = (char*)malloc(sizeof(char)*128);

	printf("���ڸ� �Է����ֽÿ�. : ");
	scanf("%s", input);

	int length = getLngth(input);

	result = (char*)malloc(sizeof(char)*length + 1);
	myStrrev(input, length, result);

	return 0;
}

int getLngth(char *input)
{
	int i = 0;
	while (input[i] != '\0')
	{
		i++;
	}

	return i;
}

void myStrrev(char *input, int length, char *result){

	int i = 0;
	int x = 0;
	//input �迭 length-1 ���� 0���� �����鼭 result[0]���� ������ �ȴ�
	printf("input �� %s\n", input);
	printf("length �� %d\n", length);

	result[length] = '\0';
	for (i = length-1 ; i > -1; i-- ) 
	{
		result[x++] = input[i];
	}
	
	printf("%s", result);


}