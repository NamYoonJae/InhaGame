#include "stdafx.h"
#include <iostream>
#include <string>

const int maxSize = 10;
int *arrHeap = new int[maxSize];
int arr[maxSize] = { 5, 8, 7, 4, 6, 9, 2, 3, 1, 10 };
int i = 0;
int k = 0;
int parents = 0;
int bitNum = 0;


using namespace std;

void tree();

void main(void)
{

	/*
		�θ��		arr[(i-1) / 2] �θ� �ε����� parentsIndex
		���� �ڽ�	arr[i * 2 + 1]	arr[parentsIndex * 2 + 1]
		������ �ڽ�	arr[i * 2 + 2]	arr[parentsIndex * 2 + 2]

		�θ� �������� �ؼ�
	*/



	for (i = 0; i < maxSize; i++)
	{
		parents = (i - 1) / 2;
		//cout << arr[i] << "  ";

		if (arr[parents] >= arr[parents * 2 + 1] && arr[parents] >= arr[parents * 2 + 2])
		{
			
		}
		else
		{
			tree();
		}

	}

	cout << "2�� Ʈ��" << endl;
	for (i = 0; i < maxSize; i++) 
	{
		cout << arr[i] << "  ";
	}

}

	



void tree() 
{
	i = maxSize;
	while (1)
	{
		parents = (i - 1) / 2;

		if (arr[parents * 2 + 1] <= arr[parents * 2 + 2]) //������ �ڽ��� �� ũ��
		{
			if (arr[parents * 2 + 2] >= arr[parents]) //������ �ڽİ� �θ� �� �� (������ �ڽ��� �� ũ��)
			{
				swap(arr[parents * 2 + 2], arr[parents]);
			}
		}
		else if (arr[parents * 2 + 1] > arr[parents * 2 + 2])
		{
			if (arr[parents * 2 + 1] >= arr[parents])
			{
				swap(arr[parents * 2 + 1], arr[parents]);
			}
		}
		else
		{

		}

		i--;

		if (parents == 0) 
		{
			break;
		}
	}

}