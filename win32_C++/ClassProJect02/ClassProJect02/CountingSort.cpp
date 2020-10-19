#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
/*
계수 정렬

배열 중 가장 큰 수를 구한다

그 큰 수만큼의 배열을 만든다

arr1[6] = {1, 2, 3, 2, 4, 8} 배열이 주어진다

arr1에서 8이 가장 큰 수이다

arr2[]의 크기를 8로 지정해서 새로 생성한다

arr의 원소 숫자를 n 으로 칭하고
arr2[n] +=1 을 해준다


arr2의 방 번호에 있는 숫자만큼 arr3에 담는다
arr2[0] == 1
arr2[1] == 3
arr2[2] == 4
라면

arr3[] 0 1 1 1 2 2 2 2 가 된다
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