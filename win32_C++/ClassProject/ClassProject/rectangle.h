#pragma once

class rectangle 
{
	
private:
	double width;
	double height;
	double areaRsult;
	double circum;
public:
	rectangle();
	~rectangle();

	void rectangle::setWidth(double w);
	void rectangle::setHeght(double h);
	double rectangle::getWidth();
	double rectangle::getHeight();
	void rectangle::area();//≥–¿Ã
	void rectangle::circumference();//µ—∑π

};