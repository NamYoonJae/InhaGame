#include "stdafx.h"
#include <iostream>
#include <cmath>

/*
	소수 => 약수로 1과 자신만을 가지는 수
	약수 => 어떤 수를 나누었을 때 나누어 떨어지게하는 자연수

	2와 1000 사이에 존재하는 모든 소수를 출력하는 프로그램을 작성하라.
*/
using namespace std;

void main(void) {

	int num = 2;
	int i = 0;
	int numList[1000];

	for (i = 2; i < 1000; i++)
	{
		numList[i] = num;
		num++;
	}

	for (num = 2; num < 1000; num++) 
	{
		for (i = 2; i <1000; i++)
		{
			if (num % i == 0 && num!=i)
			{
				numList[num] = 0;
			}
		}
	}

	for (i = 2; i < 1000; i++) 
	{
		if (numList[i] != 0) 
		{
			cout << numList[i] << endl;
		}

	}
	
}