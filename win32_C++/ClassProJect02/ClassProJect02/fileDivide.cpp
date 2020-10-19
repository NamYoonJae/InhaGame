#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

/*
	Q1. ���� ���� ��� ����Ʈ�� 5�� ���ϵ��� ������ ��ȣȭ(encoding) �Ͽ���.
		����ڰ� �Է� ���� �̸��� ��� ���� �̸��� �Է��ϸ� 
		�Է� ������ ��ȣȭ�� ������ ��� ���Ϸ� �����ϴ� ���α׷��� �ۼ��϶�.


	Q2. ��ȣȭ�� ������ ��ȣȭ(decoding)�ϴ� ���α׷��� �ۼ��϶�.
		����ڰ� �Է� ���� �̸��� ��� ���� �̸��� �Է��ϸ� 
		�Է� ������ ��ȣ�� Ǯ�� ������ ��� ���Ͽ� �����϶�.


*/

using namespace std;

void main(void) {


	string inFileName;
	string outFileName;
	char temp;

	/*
	cout << "�Է� ���� �̸� �Է�: ";
	cin >> inFileName;
	cout << endl;

	cout << "��� ���� �̸� �Է�: ";
	cin >> outFileName;
	cout << endl;

	
	fstream fp1;
	fp1.open(inFileName, ios_base::in | ios_base::out);

	ofstream fp2;
	fp2.open(outFileName, ios_base::out);

	if (!fp1.is_open()) 
	{
		cout << "fp1 ���� ���� ����" << endl;
		exit(EXIT_FAILURE);
	}

	if (!fp2.is_open())
	{
		cout << "fp2 ���� ���� ����" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "��ȣȭ ����" << endl;
	while (fp1.get(temp))
	{
		cout << "temp: " << temp << endl;
		temp = temp + 5;
		cout << "��ȣȭ �� temp: "<< temp << endl;
		fp2.put(temp);
	}
	cout << "��ȣȭ �Ϸ�" << endl;

	fp1.close();
	fp2.close();
	*/

	cout << "��ȣȭ �� ���� �̸� �Է�: ";
	cin >> outFileName;
	cout << endl;

	cout << "��ȣȭ �� ���� �̸� �Է�: ";
	cin >> inFileName;
	cout << endl;

	fstream fp2;
	fp2.open(outFileName, ios_base::in | ios_base::out);

	ofstream fp1;
	fp1.open(inFileName, ios_base::out);

	if (!fp1.is_open())
	{
		cout << "fp1 ���� ���� ����" << endl;
		exit(EXIT_FAILURE);
	}

	if (!fp2.is_open())
	{
		cout << "fp2 ���� ���� ����" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "��ȣȭ ����" << endl;
	while (fp2.get(temp))
	{
		cout << "temp: " << temp << endl;
		temp = temp - 5;
		cout << "��ȣȭ �� temp: " << temp << endl;
		fp1.put(temp);
	}
	cout << "��ȣȭ �Ϸ�" << endl;

	fp2.close();
	fp1.close();
}