#include "stdafx.h"
#include <iostream>

using namespace std;

void main(void) {


	int rats = 101;
	int & rodents = rats;

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats狼 林家 = " << &rats;
	cout << ", rodents狼 林家 = " << &rodents << endl;

}