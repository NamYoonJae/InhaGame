#pragma once

class MyPoint 
{
private:
	double x;
	double y;

public:
	MyPoint();
	MyPoint(double a, double b)
	{
		x = a;
		y = b;
	}
	~MyPoint();

	void setX(double a);
	void setY(double b);
	double distance(MyPoint point2);

};

