#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main(void) {
	
	int input = 0;
	int count = 0;

	cout << "���� ������ �Է��ϼ���" << endl;
	cin >> input;


	if (input < 0)
	{
		cout << "���� ������ �ƴմϴ�" << endl;
	}
	else
	{
		while (1)
		{
			count++;
			input = input / 10;
			
			if (input == 0) 
			{
				break;
			}

		}

		cout << count << "�ڸ��Դϴ�" << endl;
	}
	

}