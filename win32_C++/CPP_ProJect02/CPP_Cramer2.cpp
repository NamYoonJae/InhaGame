#include "stdafx.h"
#include <iostream>
#include <string>

/*
	�׸��� ���� �� 1�� �� ���� (x1,y1)�� (x2,y2)�� �� 2�� �� ���� (x3,y3) (x4,y4)�� �־�����.
	�� ���� ��������
	(y1-y2)x - (x1-x2)y = (y1-y2)x1 - (x1-x2)y1
	(y3-y4)x - (x3-x4)y = (y3-y4)x3 - (x3-x4)y3
	�� 1�� �������� ũ������ �������� �ظ� ���� �� �ִ�.
	�������� �ذ� ���ٸ� �� ���� �����ϴ�.
	4���� ���� �Է� �޾� �������� ����ϴ� ���α׷��� �ۼ��϶�.

	ex) 2 2 5 -1.0 4.0 2.0 -1.0 -2.0
		Interection Point is : (2.8889, 1.1111)
*/

/*
	ũ������ ����
	ax + by = e
	cx + dy = f

	x = (ed-bf) / (ad - bc)
	y = (af-ec) / (ad - bc)

	ad - bc = 0�̸� �ذ� ����
*/


using namespace std;


void main(void) {

	float x1, x2, x3, x4;
	float y1, y2, y3, y4;

	cout << "x1 �� �Է� : ";
	cin >> x1;
	cout << endl;

	cout << "y1 �� �Է� : ";
	cin >> y1;
	cout << endl;

	cout << "x2 �� �Է� : ";
	cin >> x2;
	cout << endl;

	cout << "y2 �� �Է� : ";
	cin >> y2;
	cout << endl;

	cout << "x3 �� �Է� : ";
	cin >> x3;
	cout << endl;

	cout << "y3 �� �Է� : ";
	cin >> y3;
	cout << endl;

	cout << "x4 �� �Է� : ";
	cin >> x4;
	cout << endl;

	cout << "y4 �� �Է� : ";
	cin >> y4;
	cout << endl;

	float a = y1 - y2;
	float b = -(x1 - x2);
	float c = y3 - y4;
	float d = -(x3 - x4);
	float e = ((y1 - y2)*x1) - ((x1 - x2)*y1);
	float f = ((y3 - y4)*x3) - ((x3 - x4)*y3);

	float k = (a*d) - (b*c);

	float x = (e*d - b*f) / k;
	float y = (a*f - e*c) / k;



	
	if (k == 0) 
	{
		cout << "�ذ� �����ϴ�.";
	}
	else
	{
		cout << "Intersecting point is : ( "<< x <<", " << y <<" )"<< endl;
	}

}