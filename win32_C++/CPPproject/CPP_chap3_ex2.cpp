#include "stdafx.h"
#include <iostream>
#include <cmath>


/*
	�� �� (x1, y1) (x2, y2)�� �Է¹޾� �� �� �� ������ �Ÿ��� ����ϴ� ���α׷��� �ۼ�

	//square root a �� ����ϱ� ���� pow(a, 0.5)�� ����� �� �ִ�
*/
using namespace std;

void main(void) {

	float x1;
	float x2;
	float x;
	float y;
	float y1;
	float y2;

	cout << "(x1 y1)�� �Է��ϼ���" << endl;
	
	cin >> x1 >> y1;

	cout << "(x2 y2)�� �Է��ϼ���" << endl;

	cin >> x2 >> y2;


	x = x2 - x1;
	y = y2 - y1;

	float p = pow(x, 2) + pow(y, 2);

	float result = pow(p, 0.5);

	cout << "�� �� ������ �Ÿ���  : " << result << "" << endl;


}
