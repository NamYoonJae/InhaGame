#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main(void) {

	int numArr[7][7] = {0};
	int x = 0;
	int y = 0;
	int n = 1;
	int k = 0;

	for (x = 0; x <7; x++) 
	{
		if (x<4) 
		{
			for (y = 0 + x; y < 7 - x; y++)
			{
				numArr[x][y] = n;
			}
			++n;
		}

		else
		{	
			for (y = 6-x; y <1+x ; y++) 
			{
				numArr[x][y]=n-2;
			}
			--n;
		}
		

	}




	for (x = 0; x <7; x++)
	{
		for (y = 0; y < 7; y++)
		{
			if (numArr[x][y] == 0)
			{
				cout << " ";
			}
			else
			{
				cout << numArr[x][y];
			}
		}
		cout << endl;
	}

}