#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
/*
��� ����

�迭 �� ���� ū ���� ���Ѵ�

�� ū ����ŭ�� �迭�� �����

arr1[6] = {1, 2, 3, 2, 4, 8} �迭�� �־�����

arr1���� 8�� ���� ū ���̴�

arr2[]�� ũ�⸦ 8�� �����ؼ� ���� �����Ѵ�

arr�� ���� ���ڸ� n ���� Ī�ϰ�
arr2[n] +=1 �� ���ش�


arr2�� �� ��ȣ�� �ִ� ���ڸ�ŭ arr3�� ��´�
arr2[0] == 1
arr2[1] == 3
arr2[2] == 4
���

arr3[] 0 1 1 1 2 2 2 2 �� �ȴ�
*/

using namespace std;

void main(void) {

	int arr1[6] = { 2, 1, 2, 4, 3, 8 };
	int arrSize = sizeof(arr1) / sizeof(arr1[0]);
	int maximum = 0;
	int i = 0;
	int j = 0;
	int n = 0;

	for (i = 0; i < arrSize; i++) 
	{
		if (arr1[i] > maximum)
		{
			maximum = arr1[i];
		}
	}
	
	int *arr2 = new int[maximum];

	memset(arr2, 0, sizeof(int)*maximum);

	for (i = 0 ; i < arrSize; i++)
	{
		n = arr1[i]-1; 
		arr2[n] += 1;
	}
	
	for (i = 0; i < maximum; i++) 
	{
		cout << arr2[i] << endl;
	}
	
	vector<int> v;

	for (i = 0; i < maximum; i++) 
	{
		if (arr2[i] > 0) 
		{
			for (j = 0; j < arr2[i]; j++) 
			{
				v.push_back(i+1);
			}
		}
	}

	
	for (i = 0; i < arrSize; i++) 
	{
		cout <<"v: "<< v[i] << endl;
	}
	

	delete[] arr2;
	
	

	


}