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
	static int num_strings; //Ŭ������ ȣ��Ǵ¼��� ��������ó�� ����� �� �ִ�

};

