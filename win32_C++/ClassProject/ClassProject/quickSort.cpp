#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

/*
	leftIndex��  rightIndex �ǹ��̶� ��

	leftIndex�� �ǹ����� �۰� rightIndex�� �ǹ����� Ŭ ���
	leftIndex �ε��� ++ 
	rightIndex�ε���--

	leftIndex�� �ǹ����� ũ�� rightIndex�� �ǹ����� Ŭ���
	rightIndex--
	���� rightIndex == pivot�ϰ�� swap(leftIndex, pivot)


	leftIndex�� �ǹ����� �۰� rightIndex�� �ǹ����� ���� ���
	leftIndex++
	���� leftIndex == pivot �� ��� swap(rightIndex, pivot)


	leftIndex�� pivot ���� ũ�� rightIndex�� pivot ���� ���� ���
	swap(leftIndex, rightIndex)

*/
using namespace std;

void main(void) {

	int arr[9] = {5, 7, 1, 4, 6, 2, 3, 9, 8};
	int size = sizeof(arr) / sizeof(arr[0]);
	int pivot = size/2;

	int leftIndex = 0;
	int rightIndex = size-1;

	int i = 0;
	int temp;
	cout << "arr[pivot] : " << arr[pivot] << endl;
	cout << "arr[leftIndex] : " << arr[leftIndex] << endl;
	cout << "arr[rightIndex] : " << arr[rightIndex] << endl;

	
	//���� ������ �ǹ� ������ ���� ��찡 �ִ�
	// �̰� ���� ������ < > �� ó���߱� ������ ���� ó���ؾ��ϴµ�
	// ���� ó�� ���Ϸ��� ���ǹ��� <= =>�� �����ؾ��Ѵ�
	for (i = 0; i < size; i++)
	{
		//leftIndex�� pivot���� �۰� rightIndex�� pivot���� Ŭ ���
		if (arr[leftIndex] < arr[pivot] && arr[pivot] < arr[rightIndex])
		{
			leftIndex++;
			rightIndex--;
		}

		//leftIndex �� pivot���� ũ�� rightIndex �� pivot���� ū��� 
		else if (arr[leftIndex] > arr[pivot] && arr[pivot] < arr[rightIndex])
		{
			rightIndex--;
			if (rightIndex == pivot)
			{
				swap(arr[leftIndex], arr[pivot]);
			}
		}

		//leftIndex�� pivot���� �۰� rightIndex�� pivot���� ���� ���
		else if (arr[leftIndex] < arr[pivot] && arr[pivot] > arr[rightIndex])
		{
			leftIndex++;
			if (leftIndex == pivot)
			{
				swap(arr[rightIndex], arr[pivot]);
			}
		}

		//leftIndex�� pivot ���� ũ�� rightIndex�� pivot ���� ���� ���
		else if (arr[leftIndex] > arr[pivot] && arr[pivot] > arr[rightIndex])
		{
			swap(arr[leftIndex], arr[rightIndex]);
		}


	}
	

	for (i = 0; i < 9; i++) 
	{
		cout << arr[i] << endl;
	}



	


}