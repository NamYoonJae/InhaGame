#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>

#define N 1000
/*
	동전을 백만 번 던지는 것을 시뮬레이션하고 앞 면과 뒷 면의 수를 출력하는 프로그램을 작성하라.
	100, 1000, 10000, 100000, 1000000
	각각 앞 뒤가 몇 %씩 나오는지 계산해 출력하라.
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
		if (rest == 0) // 난수가 짝수면
		{
			oddNumCount++;
		}
		else
		{
			evenNumCount++;
		}
	}

	cout << "oddNumCount 횟수 : "<< oddNumCount << endl;
	cout << "evenNumCount 횟수 : " << evenNumCount << endl;

	double odd = (double(oddNumCount) / N) * 100;
	double even = (double(evenNumCount) / N) * 100;

	cout << "oddNumCount 확률 : "<< odd << "%" <<endl;
	cout << "evenNumCount 확률 : " << even << "%" << endl;


}