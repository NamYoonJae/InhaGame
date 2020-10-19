#include "stdafx.h"
#include "strngbad.h"
#include <iostream>

using namespace std;
int stringbad::num_strings = 0;

stringbad::stringbad()
{
	//num_strings++;
	//cout << "Constructor Object Count" << num_strings <<endl;
	len = 4;
	str = new char[4];
	strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str << "\"叼弃飘 按眉积己\n";

}


stringbad::~stringbad()
{
	//num_strings--;
	//cout << "Constructor Object Count" << num_strings << endl;

	cout << "\"" << str << "\"按眉颇鲍, ";
	--num_strings;
	cout << "巢篮 按眉 荐 : " << num_strings << "\n";
	delete[] str;
}

stringbad::stringbad(const char * s)
{
	len = strlen(s);
	str = new char(len + 1);
	strcpy(str, s);
	num_strings++;
	cout << num_strings << " : \"" << str << "\ 按眉 积己\n";

}

std::ostream & operator<<(std::ostream & os, const stringbad & st)
{
	os << st.str;
	return os;
}
