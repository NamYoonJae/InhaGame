#include "stdafx.h"
#include <iostream>
#include <string>

/*
	�� ������ �� �ΰ� ? 10
	�� �Է� : 12
	�� ������ ��ȯ�� ? 16
	10���� 12�� 16���� c�̴�

*/

using namespace std;


int ChangeSixteen();


void main(void) {
	//�Լ� ������ �����غ���

	int inputHowNumber = 0;

	cout << "�� ������ �� �Դϱ� ?";
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

//16����
int ChangeSixteen() 
{
	string inputSixteen;
	int howChange;

	cout << "�� �Է� : ";
	cin >> inputSixteen;
	cout << endl;

	cout << "�� ������ ��ȯ ? : ";
	cin >> howChange;
	cout << endl;


	if (howChange == 8) //16������ 8������
	{
		
	}
	else if (howChange == 10) //16������ 10������
	{

	}


}