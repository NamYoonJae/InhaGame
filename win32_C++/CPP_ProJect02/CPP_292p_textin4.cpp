#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main(void) {

	int ch;
	int count = 0;

	while ((ch = cin.get()) != EOF)
	{
		cout.put(char(ch));
		++count;
	}
	cout << count << "���ڸ� �о����ϴ�.\n";

}