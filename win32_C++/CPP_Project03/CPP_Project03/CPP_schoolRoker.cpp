#include "stdafx.h"
#include <iostream>
#include <string>

/*
	�б��� 100���� �繰�԰� 100���� �л��� �ִ�. ��� �繰���� ���� ù ������ �����ִ�. �л��� ���Ƿ� ���鼭 �繰���� ����.

	ù ��° S1�� ù ��° �繰�� L1���� �����Ͽ� ��� ����.
	�� ��° S2�� �� ��° �繰�� L2���� �����Ͽ� �ǳ� �ٸ鼭 �繰���� �ݴ´�.

	�� ��° S3�� �� ���� �繰�� L3���� �����Ͽ� �� ��° �繰�Ը��� ���¸� �����Ѵ�. (������ �ݰ�, ������ ����.)
	�� ��° S4�� �� ��° �繰�� L4���� �����Ͽ� �� ��° �繰�Ը��� ���¸� �����Ѵ�.
	�ټ� ��° S5�� �ټ� ��° �繰�� L5����  �����Ͽ� �ټ� ��° �繰�Ը��� �繰���� ���¸� �����Ѵ�.
	���� �۾��� �л� S100�� L100 �繰���� ���� �� �� ���� ��� �ȴ�.
	��� �л��� ������ ����ϰ� ���� ����, � �繰���� �����ִ��� Ȯ���ϰ�,
	�����ִ� ��� �繰�� ��ȣ�� ����ϴ� ���α׷��� �ۼ��϶�.

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