#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main(void) {

	cout.fill('*');
	const char * staff[2] = { "������", "�ڼ���" };
	long bonus[2] = { 900, 1350 };

	for (int i = 0; i < 2; i++)
	{
		cout << staff[i] << ": $";
		cout.width(7);
		cout << bonus[i] << endl;
	}
	

}