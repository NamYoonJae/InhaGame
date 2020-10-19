#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
T max(T *arr, int size) 
{
	T result = 0;
	for (int i = 0; i < size; i++)
	{
		if (result < arr[i])
		{
			result = arr[i];
		}
	}

	return result;

}


void main(void) 
{

	int intArr[5] = { 1, 3, 5, 7, 2 };
	double doubleArr[5] = { 1.11, 3.33, 5.55, 6.66, 2.22 };

	cout << "가장 큰 숫자 = " << max(intArr, sizeof(intArr) / 4);
	cout << endl;
	cout << "가장 큰 숫자 = " << max(doubleArr, sizeof(doubleArr) / 4);
	cout << endl;

}