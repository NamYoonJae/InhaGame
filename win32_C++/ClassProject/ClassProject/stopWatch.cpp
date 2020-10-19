#include "stdafx.h"
#include "stopWatch.h"
#include <cmath>
#include <iostream>
#include <time.h>

int *arr2 = new int[maxSize];

using namespace std;

stopWatch::stopWatch()
{
	m_startTime = 0;
	m_endTime = 0;
}

stopWatch::~stopWatch()
{
}

void stopWatch::inNumber()
{
	int i = 0;
	for (i = 0; i < maxSize; i++)
	{	
		arr[i] = rand()% maxSize +1;
	}

}

void stopWatch::start()
{
	m_startTime = clock();
	cout <<"시작 시간 : "<< m_startTime << "m/s"<< endl;
}

void stopWatch::end()
{
	m_endTime = clock();
	cout << "종료 시간 : " << m_endTime <<"m/s"<< endl;
}

void stopWatch::bubbleSort()
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for (i = 0; i < maxSize; i++)
	{
		for (j = 1; j < maxSize; j++)
		{
			if (arr[i] >arr[j]) 
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}

void stopWatch::choiceSort()
{

	int i = 0;
	int j = 0;
	int temp = 0;

	for (i = 0; i < maxSize; i++)
	{
		int min = i;
		for (j = 1; j < maxSize; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}

		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}

/*
	for (i = 0; i < 100000; i++) 
	{
		for (j=i+1; j<100000; j++) 
		{
			if (arr[i] > arr[j])
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
		}
	}
	*/
}


void stopWatch::insertSort()
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < maxSize; i++)
	{
		int temp = arr[i];
		for (j = i; j > 0 && arr[j-1] > temp; j--) 
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
	
}

void stopWatch::shellSort()
{
	int i = 0;
	int j = 0;
	int length = sizeof(arr)/sizeof(arr[0]);
	int half = length / 2;

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


				
				for (j = i; j > 0;)
				{

					if (arr[j] < arr[j - half])
					{
						swap(arr[j], arr[j-half]);
					}
					else
					{
						break;
					}
					j = j - half;
				}
				

			}
		}

		if (half == 1)
			break;
	}

	for (i = 0; i < maxSize; i++) 
	{
		cout << arr[i] << endl;
	}
	
}

void stopWatch::partition(int leftIndex, int rightIndex)
{
	int half;
	if (leftIndex < rightIndex)
	{
		half = (leftIndex + rightIndex) / 2;
		partition(leftIndex, half);
		partition(half + 1, rightIndex);
		mercy(leftIndex, rightIndex);

	}
}

void stopWatch::mercy(int leftIndex, int rightIndex)
{
	int half = (leftIndex + rightIndex) / 2;
	int i = leftIndex;
	int j = half + 1;
	int k = leftIndex;

	while (i <= half && j <= rightIndex)
	{
		if (arr[i] <= arr[j])
		{
			arr2[k++] = arr[i++];
		}
		else
		{
			arr2[k++] = arr[j++];
		}
	}

	int temp = i > half ? j : i;

	while (k <= rightIndex)
		arr2[k++] = arr[temp++];

	for (i = 0; i <= rightIndex; i++)
	{
		arr[i] = arr2[i];
	}

	/*
	for (i = 0; i < maxSize + 1;  i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	*/
}


void stopWatch::timeCal()
{
	cout << "경과 시간 : " << this->m_endTime - this->m_startTime << "m/s" << endl;
	cout << endl;
}





