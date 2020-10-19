#include "stdafx.h"
#include <iostream>
#include <string>

/*
	몇 진수의 수 인가 ? 10
	수 입력 : 12
	몇 진수로 변환을 ? 16
	10진수 12는 16진수 c이다

*/

using namespace std;


int ChangeSixteen();


void main(void) {
	//함수 포인터 생각해보기

	int inputHowNumber = 0;

	cout << "몇 진수의 수 입니까 ?";
	cin >> inputHowNumber;

	if (inputHowNumber == 16)
	{
		ChangeSixteen();
	}

	else if (inputHowNumber == 10)
	{
		
	}

	else if (inputHowNumber == 8) 
	{
		
	}



}

//16진수
int ChangeSixteen() 
{
	string inputSixteen;
	int howChange;

	cout << "수 입력 : ";
	cin >> inputSixteen;
	cout << endl;

	cout << "몇 진수로 변환 ? : ";
	cin >> howChange;
	cout << endl;


	if (howChange == 8) //16진수를 8진수로
	{
		
	}
	else if (howChange == 10) //16진수를 10진수로
	{

	}


}