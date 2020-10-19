#include "stdafx.h"
#include <iostream>
#include <string>

/*
	회문 소수(palindromeic prime)
	거꾸로 읽어도 소수가 되는 소수를 뜻한다
	2~1000 범위의 회문 소수를 출력하는 프로그램을 작성
*/
using namespace std;

void main(void)
{

	//소수를 구한다
	//각각 복사해서 비교
	//비교해서 같으면 출력
	int i = 0;
	int j = 0;
	int count = 0;
	string changeString;
	string cpy;
	int cpyLength = 0;
	int  temp;

	for (i = 2; i < 1001; i++)
	{
		count = 0;

		for (j = 1; j <= i; j++)
		{
			if (i%j == 0)
			{
				count++;
			}
		}

		if (count == 2)
		{
			cout << i << endl; //소수들

			//cout << i << endl; //소수들
			changeString = to_string(i);
			cpy = changeString;
			cpyLength = cpy.length();
			for (i = 0; i < cpyLength / 2; i++)
			{
				temp = cpy[i];
				cpy[i] = cpy[cpy.length() - 1 - i];
				cpy[cpy.length() - 1 - i] = temp;
			}

			if (changeString == cpy)
			{
				cout << changeString << endl;
			}

		}


	}



}