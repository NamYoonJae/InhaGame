#include "stdafx.h"
#include <iostream>
#include <climits>

void main(void) {

	using namespace std;

	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	int min_int = INT_MIN;
	short min_short = SHRT_MIN;
	long min_long = LONG_MIN;
	long long min_llong = LLONG_MIN;

	cout << "int�� " << sizeof(int) << "����Ʈ�̴�" << endl;
	cout << "short��" << sizeof(short) << "����Ʈ�̴�" << endl;
	cout << "long��" << sizeof(long) << "����Ʈ�̴�" << endl;
	cout << "long long ��" << sizeof(long long) << "����Ʈ�̴�" << endl;
	cout << endl;

	cout << "�ִ�" << endl;
	cout << "int : " << n_int << endl;
	cout << "short : " << n_short << endl;
	cout << "long : " << n_long << endl;
	cout << "long long : " << n_llong << endl;

	cout << "�ּڰ�" << endl;
	cout << "int : " << min_int << endl;
	cout << "short : " << min_short << endl;
	cout << "long : " << min_long << endl;
	cout << "long long : " << min_llong << endl;


	cout << "����Ʈ �� ��Ʈ �� = " << CHAR_BIT << endl;


}
