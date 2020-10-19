#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void main(void) {
	 
	char arr[16] = { 'A', 'B', 'C', 'X', 'D', 'E', 'Z', 'C', 'A', 'B' ,'A ', 'C', 'A', 'B', 'A', 'C' };
	//				 'B', 'C', 'X', 'C'
	
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	string input;

	cout << "변환 시킬 문자열 입력: ";
	cin >> input;

	static int inputLast = input.size() - 1; // 입력값의 맨 뒤를 찾기 위해 선언
	int arrLast = inputLast;
	//arr[inputLast]를 하면 arr의 찾기 가능
	//input 맨 뒤와 arr 맨 뒤 비교
	//다르면 count 1 증가 시키고 arr [-1] 해서 비교 
	//다르면 count 1 증가 시키고 arr [-1] 해서 비교 
	//같으면 input[-1] arr[-1] 시켜서 다시 비교

	//같은게 발견되면 arr의 끝지점 count수만큼 증가시켜서 비교


	int count = 0;
	/*
	if (arr[arrLast] == input[inputLast]) 
	{
		arrLast--;
		inputLast--;
		count++;
	}
	else
	{
		inputLast--;
		count;
	}
	*/

	/*
		같은지 비교 arrLast값이 arr의 사이즈와 같은 때 까지 반복

		같으면 ? 어떤식 수행하고 다시 반복

		다르면 ? 어떤시 수행하고 다시 반복
	*/

	while (arrLast != arrSize)
	{
		if (arr[arrLast] == input[inputLast]) //마지막 값이 같으면 양쪽 인덱스 값 감소시키고 
		{
			arrLast--;
			inputLast--;
			count++;
		}
	}


}