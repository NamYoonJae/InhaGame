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

	cout << "int는 " << sizeof(int) << "바이트이다" << endl;
	cout << "short는" << sizeof(short) << "바이트이다" << endl;
	cout << "long는" << sizeof(long) << "바이트이다" << endl;
	cout << "long long 는" << sizeof(long long) << "바이트이다" << endl;
	cout << endl;

	cout << "최댓값" << endl;
	cout << "int : " << n_int << endl;
	cout << "short : " << n_short << endl;
	cout << "long : " << n_long << endl;
	cout << "long long : " << n_llong << endl;

	cout << "최솟값" << endl;
	cout << "int : " << min_int << endl;
	cout << "short : " << min_short << endl;
	cout << "long : " << min_long << endl;
	cout << "long long : " << min_llong << endl;


	cout << "바이트 당 비트 수 = " << CHAR_BIT << endl;


}
