#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

double hmean(double a, double b);

void main(void) 
{
	double x, y, z;
	cout << "�� ���� �Է��Ͻʽÿ� : ";
	while (cin >> x >> y)
	{
		z = hmean(x, y);
		cout << x << ", " << y << "�� ��ȸ ����� " << z << "�Դϴ�.\n";
		cout << "�ٸ� �� ���� �Է��Ͻʽÿ�(�������� q) : ";
	}
	cout << "���α׷��� �����մϴ�, \n";

}

double hmean(double a, double b) 
{
	if (a == -b) 
	{
		cout << "�Ű��������� hmean()�� ������ �� �����ϴ�.\n";
		abort();
	}
	return 2.0 * a * b / (a + b);
}