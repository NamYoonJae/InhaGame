#include "stdafx.h"
#include <iostream>
#include <string>


/*
	���ӿ��� ��й�ȣ�� � ��Ģ�� �䱸�ϴ� ��찡 �ִ�.
	������ ���� ��й�ȣ�� ������ �Ѵٰ� ����.
	1. ��й�ȣ�� ��� 8���� ���ڿ��� �Ѵ�.
	2. ��й�ȣ�� ���ڿ� ���ڷθ� �����Ǿ���Ѵ�.
	3. ��й�ȣ�� ��� �� ���� ���ڰ� ���ԵǾ���Ѵ�.
	����ڰ� ��й�ȣ�� �Է����� �� �� ��Ģ�� ������ "valid password"��
	�׷��� ������ "invalid password"�� ����ϴ� ���α׷��� �ۼ��϶�.

*/

using namespace std;

void main(void) {

	char inputPassword[20];
	int passwordLength = 0;
	int i = 0;
	int passwordNumCount = 0;

	cout << "��й�ȣ�� �Է��ϼ��� : ";
	cin >> inputPassword;

	passwordLength = strlen(inputPassword);
	
	while (1)
	{
		if (passwordLength < 8)
		{
			cout << "��й�ȣ�� ��� 8�� �̻��̿��� �մϴ�" << endl;
			break;
		}

		for (i = 0; i < passwordLength; i++)
		{
			if (isdigit(inputPassword[i]) != 0 && isalpha(inputPassword[i]) != 0)
			{
				cout << "��й�ȣ�� ���ڿ� ���ڷθ� �����Ǿ���մϴ�" << endl;
				break;
			}

			if (isdigit(inputPassword[i]) == true)
			{
				passwordNumCount++;
			}
		}

		if (passwordNumCount <2)
		{
			cout << "��� �� �� �̻��� ���ڸ� �Է��ؾ��մϴ�" << endl;
			break;
		}
	}

}