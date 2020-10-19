#include "stdafx.h"
#include <iostream>
#include <string>

/*
	학교에 100개의 사물함과 100명의 학생이 있다. 모든 사물함은 개학 첫 날에는 닫혀있다. 학생이 교실로 들어가면서 사물함을 연다.

	첫 번째 S1은 첫 번째 사물함 L1부터 시작하여 모두 연다.
	두 번째 S2는 두 번째 사물함 L2부터 시작하여 건너 뛰면서 사물함을 닫는다.

	세 번째 S3는 세 번재 사물함 L3부터 시작하여 세 번째 사물함마다 상태를 변경한다. (열린건 닫고, 닫힌건 연다.)
	네 번째 S4는 네 번째 사물함 L4부터 시작하여 네 번째 사물함마다 상태를 변경한다.
	다섯 번째 S5는 다섯 번째 사물함 L5부터  시작하여 다섯 번째 사물함마다 사물함의 상태를 변경한다.
	히이 작업은 학생 S100이 L100 사물함을 변경 할 떄 까지 계속 된다.
	모든 학생이 교실을 통과하고 나간 다음, 어떤 사물함이 열려있는지 확인하고,
	열려있는 모든 사물함 번호를 출력하는 프로그램을 작성하라.

*/

using namespace std;

void main(void) {
	
	int i = 0;
	int z = 0;
	int n = 1;
	int k = 0;
	int total = 1;
	int locker[101] = { 0 };
	int count = 0;
	

	for (i= 1; i < 101; i++) 
	{
		locker[i] = 1;
	}

	for (i = 1; i < 101; i++)
	{
		n = i * 2;

		if (n >101)
		{
			break;
		}

		locker[n] = 0;
	}


	for (z = 3; z< 101; z++) 
	{
		for (i = 1; i < 101; i++)
		{
			n = i * z;
			
			if (n >101)
			{
				break;
			}
			
			locker[n] = !locker[n];
		}
	}
	
	for (i = 1; i < 101; i++) 
	{

		
		if (locker[i] == 1)
		{
			cout << i << endl;
		}
		


	}

}