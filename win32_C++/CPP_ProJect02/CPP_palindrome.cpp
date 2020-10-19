#include "stdafx.h"
#include <iostream>
#include <string>

/*
	문자열을 앞에서부터 읽으나 뒤에서부터 읽으나 동인한 경우를
	palindrome(회문) 이라고 한다.
	문자열을 입력받아 회문인지 판단하고 결과를 출력하는 프로그램을 작성하라.

	ex> ""mom "dad" "noon" "sos"
*/

using namespace std;

void main(void) {

	string inputString;
	string cpy;
	string ch;
	int n = 0;
	int temp = 0;

	cout << "문자열을 입력하세요 : ";
	getline(cin, inputString);

	n = inputString.length() / 2;
	cpy = inputString;

	cout << endl;

	for (int i= 0; i<n;i++) 
	{
		temp = cpy[i];
		cpy[i] = cpy[cpy.length()-1 -i];
		cpy[cpy.length() - i - 1] = temp;
	}


	if (inputString == cpy) 
	{
		cout << "회문입니다" << endl;
	}
	else
	{
		cout << "회문이 아닙니다" << endl;
	}
	

}