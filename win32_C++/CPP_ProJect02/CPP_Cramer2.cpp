#include "stdafx.h"
#include <iostream>
#include <string>

/*
	그림과 같이 선 1의 두 점은 (x1,y1)과 (x2,y2)로 선 2의 두 점은 (x3,y3) (x4,y4)로 주어진다.
	두 선의 교차점은
	(y1-y2)x - (x1-x2)y = (y1-y2)x1 - (x1-x2)y1
	(y3-y4)x - (x3-x4)y = (y3-y4)x3 - (x3-x4)y3
	이 1차 방정식은 크래머의 공식으로 해를 구할 수 있다.
	방정식의 해가 없다면 두 선은 평행하다.
	4개의 점을 입력 받아 교차점을 출력하는 프로그램을 작성하라.

	ex) 2 2 5 -1.0 4.0 2.0 -1.0 -2.0
		Interection Point is : (2.8889, 1.1111)
*/

/*
	크래머의 공식
	ax + by = e
	cx + dy = f

	x = (ed-bf) / (ad - bc)
	y = (af-ec) / (ad - bc)

	ad - bc = 0이면 해가 없음
*/


using namespace std;


void main(void) {

	float x1, x2, x3, x4;
	float y1, y2, y3, y4;

	cout << "x1 을 입력 : ";
	cin >> x1;
	cout << endl;

	cout << "y1 을 입력 : ";
	cin >> y1;
	cout << endl;

	cout << "x2 을 입력 : ";
	cin >> x2;
	cout << endl;

	cout << "y2 을 입력 : ";
	cin >> y2;
	cout << endl;

	cout << "x3 을 입력 : ";
	cin >> x3;
	cout << endl;

	cout << "y3 을 입력 : ";
	cin >> y3;
	cout << endl;

	cout << "x4 을 입력 : ";
	cin >> x4;
	cout << endl;

	cout << "y4 을 입력 : ";
	cin >> y4;
	cout << endl;

	float a = y1 - y2;
	float b = -(x1 - x2);
	float c = y3 - y4;
	float d = -(x3 - x4);
	float e = ((y1 - y2)*x1) - ((x1 - x2)*y1);
	float f = ((y3 - y4)*x3) - ((x3 - x4)*y3);

	float k = (a*d) - (b*c);

	float x = (e*d - b*f) / k;
	float y = (a*f - e*c) / k;



	
	if (k == 0) 
	{
		cout << "해가 없습니다.";
	}
	else
	{
		cout << "Intersecting point is : ( "<< x <<", " << y <<" )"<< endl;
	}

}