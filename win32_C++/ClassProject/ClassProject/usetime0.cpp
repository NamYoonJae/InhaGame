#include "stdafx.h"
#include <iostream>
#include <string>
#include "mytime0.h"

using namespace std;

void main(void) {

	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "Planning time = ";
	planning.show();
	cout << endl;

	cout << "coding time = ";
	coding.show();
	cout << endl;

	cout << "fixing time = ";
	fixing.show();
	cout << endl;

	/*
	total = coding.Sum(fixing);
	cout << "coding.Sum(fixing) = ";
	total.show();
	cout << endl;
	*/
}