#include "stdafx.h"
#include <iostream>
#include <string>

/*
	���ڿ��� �տ������� ������ �ڿ������� ������ ������ ��츦
	palindrome(ȸ��) �̶�� �Ѵ�.
	���ڿ��� �Է¹޾� ȸ������ �Ǵ��ϰ� ����� ����ϴ� ���α׷��� �ۼ��϶�.

	ex> ""mom "dad" "noon" "sos"
*/

using namespace std;

void main(void) {

	string inputString;
	string cpy;
	string ch;
	int n = 0;
	int temp = 0;

	cout << "���ڿ��� �Է��ϼ��� : ";
	getline(cin, inputString);

	n = inputString.length() / 2;
	cpy = inputString;

	cout << endl;

	for (int i= 0; i<n;i++) 
	{
		temp = cpy[i];
		cpy[i] = cpy[cpy.length()-1 -i];
		cpy[cpy.length() - i - 1] = temp;
	}


	if (inputString == cpy) 
	{
		cout << "ȸ���Դϴ�" << endl;
	}
	else
	{
		cout << "ȸ���� �ƴմϴ�" << endl;
	}
	

}