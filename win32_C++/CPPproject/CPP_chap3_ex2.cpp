#include "stdafx.h"
#include <iostream>
#include <cmath>


/*
	두 점 (x1, y1) (x2, y2)를 입력받아 이 두 점 사이의 거리를 출력하는 프로그램을 작성

	//square root a 를 계싼하기 위해 pow(a, 0.5)를 사용할 수 있다
*/
using namespace std;

void main(void) {

	float x1;
	float x2;
	float x;
	float y;
	float y1;
	float y2;

	cout << "(x1 y1)을 입력하세요" << endl;
	
	cin >> x1 >> y1;

	cout << "(x2 y2)을 입력하세요" << endl;

	cin >> x2 >> y2;


	x = x2 - x1;
	y = y2 - y1;

	float p = pow(x, 2) + pow(y, 2);

	float result = pow(p, 0.5);

	cout << "두 점 사이의 거리는  : " << result << "" << endl;


}
