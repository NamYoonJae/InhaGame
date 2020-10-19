#include "stdafx.h"
#include <iostream>
#include <string>


/*
	게임에서 비밀번호에 어떤 법칙을 요구하는 경우가 있다.
	다음과 같이 비밀번호를 만들어야 한다고 하자.
	1. 비밀번호는 적어도 8개의 문자여야 한다.
	2. 비밀번호는 문자와 숫자로만 구성되어야한다.
	3. 비밀번호는 적어도 두 개의 숫자가 포함되어야한다.
	사용자가 비밀번호를 입력했을 때 위 법칙에 맞으면 "valid password"를
	그렇지 않으면 "invalid password"를 출력하는 프로그램을 작성하라.

*/

using namespace std;

void main(void) {

	char inputPassword[20];
	int passwordLength = 0;
	int i = 0;
	int passwordNumCount = 0;

	cout << "비밀번호를 입력하세요 : ";
	cin >> inputPassword;

	passwordLength = strlen(inputPassword);
	
	while (1)
	{
		if (passwordLength < 8)
		{
			cout << "비밀번호는 적어도 8자 이상이여야 합니다" << endl;
			break;
		}

		for (i = 0; i < passwordLength; i++)
		{
			if (isdigit(inputPassword[i]) != 0 && isalpha(inputPassword[i]) != 0)
			{
				cout << "비밀번호는 문자와 숫자로만 구성되어야합니다" << endl;
				break;
			}

			if (isdigit(inputPassword[i]) == true)
			{
				passwordNumCount++;
			}
		}

		if (passwordNumCount <2)
		{
			cout << "적어도 두 개 이상의 숫자를 입력해야합니다" << endl;
			break;
		}
	}

}