#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� 306p ��������
/*
���� ���İ����� ���� ������� �ڸ��� �ٷ� ��ȯ�ϴ°� �ƴ� �ε����� ���� ��
���� ���õ� �ε����� ���� ���̶� ���ϰ� �� ������ ������ �װ��� �ε����� ����
�񱳰� ���� �� ���� �ε����� ���� ���� �ε����� ��ȯ
*/
int main() {

	int aList[5] = { 30, 40, 10, 50, 20 };
	int i = 0;
	int j = 0;
	int nTemp = 0;
	int nMinIndex = 0;


	for (j =0; j < 4; j++) 
	{
		nMinIndex = j;	//���� ���õ� �迭�� �ε��� ���� nMinIndex�� ����
		for (i = j + 1; i < 5; i++)	//���� ���õ� �ε����� ������ ������ �� �ε��� ��

			if (aList[nMinIndex] > aList[i])	//���� ���� �ε��� ���� �� ������
				nMinIndex = i;	//���� �ε��� ���� nMinIndex�� ����

		//���� �ε����� �� ������ nMinIndex�� ���������״� j�� nMin���� �ٸ��� �ȴ�
		//�׷��� ���� ���� �ʴٸ� ���� �ε��� ���� �� ��������̴�.

		if (nMinIndex != j) 
		{
			nTemp = aList[nMinIndex];
			aList[nMinIndex] = aList[j];
			aList[j] = nTemp;
		}

	}
	//��¹�
	for (i = 0; i < 5; ++i)

		printf("%d\t", aList[i]);
	putchar('\n');


	

}