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

	cout << "��ȯ ��ų ���ڿ� �Է�: ";
	cin >> input;

	static int inputLast = input.size() - 1; // �Է°��� �� �ڸ� ã�� ���� ����
	int arrLast = inputLast;
	//arr[inputLast]�� �ϸ� arr�� ã�� ����
	//input �� �ڿ� arr �� �� ��
	//�ٸ��� count 1 ���� ��Ű�� arr [-1] �ؼ� �� 
	//�ٸ��� count 1 ���� ��Ű�� arr [-1] �ؼ� �� 
	//������ input[-1] arr[-1] ���Ѽ� �ٽ� ��

	//������ �߰ߵǸ� arr�� ������ count����ŭ �������Ѽ� ��


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
		������ �� arrLast���� arr�� ������� ���� �� ���� �ݺ�

		������ ? ��� �����ϰ� �ٽ� �ݺ�

		�ٸ��� ? ��� �����ϰ� �ٽ� �ݺ�
	*/

	while (arrLast != arrSize)
	{
		if (arr[arrLast] == input[inputLast]) //������ ���� ������ ���� �ε��� �� ���ҽ�Ű�� 
		{
			arrLast--;
			inputLast--;
			count++;
		}
	}


}