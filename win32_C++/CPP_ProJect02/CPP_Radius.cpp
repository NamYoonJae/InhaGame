#include "stdafx.h"
#include <string>
#include <iostream>

/*
	Q1. �� (x,y)�� �Է¹޾� �� ���� (0,0)�� �߽������ϰ� ������ r �� ���� ���ο� �����ϴ��� �˻��ϴ� ���α׷��� �ۼ��϶�.

	ex) r = 10, x = 4, y = 5
		��(4,5)�� ������ 10�� �� �ȿ� �ֽ��ϴ�.

		r = 10, x = 9, y = 9
		��(9,9)�� ������ 10�� �� �ȿ� ���� �ʽ��ϴ�.

		���α׷��� ���� ���ο� �����ϴ��� �˻��ϴ� �Լ��� �����,
		�� (x,y)�� ���ڷ� �Ѱ��� �� ������ ����ü�� �̿��ؼ� ������ �Ѵ�.
*/
using namespace std;

struct Radius 
{
	float x;
	float y;

};

int Calculation(float r, Radius*);


void main(void) {

	Radius radius;

	float r = 0;
	cout << "������ r�� �Է��ϼ��� : ";
	cin >> r;
	cout << endl;

	cout << "x �� �Է��ϼ��� : ";
	cin >> radius.x;
	cout << endl;
	
	cout << "y �� �Է��ϼ��� : ";
	cin >> radius.y;
	cout << endl;

	int result = Calculation(r,&radius);

	if (result == 1) 
	{
		cout << "������ "<< r <<"�� �ȿ� �ֽ��ϴ�.\n";
	}
	else
	{
		cout << "������ "<< r <<"�� �ȿ� �����ʽ��ϴ�\n";
	}


}

int Calculation(float r, Radius *radius)
{
	float sqrPowSum = sqrt(pow(radius->x, 2) + pow(radius->y, 2));

	if (sqrPowSum <= r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
