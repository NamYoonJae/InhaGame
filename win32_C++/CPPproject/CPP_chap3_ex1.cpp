#include "stdafx.h"
#include <iostream>
#include <cmath>
/*
	chap 3. Q1. ������� ���ӵ� a�� �̷��ӵ� v�� �־����� ��,
	����Ⱑ �̷��ϱ� ���� �ּ� Ȱ�� ���̸� ����ϴ� ���α׷��� �ۼ��϶�

	���� = v^2 / 2a

	����ڿ��� ���ʹ� ��(m/s) ������ v�� ����/��^2(m/s^2) ������ ���ӵ� a�� �Է��ϵ��� �˷��ְ�,
	�ּ� Ȱ�� ���̸� ����϶�
	ex) Speed and Accelerration :  60  3.5
		minimum runaway length : 512.286

*/

using namespace std;

void main(void) {

	float inputV = 0;	// �̷��ӵ�
	float inputA = 0;	// ���ӵ�
	float length = 0;
	cout << "�̷� �ӵ��� ���ʹ� ��(m/s)�� �Է��ϼ���" << endl;
	cin >> inputV;

	cout << "���ӵ��� ����/�� ������ �Է��ϼ���" << endl;
	cin >> inputA;

	length = pow(inputV,2) / (2*inputA);

	cout << "Speed and Accelerration : " << inputV << endl;
	cout << "minimum runaway lenth : " << length << endl;






}
