#include "stdafx.h"
#include <string>
#include <iostream>

/*
	Q1. 점 (x,y)를 입력받아 그 점이 (0,0)을 중심으로하고 반지름 r 인 원의 내부에 존재하는지 검사하는 프로그램을 작성하라.

	ex) r = 10, x = 4, y = 5
		점(4,5)는 반지름 10인 원 안에 있습니다.

		r = 10, x = 9, y = 9
		점(9,9)는 반지름 10인 원 안에 있지 않습니다.

		프로그램은 점이 내부에 존재하는지 검사하는 함수를 만들고,
		점 (x,y)를 인자로 넘겨줄 때 포인터 구조체를 이용해서 만들어야 한다.
*/
using namespace std;

struct Radius 
{
	float x;
	float y;

};

int Calculation(float r, Radius*);


void main(void) {

	Radius radius;

	float r = 0;
	cout << "반지름 r을 입력하세요 : ";
	cin >> r;
	cout << endl;

	cout << "x 을 입력하세요 : ";
	cin >> radius.x;
	cout << endl;
	
	cout << "y 를 입력하세요 : ";
	cin >> radius.y;
	cout << endl;

	int result = Calculation(r,&radius);

	if (result == 1) 
	{
		cout << "반지름 "<< r <<"원 안에 있습니다.\n";
	}
	else
	{
		cout << "반지름 "<< r <<"원 안에 있지않습니다\n";
	}


}

int Calculation(float r, Radius *radius)
{
	float sqrPowSum = sqrt(pow(radius->x, 2) + pow(radius->y, 2));

	if (sqrPowSum <= r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
