#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

void main(void) {

	char input;
	int consonantCount = 0; //����
	int vowelCount = 0; //����
	int other = 0; //��Ÿ
	char buffer[100];
	//a e i o u //����
	cin >> buffer;


	while (strcmp("q",buffer) != 0)
	{
		if (isalpha(buffer[0]) == 0)
		{
			++other;
		}
		else
		{
			if (buffer[0] == 'a')
			{
				++vowelCount;
			}
			else if (buffer[0] == 'e')
			{
				++vowelCount;
			}
			else if (buffer[0] == 'i')
			{
				++vowelCount;
			}
			else if (buffer[0] == 'o')
			{
				++vowelCount;
			}
			else if (buffer[0] == 'u')
			{
				++vowelCount;
			}
			else
			{
				++consonantCount;
			}
		}
		cin >> buffer;
	}

	cout << "�������� ���� : " << consonantCount << endl;
	cout << "�������� ���� : " << vowelCount << endl;
	cout << "��Ÿ : " << other << endl;


}