#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void main(void) {

	const char * state1 = "Florida";
	const char * state2 = "Kansas";
	const char * state3 = "Euphoria";
	int len = strlen(state2);
	cout << "���� �ε��� ���� : \n";
	int i;
	for (i = 1; i <=len; i++) 
	{
		cout.write(state2, i);
		cout << endl;
	}

	cout << "���� �ε��� ����: \n";
	for (i = len; i > 0; i--)
		cout.write(state2, i) << endl;

	cout << "���ڿ� ���� �ʰ� : \n";
	cout.write(state2, len + 5) << endl;

}