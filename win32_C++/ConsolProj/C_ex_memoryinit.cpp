#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
#include <malloc.h>
#include <string.h>

/*
�Է°����� �̸� �������� �ʰ� ���ڸ� �Է¹޾Ƽ�
���ڸ� �Է¹��� ������ �޸𸮸� �÷����鼭 ó���ϴ� �ڵ带
�̿��� ���α׷��� §��.�Է¹޴� ���ڴ� �ڿ����̸�,
-1�� �ԷµǸ� �Է¹��� ���ڵ�� �� ���� ����ϰ� ���α׷��� �����Ѵ�.
*/

void nInput();

int main(void) {

	nInput();

	return 0;
}

void nInput() {

	int i = 0;
	int x = 0;
	int totalSum = 0;
	int nInput = 0;

	int  *szBuffer = NULL;
	int *szNewBuffer = NULL;
	int nCnt = 0;


	szBuffer = (int*)malloc(sizeof(int));
	szNewBuffer = (int*)malloc(sizeof(int));


	printf("���ڸ� �Է��ϼ���\n");
	while (1)
	{

		scanf_s("%d", &szBuffer[i], sizeof(szBuffer[i]));

		if (szBuffer[i] == -1) break;

		totalSum += szBuffer[i];

		memcpy(szNewBuffer, szBuffer, _msize(szBuffer)); //szBuffer�� szNewBuffer�� ����
		free(szBuffer); //szBuffer �Ҵ� ����


		//���� ���� ���� �߰��� ���� �� �ְ� �޸� ��ĭ �� Ű���� �ٽ� �Ҵ��ϱ�
		szBuffer = (int*)malloc(sizeof(int) * (i + 2));
		memset(szBuffer, 0, _msize(szBuffer));

		//���� ���� �޸� ũ�� �ø� ���� �ٽ� �����ϱ�
		memcpy(szBuffer, szNewBuffer, _msize(szNewBuffer));
		free(szNewBuffer);

		//szNewBuffer �޸� ũ�� Ű���� �ٽ� �Ҵ�
		szNewBuffer = (int*)malloc(sizeof(int) * (i + 2));
		memset(szNewBuffer, 0, _msize(szNewBuffer));

		nCnt++;
		i++;

	}

	printf("�Է��� ���� ");
	for (i = 0; i < nCnt; i++)
	{
		printf(" %d ", szBuffer[i]);
	}
	putchar('\n');

	printf("�� ���� %d �Դϴ�\n", totalSum);

	if (szBuffer != NULL) free(szBuffer);
	if (szNewBuffer != NULL) free(szNewBuffer);

}