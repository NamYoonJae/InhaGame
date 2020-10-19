#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void main(void) {

	cout << fixed << right;

	cout << setw(6) << "N" << setw(14) << "Á¦°ö±Ù" << setw(15) << "³× Á¦°ö±Ù\n";

	double root;
	for (int n = 10; n <=100; n+=10) 
	{
		root = sqrt(double(n));
		cout << setw(6) << setfill('.') << n << setfill(' ') 
			<< setw(12) << setprecision(3) << root 
			<< setw(14) << setprecision(4) << sqrt(root) << endl;
	}

}