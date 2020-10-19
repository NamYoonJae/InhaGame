#include "stdafx.h"
#include "myPoint.h"
#include <iostream>

using namespace std;

void main(void) 
{
	MyPoint point1;
	point1.setX(2);
	point1.setY(2);

	MyPoint point2;
	MyPoint(10, 30.5);
	point2.setX(6);
	point2.setY(8);

	cout << "두 점 사이의 거리 : " << point1.distance(point2) << endl;;


}