#include "stdafx.h"
#include <iostream>
#include <string>
#include <cctype>


using namespace std;

void main(void) {

	cout << "분석할 텍스트를 입력하십시오."
		"입력의 끝을 @으로 표시하십시오.\n";

	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int other = 0;

	cin.get(ch);
	while (ch !='@')
	{
		if (isalpha(ch))
			chars++;
		else if (isspace(ch))
			whitespace++;
		else if (isdigit(ch))
			digits++;
		else if (ispunct(ch))
			punct++;
		else
			other++;
		cin.get(ch);
	}

	cout << "알파벳 문자" << chars << ", "
		<< "화이트 스페이스 " << whitespace << ", "
		<< "숫자 " << digits << ", "
		<< "구둣점 " << punct << ", "
		<< "기타 " << other << endl;
}