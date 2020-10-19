#include "stdafx.h"
#include <iostream>
#include <fstream>

const int SIZE = 60;

using namespace std;

void main(void) {

	char filename[SIZE];
	ifstream inFile;
	cout << "������ ������ �̸��� �Է��Ͻÿ� : ";
	cin.getline(filename, SIZE);
	inFile.open(filename);
	if (!inFile.is_open()) 
	{
		cout << filename << "������ �� �� �����ϴ�." << endl;
		cout << "���α׷��� �����մϴ�" << endl;
		exit(EXIT_FAILURE);
	}

	double value;
	double sum = 0.0;
	int count = 0;

	inFile >> value;
	while (inFile.good())
	{
		++count;
		sum += value;
		inFile >> value;
	}

	if (inFile.eof())
		cout << "������ ���� �����߽��ϴ�.\n";
	else if (inFile.fail())
		cout << "������ ����ġ�� �Է��� ����Ǿ����ϴ�.\n";
	else
		cout << "�� �� ���� ������ �Է��� ����Ǿ����ϴ�.\n";
	if (count == 0)
		cout << "�����Ͱ� �����ϴ�.\n";
	else
	{
		cout << "���� �׸��� ����: " << count << endl;
		cout << "�հ� : " << sum << endl;
		cout << "��� : " << sum / count << endl;
	}
	inFile.close();
}