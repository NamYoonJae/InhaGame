#include "stdafx.h"
#include "triangle.h"


using namespace std;

void main(void) 
{

	Triangle triangle;
	triangle.accessFunction(1.0, 1.0, 1.0);
	
	cout << "»ï°½Çü ¸éÀû : " << triangle.getArea() << endl;
	cout << "»ï°¢Çü µÑ·¹ : " << triangle.getPerimeter() << endl;


	triangle.setColor1("»¡°­");
	triangle.setColor2(0);
	cout << "»ö±ò : " << triangle.getColor1() << endl;
	cout << "Ã¤»ö ¿©ºÎ : " << triangle.getColor2() << endl;





}