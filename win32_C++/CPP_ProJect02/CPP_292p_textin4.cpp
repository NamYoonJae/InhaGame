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
	cout << count << "문자를 읽었습니다.\n";

}