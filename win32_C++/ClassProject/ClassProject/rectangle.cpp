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
	cout << "���� : "<<width << endl;
	return width;
}

double rectangle::getHeight()
{
	cout << "���� : "<<height << endl;
	return height;
}

//����
void rectangle::area()
{
	areaRsult = width*height;
	cout << "���� : " << areaRsult <<endl;
}

//�ѷ�
void rectangle::circumference()
{
	circum = (width * 2) + (height * 2);
	cout << "�ѷ� : "<<circum << endl;
}
