#include "stdafx.h"
#include "rectangle.h"
#include <iostream>

using namespace std;

rectangle::rectangle()
{
	width = 0;
	height = 0;
	areaRsult = 0;
	circum = 0;
}

rectangle::~rectangle()
{

}

void rectangle::setWidth(double w)
{
	width = w;
}

void rectangle::setHeght(double h)
{
	height = h;
}

double rectangle::getWidth()
{
	cout << "가로 : "<<width << endl;
	return width;
}

double rectangle::getHeight()
{
	cout << "세로 : "<<height << endl;
	return height;
}

//넓이
void rectangle::area()
{
	areaRsult = width*height;
	cout << "넓이 : " << areaRsult <<endl;
}

//둘레
void rectangle::circumference()
{
	circum = (width * 2) + (height * 2);
	cout << "둘레 : "<<circum << endl;
}
