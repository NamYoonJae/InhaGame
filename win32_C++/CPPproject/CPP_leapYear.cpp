#include "stdafx.h"
#include <iostream>
#include <string>

/*
	윤년을 계산하는 프로그램을 작성하라.
	4로 나누어 떨어지면서 100으로는 나누어 떨어지지 않거나, 400으로 나누어 떨어지는 해는 윤년이다

*/


using namespace std;

void main(void) {

	int input = 0;

	cout << "년도를 입력하세요 : " << endl;
	cin >> input;

	if (input%4 == 0) 
	{

		if (input *100 % 100 == 0) 
		{

			if (input * 100 % 400 == 0)
			{
				cout << "윤년입니다." << endl;
			}
			else
			{
				cout << "윤년이 아닙니다" << endl;
			}

		}
		else
		{
			cout << "윤년이 아닙니다" << endl;
		}
	}
	else
	{
		cout << "윤년이 아닙니다" << endl;
	}


}