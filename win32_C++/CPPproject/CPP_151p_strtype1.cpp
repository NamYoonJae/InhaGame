#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main(void) {

	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";


	cout << "����̰� ���� �� ���� �Է��Ͻÿ�";
	cin >> charr1;

	cout << "����̰��� �� �ٸ� ���� �� ���� �Է��Ͻÿ�";
	cin >> str1;

	cout << "�Ʒ� �������� ��� ����̰��Դϴ� : \n";
	cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;

	cout << charr2 << "���� 3��° ���� : " << charr2[2] << endl;
	cout << str2 << "���� 3��° ���� : " << str2[2] << endl;

}