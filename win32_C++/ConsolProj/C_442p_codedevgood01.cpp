#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//442~445p ��ģ�����̴� �ٽ��غ��� (�Է� ������ ����
/*
1. line43 �� �ִ� aList[]�� *pList �� �ٲ� ��
2. InitList �Լ�
	2.1 �Է¹޴´�� �޸� ���Ҵ��ϰ� ũ�⸦ ����ϴ� ���·� �ٲٱ�
	2.2 ���� �Է�, ���� ������ �޵����ϰ� ������ �ԷµǸ� ����
3. �� �Լ� ȣ�� �� �� ��° ���� 5�� ������ �ٲپ� �� ��

*/


int InitList(int *pList, int nSize);
void SortList(int *pList, int nSize);
void printList(int *pList, int nSize);


int main(void) {

	int *pList = (int*)malloc(sizeof(int));
	int nSize = 0;

	nSize = InitList(pList, nSize);
	SortList(pList, nSize);
	printList(pList, nSize); //�Ѱ��� ���� �ּҰ��� �Ѱ�����Ѵ�

	return 0;
}

int InitList(int *pList, int nSize) {

	int i = 0;
	int x = 0;
	while (1) {

		printf("������ �Է��ϼ��� : ");
		scanf("%d", &pList[i]); // i 0���� ����
		if (pList[i] < 0) break;

		i++;// i �ϳ� ����
		pList = (int*)realloc(pList, sizeof(int)*(i+1));// pList�� ������ sizeof(int)*i��ŭ �÷��ְڴٴ� �� 
														// ���� 41��°���� i�������� �����ڸ�
														// �׸��� �̾� �ٿ����ϴϱ� �����ڸ��� +1�� �ؾ��Ѵ�
		
		
		nSize++;
	}
	return nSize;
}

void SortList(int *pList, int nSize) {

	int i = 0, j = 0, nTmp = 0;

	for (i = 0; i <nSize; ++i) 
	{
		for (j = i + 1; j < nSize; ++j) 
			if(pList[j] < pList[i])
		{
				nTmp = pList[j];
				pList[j] = pList[i];
				pList[i] = nTmp;
		}
	}

}

void printList(int *pList, int nSize) {
	
	int i = 0;
	for (i = 0; i < nSize; ++i)
		printf("%d\t", pList[i]);
	putchar('\n');
	
}