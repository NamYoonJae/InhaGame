#include "stdafx.h"
#include "myPoint.h"
#include <cmath>


MyPoint::MyPoint()
{
	x = 0;
	y = 0;
}

MyPoint::~MyPoint()
{

}

void MyPoint::setX(double a)
{
	x = a;
}

void MyPoint::setY(double b)
{
	y = b;
}

double MyPoint::distance(MyPoint point2)
{
	return sqrt(pow((point2.x - this->x), 2) + pow((point2.y - this->y), 2));
}


