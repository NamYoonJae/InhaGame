#include "stdafx.h"
#include <conio.h>
#include <windows.h>

void InitList(int*pList, int nSize)
{
	int i = 0;
	for (i = 0; i < nSize; ++i) 
	{
		printf("������ �Է��ϼ��� : ");
		scanf("%d", &pList[i]);
	}
}

void sortList(int *pList, int nSize)
{
	int i = 0, j = 0, nTmp = 0;

	for (i = 0; i<nSize -1; ++i)
		if (pList[j]<pList[i]) 
		{
			nTmp = pList[j];
			pList[j] = pList[i];
			pList[i] = nTmp;
		}

}

void PrintList(int *pList, int nSize)
{
	int i = 0;
	for (i=0; i<nSize; ++i) 
		printf("%d\t", pList[i]);
			putchar('\n');
}



int main(void) {

	int aList[5] = { 0 };

	InitList(aList, 5);
	sortList(aList, 5);
	PrintList(aList, 5);

	return 0;
}