#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main(void) {
	
	int input = 0;
	int count = 0;

	cout << "양의 정수를 입력하세요" << endl;
	cin >> input;


	if (input < 0)
	{
		cout << "양의 정수가 아닙니다" << endl;
	}
	else
	{
		while (1)
		{
			count++;
			input = input / 10;
			
			if (input == 0) 
			{
				break;
			}

		}

		cout << count << "자리입니다" << endl;
	}
	

}