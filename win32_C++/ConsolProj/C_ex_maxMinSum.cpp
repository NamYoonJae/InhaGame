#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� ����
/*
int aList[5] = {0};
scanf("%d",&aList[2])

���̰� 7�� int�� �迭�� �����ϰ�, ����ڷκ��� �� 7���� ������ �Է¹޾�
1. �Էµ� ���� �� �ִ�
2. �Էµ� ���� �� �ּڰ�
3. �Էµ� ������ �� ��
*/

int main(void) {

	int aList[7] = { 0 };
	int i = 0;
	int nMax = 0;
	int nSum = 0;

	for (i = 0; i < 7; i++) 
	{
		scanf("%d", &aList[i]);
		
	}

	for (i = 0; i < 7; i++) 
	{
		nSum += aList[i];

		if (aList[i] > nMax)
		{
			nMax = aList[i];
		}

		else if (aList[i] < aList[0])
		{
			aList[0] = aList[i];
		}
	}

	printf("�ִ��� %d\n", nMax);
	printf("�ּڰ��� %d\n", aList[0]);
	printf("�� ����  %d\n", nSum);


	return 0;
}