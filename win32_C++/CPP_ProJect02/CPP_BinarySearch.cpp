#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

void main(void) {

	int arrList[11] = { 5, 7, 15, 28, 29, 31, 39, 58, 68, 70, 95 };
	int inputNumber = 0;
	int startIndex = 0;
	int endIndex = 0;
	int n = 0; // �߰� ��ǥ��
	int i = 0;
	int y = 0;
	
	cout << "�˻��� �� �Է� : ";
	cin >> inputNumber;
	cout << endl;

	n = sizeof(arrList) / 4 / 2;
	endIndex = sizeof(arrList) / 4;
	
	while (1) 
	{
		if (endIndex - startIndex == 1 && arrList[n]!=inputNumber) 
		{
			cout << "�������� �ʽ��ϴ�" << endl;
			break;
		}
		else if (inputNumber > arrList[n]) 
		{
			startIndex = n;
			n = (startIndex + endIndex) / 2; //�߰���
			continue;
		}
		else if(inputNumber < arrList[n])
		{
			endIndex = n;
			n = (startIndex + endIndex) / 2;
			continue;
		}
		else if (inputNumber == arrList[n])
		{
			cout << n + 1 << "��°�� �ֽ��ϴ�"<<endl;
			break;
		}

	}
	


}