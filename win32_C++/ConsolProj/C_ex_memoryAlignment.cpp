#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
#include <malloc.h>
#include <string.h>

//���ΰ��� ī�信 �ø���
/*
Q. �Է� ������ �������� ���� ���¿���
-1�� �Է��� ������ �Է��� ��� ������ ����ϰ�,
�������� Ȥ�� ���������� ������� �������� Ȥ�� ������������
������ ��� ������ �ٽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
* ����) �ݵ�� �����Ϳ� �޸� �Ҵ��� �̿��ؼ� ���α׷��� �����ؾ� �մϴ�.
*/




int main(void) {

	int *szBuffer = NULL;
	int i = 0;
	int j = 0;
	int nCnt = 0;
	int temp = 0;

	szBuffer = (int*)malloc(sizeof(int));

	while (1)
	{
		printf("���ڸ� �Է��ϼ���\n");
		scanf_s("%d", &szBuffer[i], sizeof(szBuffer[i]));

		if (szBuffer[i] == -1) break;

		realloc(szBuffer, sizeof(int)*(i + 2));

		i++;
		nCnt++;

	}

	printf("�Է��� ���� ");
	for (i = 0; i < nCnt; i++)
	{
		printf("%d, ", szBuffer[i]);
	}
	putchar('\n');


	//��������
	for (i = 0; i < nCnt; i++)
	{
		for (j = i + 1; j < nCnt; j++)
		{
			if (szBuffer[i] > szBuffer[j])
			{
				temp = szBuffer[i];
				szBuffer[i] = szBuffer[j];
				szBuffer[j] = temp;
			}

		}
	}

	printf("�������� ���� : ");
	for (i = 0; i < nCnt; i++)
	{
		printf("%d, ", szBuffer[i]);
	}

	free(szBuffer);
	return 0;
}