#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
auto maxn(T *arr, int size)
{
	T result = 0;

	for (int i = 0; i < size; i++) 
	{
		if (arr[i] > result) 
		{
			result = arr[i];
		}
	}

	return result;

}

template <> auto maxn<char*>(char **arrChar, int size)
{

	int longestChar = 0;
	int longestNum = 0;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (longestChar < strlen(arrChar[i]))
		{
			longestChar = strlen(arrChar[i]);
			longestNum = i;
		}

	}

	return longestNum;
}



void main(void) 
{
	int intArr[6] = {2, 1, 3, 6, 5, 4};
	double doubleArr[4] = { 2.22, 1.11, 5.55, 3.33 };
	int length = 0;
	int addrNum = 0;

	cout << "int형 배열 최대 값 : " << maxn(intArr, sizeof(intArr) / 4) << endl;
	cout << "double형 배열 최대 값 : " << maxn(doubleArr, sizeof(doubleArr) / 4) << endl;

	char *charArr[4] = { "aaa", "bbbbb","ccccccc","dd" };


	length = sizeof(charArr) / 4;
	addrNum = maxn(charArr, length);

	cout << "charArr[0] : " <<&charArr[0] << endl;
	cout << "charArr[1] : " <<&charArr[1] << endl;
	cout << "charArr[2] : " <<&charArr[2] << endl;
	cout << "charArr[3] : " <<&charArr[3] << endl;


	cout << "가장 긴 문자열의 주소 : " << &charArr[addrNum] << endl;



}