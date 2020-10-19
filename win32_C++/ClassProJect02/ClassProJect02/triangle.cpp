#include "stdafx.h"
#include "triangle.h"

GeometricObject::GeometricObject()
{
}


GeometricObject::~GeometricObject()
{
}

void const GeometricObject::accessFunction(double a, double b, double c)
{

}

double GeometricObject::getArea()
{
	return 0;
}

double GeometricObject::getPerimeter()
{
	return 0;
}


Triangle::Triangle()
{
}

Triangle::Triangle(double a, double b, double c)
{
	m_side1 = a;
	m_side2 = b;
	m_side3 = c;

}

Triangle::~Triangle()
{

}

void const Triangle::accessFunction(double a, double b, double c)
{
	m_side1 = a;
	m_side2 = b;
	m_side3 = c;
}


double Triangle::getArea()
{
	double height;
	double s = (m_side1 + m_side2 + m_side3 )/ 2;

	height = sqrt(s*(s - m_side1)*(s - m_side2)*(s - m_side3));

	return height;
}

double Triangle::getPerimeter()
{
	return m_side1 + m_side2 + m_side3;
}

void Triangle::setColor1(string color1)
{
	m_color1 = color1;
}

void Triangle::setColor2(int color2)
{
	m_color2 = color2;
}

string Triangle::getColor1()
{

	return m_color1;
}

string Triangle::getColor2()
{
	string result;
	if (m_color2 == 1)
	{
		result = "True";
	}
	else
	{
		result = "False";
	}

	return result;
}
