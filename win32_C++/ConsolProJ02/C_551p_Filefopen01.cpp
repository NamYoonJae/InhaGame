#include <stdio.h>
#include "stdafx.h"

//������ �󿡴� �� ���� ���Ͽ� �ؽ�Ʈ ������ �����ȴ�
//�׷��� �� ����� ����� ������ ���������� �ִµ� �װ��� �����ϸ� �ٷ� �� ���(����װ��)�� �����ȴ�.
void main() 
{
	FILE *fp = NULL;
	FILE *fp2 = NULL;
	FILE *fp3 = NULL;

	fp = fopen("Test.txt", "w");
	fp2 = fopen("Test2.txt", "w");
	fp3 = fopen("Test3.txt", "w");


	if (fopen == NULL) 
	{
		puts("Error : Failed to open file!");
			return;
	}

	//fclose;

	//���� 552p
	//���� ���� ���� ����غ���
	int nClose = fcloseall();
	printf("Count : %d\n", nClose);



}