// CPP_ProJect02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{

	// �̷��� ����ϸ� pr�� ��� ���� ��µȴ�.
	// for������ i������Ű�鼭 �̾Ƴ� �ʿ� ����
	double pr[5] = { 4.44, 5.44, 6.66, 2.22, 7.77 };

		for (double x : pr) 
		{
			cout << x << endl;
		}

    return 0;
}

