#include "stdafx.h"
#include <iostream>
#include <string>
#include "rectangle.h"

/*
직사각형을 나타내는 Rectangle이란 이름의 클래스를 설계하라.
클래스는 다음을 포함한다.
1. 직사각형의 폭과 높이를 나타내는 width, height 라는 이름의 double 데이터 필드
2. width 와 height의 값이 1인 직사각형을 생성하는 인수 없는 생성자
3. 지정된 width와 height를 갖는 기본 직사각형을 생성하는 생성자
4. 모든 데이터 필드에 대한 접근자와 변경자 함수
setWidth(), setHeight(),
getWidth(), getHight()
5. 직사각형의 면적 값을 반환하는 getArea() 함수
6. 둘레 길이를 반환하는 getPerimeter() 함수

ex) 두 개의 Retangle 객체를 생성하는 테스트 프로그램을 작성하고,
첫 번째 객체에는 width = 4, height = 40
두 번째 객체에는 width = 3.5 height = 35.9
각각 할당하고, 두 객체의 속성을 표시하고 면적과 둘레 길이를 계산하라.
ex ) W : 4, H = 30, Area = 160, Per..= 88

*/
using namespace std;

void main(void) 
{
	rectangle rect1;
	rect1.setWidth(4);
	rect1.setHeght(40);
	rect1.getWidth();
	rect1.getHeight();
	rect1.area();
	rect1.circumference();
	cout << endl;

	rectangle rect2;
	rect1.setWidth(3.5);
	rect1.setHeght(35.9);
	rect1.getWidth();
	rect1.getHeight();
	rect1.area();
	rect1.circumference();
	cout << endl;



}


