#include <stdio.h>
#include <stdlib.h>
#include <stdafx.h>
#include <malloc.h>

/*
�Է� ���� �ڿ��� �̴�
�Է� �޴� ��� ���� �ø��� -1 �Է½� �� ���� ���Ѵ�
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

	printf("���ڸ� �Է��ϼ���.\n");
	while (1)
	{
		scanf("%d", szBuffer[x++], sizeof(szBuffer[x++]));

		if (nInput == -1) break;
		nCnt++;
		totalSum += szBuffer[x++];

		memcpy(szNewBuffer, szBuffer, _msize(szBuffer));
		free(szBuffer);


	}

	printf("nCnt ���� %d\n", nCnt);

	for (i = 0; i<nCnt; i++)
	{
		printf("szBuffer ����%d\n", szBuffer[i]);
	}

	memcpy(szNewBuffer, szBuffer, nCnt);
	free(szBuffer);

	//�����͸� ����ϴ� ���� : �޸𸮿� ���� ������ �����ϴ�
	//�����͸� ��������ν� ���纻�� �������ʰ� �ּҿ� �ٷ� �����ؼ� �޸𸮰� �������̰ų� ó���ð��� �߿��� �ý��ۿ� ���δ�.
	//�ʹ� ���̸���ũ�ε� �̷��Ա��� ���� �����ϴ� ������ ?
	//���ӻ� ���쿡 ���̾��̴��� �񱳼����� �ʿ�


	free(szNewBuffer);






}