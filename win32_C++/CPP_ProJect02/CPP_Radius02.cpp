#include "stdafx.h"
#include <string>
#include <iostream>

/*
	Q2. ��(x,y)�� �Է¹޾� �� ���� (0,0)�� �߽����� �ϰ� �� w, ���� h �� ���簢���� ���ο� �����ϴ����� �˻��ϴ� ���α׷��� �ۼ�
	ex) w = 10, h = 5, x = 2, y = 2
		��(2,2)�� �簢�� ���ο� ����

		w = 10, h = 5, x = 6, y = 4
		��(6,4)�� �簢�� �ܺο� ����
*/
using namespace std;

struct Radius
{
	float x,y;
	float w;
	float h;
};

void Calculation(Radius*);

void main(void) 
{
	Radius radius;

	cout << "w�� �Է��ϼ��� : ";
	cin >> radius.w;
	cout << endl;

	cout << "h�� �Է��ϼ��� : ";
	cin >> radius.h;
	cout << endl;

	cout << "x�� �Է��ϼ��� : ";
	cin >> radius.x;
	cout << endl;

	cout << "y�� �Է��ϼ��� : ";
	cin >> radius.y;
	cout << endl;

	Calculation(&radius);

}

void Calculation(Radius*radius) 
{
	
	float xRight = radius->w / 2;
	float xReft = -(radius->w / 2);
	float yHigh = radius->h / 2;
	float yLow = -radius->h / 2;

	if (radius->x <= xRight && radius->x >= xReft && radius->y <= yHigh && radius->y >= yLow)
	{
		cout << "��(" << radius->x << ", " << radius->y << ")�� �簢�� ���ο� ����";
		cout << endl;
	}
	else
	{
		cout << "��(" << radius->x << ", " << radius->y << ")�� �簢�� �ܺο� ����";
		cout << endl;
	}


}