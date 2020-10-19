#include "stdafx.h"
#include <string>
#include <iostream>

/*
	Q2. 점(x,y)를 입력받아 그 점이 (0,0)을 중심으로 하고 폭 w, 높이 h 인 직사각형의 내부에 존재하는지를 검사하는 프로그램을 작성
	ex) w = 10, h = 5, x = 2, y = 2
		점(2,2)는 사각형 내부에 존재

		w = 10, h = 5, x = 6, y = 4
		점(6,4)는 사각형 외부에 존재
*/
using namespace std;

struct Radius
{
	float x,y;
	float w;
	float h;
};

void Calculation(Radius*);

void main(void) 
{
	Radius radius;

	cout << "w를 입력하세요 : ";
	cin >> radius.w;
	cout << endl;

	cout << "h를 입력하세요 : ";
	cin >> radius.h;
	cout << endl;

	cout << "x를 입력하세요 : ";
	cin >> radius.x;
	cout << endl;

	cout << "y를 입력하세요 : ";
	cin >> radius.y;
	cout << endl;

	Calculation(&radius);

}

void Calculation(Radius*radius) 
{
	
	float xRight = radius->w / 2;
	float xReft = -(radius->w / 2);
	float yHigh = radius->h / 2;
	float yLow = -radius->h / 2;

	if (radius->x <= xRight && radius->x >= xReft && radius->y <= yHigh && radius->y >= yLow)
	{
		cout << "점(" << radius->x << ", " << radius->y << ")는 사각형 내부에 존재";
		cout << endl;
	}
	else
	{
		cout << "점(" << radius->x << ", " << radius->y << ")는 사각형 외부에 존재";
		cout << endl;
	}


}