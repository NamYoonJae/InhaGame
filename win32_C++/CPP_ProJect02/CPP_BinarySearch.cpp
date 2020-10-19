#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

void main(void) {

	int arrList[11] = { 5, 7, 15, 28, 29, 31, 39, 58, 68, 70, 95 };
	int inputNumber = 0;
	int startIndex = 0;
	int endIndex = 0;
	int n = 0; // 중간 좌표값
	int i = 0;
	int y = 0;
	
	cout << "검색할 수 입력 : ";
	cin >> inputNumber;
	cout << endl;

	n = sizeof(arrList) / 4 / 2;
	endIndex = sizeof(arrList) / 4;
	
	while (1) 
	{
		if (endIndex - startIndex == 1 && arrList[n]!=inputNumber) 
		{
			cout << "존재하지 않습니다" << endl;
			break;
		}
		else if (inputNumber > arrList[n]) 
		{
			startIndex = n;
			n = (startIndex + endIndex) / 2; //중간값
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
			cout << n + 1 << "번째에 있습니다"<<endl;
			break;
		}

	}
	


}