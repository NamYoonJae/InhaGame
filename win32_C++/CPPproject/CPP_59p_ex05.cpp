#include "stdafx.h"
#include <iostream>

using namespace std;

double change(double input);

void main(void) {
	
	double input = 0;
	double result = 0;

	cout << "���� �µ��� �Է��ϰ� EnterŰ�� �����ʽÿ�" << endl;
	cin >> input;


	result = change(input);

	cout << "����" << input << "���� ȭ����" << result << "�Դϴ�";


}

double change(double input)
{

	double result = 1.8*input + 32.0;


	return result;
}
