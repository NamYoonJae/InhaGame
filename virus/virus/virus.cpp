// virus.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void main()
{
	int infection = 0;
	int virusDrainage = 0;
	int time = 0;

	cout << "�ʱⰨ����: " << endl;
	cin >> infection;

	cout << "���̷��� �ð��� ���� ���: " << endl;
	cin >> virusDrainage;

	cout << "���̷����� �������� �ð�: " << endl;
	cin >> time;

	cout << "���: " << infection * pow(virusDrainage, time) << endl;

	long long int result1 = infection * pow(virusDrainage, time);
	long long int result2 = result1 % 1000000007;

	cout << "�䱸 ���: " << result2 << endl;
    


}

