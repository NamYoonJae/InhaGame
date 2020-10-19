#include "stdafx.h"
#include <iostream>

using namespace std;

const int Len = 66;
const int Divs = 6;

void subdvide(char ar[], int low, int high, int level);

void main(void) 
{
	char ruler[Len];
	int i;
	int j;
	int max = 0;
	int min = 0;


	for (i = 1; i < Len - 2; i++)
		ruler[i] = ' ';
	ruler[Len - 1] = '\0';

	max = Len - 2;
	min = 0;

	ruler[min] = ruler[max] = '|';
	std::cout << ruler << std::endl;

	for (i = 1; i <=Divs; i++) 
	{
		subdvide(ruler, min, max, i);
		cin.get();
		std::cout << ruler << std::endl;

		for (j = 01; j < Len - 2; j++)
			ruler[j] = ' ';
	}

}

void subdvide(char ar[], int low, int high, int level)
{
	if (level == 0)
		return;

	int mid = (high + low) / 2;
	ar[mid] = '|';
	subdvide(ar, low, mid, level - 1);
	subdvide(ar, mid, high, level - 1);

}
