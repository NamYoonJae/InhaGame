#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>

#define N 1000
/*
	������ �鸸 �� ������ ���� �ùķ��̼��ϰ� �� ��� �� ���� ���� ����ϴ� ���α׷��� �ۼ��϶�.
	100, 1000, 10000, 100000, 1000000
	���� �� �ڰ� �� %�� �������� ����� ����϶�.
*/
using namespace std;

void main(void) {
	int i = 0;
	int oddNumCount = 0;
	int evenNumCount = 0;

	for (i = 0; i < N; i++) 
	{
		int num = rand();
		int rest = (int)num % 2;
		if (rest == 0) // ������ ¦����
		{
			oddNumCount++;
		}
		else
		{
			evenNumCount++;
		}
	}

	cout << "oddNumCount Ƚ�� : "<< oddNumCount << endl;
	cout << "evenNumCount Ƚ�� : " << evenNumCount << endl;

	double odd = (double(oddNumCount) / N) * 100;
	double even = (double(evenNumCount) / N) * 100;

	cout << "oddNumCount Ȯ�� : "<< odd << "%" <<endl;
	cout << "evenNumCount Ȯ�� : " << even << "%" << endl;


}