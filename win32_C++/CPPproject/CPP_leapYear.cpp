#include "stdafx.h"
#include <iostream>
#include <string>

/*
	������ ����ϴ� ���α׷��� �ۼ��϶�.
	4�� ������ �������鼭 100���δ� ������ �������� �ʰų�, 400���� ������ �������� �ش� �����̴�

*/


using namespace std;

void main(void) {

	int input = 0;

	cout << "�⵵�� �Է��ϼ��� : " << endl;
	cin >> input;

	if (input%4 == 0) 
	{

		if (input *100 % 100 == 0) 
		{

			if (input * 100 % 400 == 0)
			{
				cout << "�����Դϴ�." << endl;
			}
			else
			{
				cout << "������ �ƴմϴ�" << endl;
			}

		}
		else
		{
			cout << "������ �ƴմϴ�" << endl;
		}
	}
	else
	{
		cout << "������ �ƴմϴ�" << endl;
	}


}