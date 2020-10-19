#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main(void) {

	int arr[8] = { 8, 1, 4, 2, 7, 6, 3, 5 };
	int i = 0;
	int j = 0;
	int length = sizeof(arr) / sizeof(arr[0]);
	int half = length/2;
	
	while (1) 
	{
		if (half % 2 == 0)
		{
			half = half / 2;
		}
		else
		{
			half = (half / 2) + 1;
		}


		for (i = 0; i + half < length; i++)
		{
			if (arr[i] > arr[half + i])
			{
				swap(arr[i], arr[half + i]);

				for (j = i; j >0;)
				{
					j = j - half;
					if (arr[i] < arr[j])
					{
						swap(arr[i], arr[j]);
					}
					else
					{
						break;
					}
				}
			}
		}

		if (half == 1)
			break;
	}






	for (i = 0 ; i < length; i++) 
	{
		cout << arr[i] << endl;
	}



}