#include "stdafx.h"
#include "triangle.h"


using namespace std;

void main(void) 
{

	Triangle triangle;
	triangle.accessFunction(1.0, 1.0, 1.0);
	
	cout << "�ﰽ�� ���� : " << triangle.getArea() << endl;
	cout << "�ﰢ�� �ѷ� : " << triangle.getPerimeter() << endl;


	triangle.setColor1("����");
	triangle.setColor2(0);
	cout << "���� : " << triangle.getColor1() << endl;
	cout << "ä�� ���� : " << triangle.getColor2() << endl;





}