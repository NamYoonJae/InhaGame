#pragma once

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class GeometricObject 
{
protected:
	string m_color1;	//����
	int m_color2;	//ä��


public:
	GeometricObject::GeometricObject();
	virtual ~GeometricObject();
	virtual void const accessFunction(double a, double b, double c);	//�� �� �����Ϳ� �����ϴ� ������ �Լ�
	virtual double getArea(); //���� ��ȯ
	virtual double getPerimeter(); //�ѷ� ��ȯ

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
	double getArea(); //���� ��ȯ
	double getPerimeter(); //�ѷ� ��ȯ


	void setColor1(string color1);
	void setColor2(int color2);
	string getColor1();
	string getColor2();


};
