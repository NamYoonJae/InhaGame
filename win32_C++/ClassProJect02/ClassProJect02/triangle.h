#pragma once

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class GeometricObject 
{
protected:
	string m_color1;	//색상
	int m_color2;	//채색


public:
	GeometricObject::GeometricObject();
	virtual ~GeometricObject();
	virtual void const accessFunction(double a, double b, double c);	//세 개 데이터에 접근하는 접근자 함수
	virtual double getArea(); //면적 반환
	virtual double getPerimeter(); //둘레 반환

};



class Triangle : GeometricObject
{
	double m_side1;
	double m_side2;
	double m_side3;


public:

	Triangle::Triangle();
	Triangle::Triangle(double a, double b, double c);
	virtual~Triangle();

	void const accessFunction(double a, double b, double c);
	double getArea(); //면적 반환
	double getPerimeter(); //둘레 반환


	void setColor1(string color1);
	void setColor2(int color2);
	string getColor1();
	string getColor2();


};
