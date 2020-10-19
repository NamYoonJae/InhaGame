#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

void main(void) {

	char input;
	int consonantCount = 0; //자음
	int vowelCount = 0; //모음
	int other = 0; //기타
	char buffer[100];
	//a e i o u //모음
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

	cout << "자음으로 시작 : " << consonantCount << endl;
	cout << "모음으로 시작 : " << vowelCount << endl;
	cout << "기타 : " << other << endl;


}