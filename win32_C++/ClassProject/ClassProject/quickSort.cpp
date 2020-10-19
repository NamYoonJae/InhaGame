#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

/*
	leftIndex랑  rightIndex 피벗이랑 비교

	leftIndex가 피벗보다 작고 rightIndex이 피벗보다 클 경우
	leftIndex 인덱스 ++ 
	rightIndex인덱스--

	leftIndex가 피벗보다 크고 rightIndex도 피벗보다 클경우
	rightIndex--
	만약 rightIndex == pivot일경우 swap(leftIndex, pivot)


	leftIndex가 피벗보다 작고 rightIndex도 피벗보다 작을 경우
	leftIndex++
	만약 leftIndex == pivot 일 경우 swap(rightIndex, pivot)


	leftIndex가 pivot 보다 크고 rightIndex가 pivot 보다 작을 경우
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

	
	//왼쪽 오른쪽 피벗 세개가 같은 경우가 있다
	// 이건 지금 내가ㅓ < > 로 처리했기 때문에 따로 처리해야하는데
	// 따로 처리 안하려면 조건문을 <= =>로 수정해야한다
	for (i = 0; i < size; i++)
	{
		//leftIndex가 pivot보다 작고 rightIndex이 pivot보다 클 경우
		if (arr[leftIndex] < arr[pivot] && arr[pivot] < arr[rightIndex])
		{
			leftIndex++;
			rightIndex--;
		}

		//leftIndex 가 pivot보다 크고 rightIndex 가 pivot보다 큰경우 
		else if (arr[leftIndex] > arr[pivot] && arr[pivot] < arr[rightIndex])
		{
			rightIndex--;
			if (rightIndex == pivot)
			{
				swap(arr[leftIndex], arr[pivot]);
			}
		}

		//leftIndex가 pivot보다 작고 rightIndex도 pivot보다 작을 경우
		else if (arr[leftIndex] < arr[pivot] && arr[pivot] > arr[rightIndex])
		{
			leftIndex++;
			if (leftIndex == pivot)
			{
				swap(arr[rightIndex], arr[pivot]);
			}
		}

		//leftIndex가 pivot 보다 크고 rightIndex가 pivot 보다 작을 경우
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