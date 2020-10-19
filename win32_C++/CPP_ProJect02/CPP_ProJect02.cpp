// CPP_ProJect02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{

	// 이렇게 사용하면 pr의 모든 것이 출력된다.
	// for문으로 i증가시키면서 뽑아낼 필요 없다
	double pr[5] = { 4.44, 5.44, 6.66, 2.22, 7.77 };

		for (double x : pr) 
		{
			cout << x << endl;
		}

    return 0;
}

