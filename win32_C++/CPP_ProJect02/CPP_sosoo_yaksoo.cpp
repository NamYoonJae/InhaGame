#include "stdafx.h"
#include <iostream>
#include <cmath>

/*
	�Ҽ� => ����� 1�� �ڽŸ��� ������ ��
	��� => � ���� �������� �� ������ ���������ϴ� �ڿ���

	2�� 1000 ���̿� �����ϴ� ��� �Ҽ��� ����ϴ� ���α׷��� �ۼ��϶�.
*/
using namespace std;

void main(void) {

	int num = 2;
	int i = 0;
	int numList[1000];

	for (i = 2; i < 1000; i++)
	{
		numList[i] = num;
		num++;
	}

	for (num = 2; num < 1000; num++) 
	{
		for (i = 2; i <1000; i++)
		{
			if (num % i == 0 && num!=i)
			{
				numList[num] = 0;
			}
		}
	}

	for (i = 2; i < 1000; i++) 
	{
		if (numList[i] != 0) 
		{
			cout << numList[i] << endl;
		}

	}
	
}