#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main(void) {

	float price1 = 20.40;
	float price2 = 1.9 + 8.0 / 9.0;

	cout.setf(ios_base::showpoint);
	cout << "\"�տ��� ���� \" $" << price1 << "!\n";
	cout << "\"����� ���� \" $" << price2 << "!\n";

	cout.precision(2);
	cout << "\"�տ��� ���� \" $" << price1 << "!\n";
	cout << "\"����� ���� \" $" << price2 << "!\n";

}