#include "stdafx.h"
#include <iostream>
#include <string>
#include <cctype>


using namespace std;

void main(void) {

	cout << "�м��� �ؽ�Ʈ�� �Է��Ͻʽÿ�."
		"�Է��� ���� @���� ǥ���Ͻʽÿ�.\n";

	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int other = 0;

	cin.get(ch);
	while (ch !='@')
	{
		if (isalpha(ch))
			chars++;
		else if (isspace(ch))
			whitespace++;
		else if (isdigit(ch))
			digits++;
		else if (ispunct(ch))
			punct++;
		else
			other++;
		cin.get(ch);
	}

	cout << "���ĺ� ����" << chars << ", "
		<< "ȭ��Ʈ �����̽� " << whitespace << ", "
		<< "���� " << digits << ", "
		<< "������ " << punct << ", "
		<< "��Ÿ " << other << endl;
}