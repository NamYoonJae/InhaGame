#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

struct candyBar 
{
	string candyName;
	double weight;
	int kal;
};


void main(void) {

	candyBar snack = { "Mocha Munch", 2.3, 350 };

	cout << "��ǥ�� : " << snack.candyName << "�߷� : " << snack.weight << "Į�θ� : " << snack.kal << endl;;

	candyBar snack1 = { "Peach Munch", 5.0, 400};
	candyBar snack2 = {"apple Munch", 6.0, 500};
	candyBar snack3 = {"mango Munch",7.0 ,600 };

	candyBar candyBarArr[3];
	candyBarArr[0] = snack1;
	candyBarArr[1] = snack2;
	candyBarArr[2] = snack3;

	cout << "������ ��ǥ��" << candyBarArr[0].candyName << "�߷�" << candyBarArr[0].weight << "Į�θ�" << candyBarArr[0].kal << endl;
	cout << "��� ��ǥ��" << candyBarArr[1].candyName << "�߷�" << candyBarArr[1].weight << "Į�θ�" << candyBarArr[1].kal << endl;;
	cout << "���� ��ǥ��" << candyBarArr[2].candyName << "�߷�" << candyBarArr[2].weight << "Į�θ�" << candyBarArr[2].kal << endl;;


	
}