#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n = 0;

void Start();

void main(void) 
{
	
	Start();

}

void Start()
{
	string words[] = { "internet", "developer","library" };
	string temp;
	int i = 0;
	char input;
	char * in = &input;
	cout << "��� ���� �����մϴ�" << endl;

	for (i= 0; i < words[n].length(); i++)
	{
		temp.push_back('*');
	}

	cout << temp << endl;
	cout << endl << endl;

	cout << "�Է� >";
	cin >> input;

	
	for (i = 0; i <words[n].length(); i++) 
	{

		if (strcmp(words[n].c_str(), in) == 0)
		{
			temp[i] = input;
		}
	}

	cout << temp << endl;
}
