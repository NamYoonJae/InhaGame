#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void main(void) {

	string inputString;
	string temp;
	int i = 0;

	cout << "문자를 입력하세요: " << endl;
	cin >> inputString;
	cout << endl;
	/*
	for (i = 0; i < inputString.size(); i++) 
	{
		if (inputString[i] == 'a' && inputString[i+1] == 'b') 
		{
			inputString[i] = '*';
			inputString[i+1] = '*';
		}
	}

	for (i = 0; i < inputString.size(); i++) 
	{
		cout << inputString[i];
	}
	*/

	
	if (inputString.find("ab") >= 0) 
	{
		int num1 = inputString.find("ab");
		inputString[num1] ='*';
		inputString[num1+1] ='*';
	};

	for (i = 0; i < inputString.size(); i++)
	{
		cout << inputString[i];
	}
	
}