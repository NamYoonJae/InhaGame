#include "stdafx.h"
#include <iostream>
#include <string>

/*
	ȸ�� �Ҽ�(palindromeic prime)
	�Ųٷ� �о �Ҽ��� �Ǵ� �Ҽ��� ���Ѵ�
	2~1000 ������ ȸ�� �Ҽ��� ����ϴ� ���α׷��� �ۼ�
*/
using namespace std;

void main(void)
{

	//�Ҽ��� ���Ѵ�
	//���� �����ؼ� ��
	//���ؼ� ������ ���
	int i = 0;
	int j = 0;
	int count = 0;
	string changeString;
	string cpy;
	int cpyLength = 0;
	int  temp;

	for (i = 2; i < 1001; i++)
	{
		count = 0;

		for (j = 1; j <= i; j++)
		{
			if (i%j == 0)
			{
				count++;
			}
		}

		if (count == 2)
		{
			cout << i << endl; //�Ҽ���

			//cout << i << endl; //�Ҽ���
			changeString = to_string(i);
			cpy = changeString;
			cpyLength = cpy.length();
			for (i = 0; i < cpyLength / 2; i++)
			{
				temp = cpy[i];
				cpy[i] = cpy[cpy.length() - 1 - i];
				cpy[cpy.length() - 1 - i] = temp;
			}

			if (changeString == cpy)
			{
				cout << changeString << endl;
			}

		}


	}



}