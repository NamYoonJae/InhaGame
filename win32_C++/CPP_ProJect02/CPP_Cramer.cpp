#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

/*
���� 2x2 1�� �������� ũ������ ������ ����� Ǯ���ϴ� ���α׷��� �ۼ��϶�.
ax + by = e
cx + dy = f

x = (ed-bf) / (ad-bc)
y = (af-ec) / (ad - bc)

a,b,c,d,e,f ���� �Է¹޾� ����� ����϶�.
ad-bc = 0 �̸� "�ذ� ����"�� ����϶�

*/

using namespace std;

void main(void) {

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;

	cout << "a�Է� : ";
	cin >> a;
	cout << endl;

	cout << "b�Է� : ";
	cin >> b;
	cout << endl;

	cout << "c�Է� : ";
	cin >> c;
	cout << endl;

	cout << "d�Է� : ";
	cin >> d;
	cout << endl;

	cout << "e�Է� : ";
	cin >> e;
	cout << endl;

	cout << "f�Է� : ";
	cin >> f;
	cout << endl;

	int x = (((e*d) - (b*f)) / ((a*d) - (b*c)));
	int y = (((a*f) - (e*c)) / ((a*d) - (b*c)));

	if (((a*d) - (b*c)) == 0)
	{
		cout << "�ذ� �����ϴ�";
	}
	else
	{
		cout << "x�� " << x << "�Դϴ�";
		cout << endl;
		cout << "y�� " << y << "�Դϴ�";
		cout << endl;
	}



}