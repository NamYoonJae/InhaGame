#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

void main(void) {

	double *p3 = new double[3];

	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;

	cout << "p3[1]은" << p3[1] << "입니다\n";
	p3 = p3 + 1;

	cout << "이제는 p3[0]이고 " << p3[0] << "이고,";
	cout << "p3[1]이" << p3[1] << "입니다\n";

	p3 = p3 - 1;
	delete[] p3;
}