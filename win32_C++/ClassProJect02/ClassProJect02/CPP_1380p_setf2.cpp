#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main(void) {

	cout.setf(ios_base::left, ios_base::adjustfield);
	cout.setf(ios_base::showpos);
	cout.precision(3);

	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);

	cout << "왼쪽 정렬: \n";
	long n;
	for (n = 1; n <= 41; n+=10) 
	{
		cout.width(4);
		cout << n << "!";
		cout.width(12);
		cout << sqrt(double(n)) << "!\n";
	}

	cout.setf(ios_base::internal, ios_base::adjustfield);
	cout.setf(old, ios_base::floatfield);

	cout << "내부(internal) 정렬: \n";
	for (n = 1; n <= 41; n+= 10) 
	{
		cout.width(4);
		cout << n << "!";
		cout.width(12);
		cout << sqrt(double(n)) << "!\n";
	}

	cout.setf(ios_base::right, ios_base::adjustfield);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "오른쪽 정렬:\n";
	for (n = 1; n <=41; n+=10) 
	{
		cout.width(4);
		cout << n << endl;
		cout.width(12);
		cout << sqrt(double(n)) << "!\n";

	}


}