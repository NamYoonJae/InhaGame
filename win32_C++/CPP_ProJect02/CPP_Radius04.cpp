#include "stdafx.h"
#include <iostream>
#include <string>

/*
	Q4 두 개의 원에 대해 중심점 좌표(x,y)와 반지름 r을 입력받아
	두 번째 원이 내부에 있는지(내부 / 외부 판단), 
	첫 번째 원과 겹치는지를 판단하는 프로그램 작성

		ex >	C1 0.5 5.1 13
				C2 1 1.7 4.5
				=> c2는 c1의 내부에 있다.
*/

using namespace std;

struct Radius
{
	float x1, x2;
	float y1, y2;
	float r1, r2;
};

void Calculation(Radius*);

void main(void) {

	Radius radius;

	cout << "C1 x1를 입력하세요 : ";
	cin >> radius.x1;
	cout << endl;

	cout << "C1 y1를 입력하세요 : ";
	cin >> radius.y1;
	cout << endl;

	cout << "C1 r1를 입력하세요 : ";
	cin >> radius.r1;
	cout << endl;


	cout << "C2 x2를 입력하세요 : ";
	cin >> radius.x2;
	cout << endl;

	cout << "C2 y2를 입력하세요 : ";
	cin >> radius.y2;
	cout << endl;

	cout << "C2 r2를 입력하세요 : ";
	cin >> radius.r2;
	cout << endl;


	Calculation(&radius);

}

void Calculation(Radius*radius) 
{
	//두 중심점 사이의 거리
	float powResult = pow((radius->x2 - radius->x1), 2) + pow((radius->y2 - radius->y1), 2);
	float centerBetween = sqrt(powResult);


	//float centerBetween = sqrt(pow((radius->x2 - radius->x1),2) + pow((radius->y2 - radius->y1),2));



	//첫번째 원이 더 크거나 같은경우
	if (radius->r1 >= radius->r2) 
	{
		
		if (centerBetween > radius->r1 + radius->r2) 
		{
			cout << "두 원은 겹치지 않습니다";
		}
		else
		{
			//완전 포함이거나 겹칠경우
			if (centerBetween+radius->r2 <= radius->r1) 
			{
				cout << "첫 번째 원은 두 번째 원을 포함하고 있습니다 ";
			}
			else
			{
				cout << "두 원은 서로 겹칩니다";
			}
		}

	}
	else //첫번째 원이 더 작은경우
	{
		if (centerBetween > radius->r1 + radius->r2) 
		{
			cout << "두 원은 겹치지 않습니다";
		}
		else
		{
			if (centerBetween + radius->r1 <= radius->r2) 
			{
				cout << "두 번째 원은 첫 번째 원을 포함하고 있습니다";
			}
			else
			{
				cout << "두 원은 서로 겹칩니다";
			}
		}

	}

	
}