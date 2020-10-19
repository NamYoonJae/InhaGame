#pragma once
#include <iostream>


class stringbad
{
public:
	stringbad();
	~stringbad();

	stringbad(const char*s);
	friend std::ostream & operator << (std::ostream &os, const stringbad & st);
private:

	char *str;
	int len;
	static int num_strings; //클래스가 호출되는순간 전역변수처럼 사용할 수 있다

};

