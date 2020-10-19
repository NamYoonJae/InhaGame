#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const char * file = "guests.txt";

void main(void) {

	char ch;

	ifstream fin;
	fin.open(file);

	if (fin.is_open()) 
	{
		cout << file << "������ ���� ������ ������ �����ϴ�:\n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}

	ofstream fout(file, ios_base::out | ios_base::app);
	if (!fout.is_open()) 
	{
		cerr << "����� ����" << file << "������ �� �� �����ϴ�. \n";
		exit(EXIT_FAILURE);
	}

	cout << "���ο� �մ� �̸����� �Է��Ͻʽÿ�(�������� �� �� �Է�):\n";
	string name;
	while (getline(cin,name) && name.size() > 0)
	{
		fout << name << endl;
	}
	fout.close();

	fin.clear();
	fin.open(file);
	if (fin.is_open()) 
	{
		cout << file << " ������ ������ ������ ������ �����ϴ�:\n";
		while (fin.get(ch))
			cout << ch;
		fin.close();

	}
	cout << "���α׷��� �����մϴ� \n";



}