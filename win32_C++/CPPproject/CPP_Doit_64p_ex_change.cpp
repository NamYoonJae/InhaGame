#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main(void) {

	int arr[7] = { 22, 57, 11, 32, 91, 68, 70};

	int temp = 0;
	int i = 0;
	int n = sizeof(arr) / 4;
	for (i = 0; i <  n/ 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = temp;
	}

	for (i = 0; i < n; i++) 
	{
		cout << arr[i]<<", ";
	}

}