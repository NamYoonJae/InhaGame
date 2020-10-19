#include "stdafx.h"
#include <iostream>
#include <string>


/*
	Q3. 두 직사각형에 대해 중심점의 x,y 좌표 값 폭 w, 높이 h를 입력받아
	두 번째 직사각형이 첫 번째 직사각형의 내부에 있는지,
	첫 번째 직사각형과 겹치는지를 판단하는 프로그램 작성

	ex >	R1 2.5 / 4 / 2.5 / 43
			R2 1.5 / 5 / 0.5 / 3
			=> R2는 R1이 내부에 있다
*/
using namespace std;



struct Radius
{

	float x1, x2;
	float y1, y2;
	float w1, w2;
	float h1, h2;
};

void Calculation(Radius *);


void main(void) {
	Radius radius;

	float h2;

	cout << "R1의 x1를 입력하세요 : ";
	cin >> radius.x1;
	cout << endl;

	cout << "R1의 y1를 입력하세요 : ";
	cin >> radius.y1;
	cout << endl;

	cout << "R1의 w1를 입력하세요 : ";
	cin >> radius.w1;
	cout << endl;

	cout << "R1의 h1를 입력하세요 : ";
	cin >> radius.h1;
	cout << endl;


	cout << "R2의 x2를 입력하세요 : ";
	cin >> radius.x2;
	cout << endl;

	cout << "R2의 y2를 입력하세요 : ";
	cin >> radius.y2;
	cout << endl;

	cout << "R2의 w2를 입력하세요 : ";
	cin >> radius.w2;
	cout << endl;

	cout << "R2의 h2를 입력하세요 : ";
	cin >> radius.h2;
	cout << endl;


	Calculation(&radius);
}

void Calculation(Radius *radius) 
{
	float rightMark1 = radius->x1 + (radius->w1 / 2); //R1 x축 오른쪽 끝 좌표
	float reftMark1 = radius->x1 - (radius->w1 / 2); //R1 x축 왼쪽 끝 좌표

	float highH1 = radius->y1 + (radius->h1 / 2); //R1 y축 최상단 좌표
	float lowH1 = radius->y1 - (radius->h1 / 2); //R1 y축 최하단 좌표


	float rightMark2 = radius->x2 + (radius->w2 / 2);
	float reftMark2 = radius->x2 - (radius->w2 / 2);

	float highH2 = radius->y2 + (radius->h2 / 2);
	float lowH2 = radius->y2 - (radius->h2 / 2);

	//두 번째 사각형의 중앙이 첫 번째 사각형 안에 들어있냐 없냐
	if (reftMark1 <= radius->x2 && radius->x2 <= rightMark1 && lowH1<=radius->y2 && radius->y2 <=highH1) 
	{
		//사각형 안에 있는 경우
		if (reftMark1 <= reftMark2 && rightMark1 >= rightMark2 && highH1 >= highH2 && lowH1 <= lowH2)
		{
			cout << "두 번째 사각형은 첫 번째 사갹형 내부에 들어있습니다.";
			cout << endl;
		}
		else
		{
			cout << "두 번째 사각형은 첫 번째 사각형과 겹칩니다";
			cout << endl;
		}
	}
	//두 번째 사갹형의 중앙이 첫 번째 사갹형 안에 없는 경우 
	else
	{

		//두 번째 사각형의 4개의 꼭지점 하나라도 첫 번째 도형안에 있을 경우
		if (reftMark2 > reftMark1 && reftMark2 < rightMark1 && reftMark2 < highH1 && reftMark2 >lowH1 ) 
		{
			cout << "두 번째 사각형은 첫 번째 사각형과 겹칩니다.";
			cout << endl;
		}
		else if (rightMark2 > reftMark1 && rightMark2 < rightMark1 && rightMark2 < highH1 && rightMark2 > lowH1) 
		{
			cout << "두 번째 사각형은 첫 번째 사각형과 겹칩니다.";
			cout << endl;
		}
		else if (highH2 > reftMark1 && highH2 < rightMark2 && highH2 < highH1 && highH2 > lowH1)
		{
			cout << "두 번째 사각형은 첫 번째 사각형과 겹칩니다.";
			cout << endl;
		}
		else if (lowH2 > reftMark1 && lowH2 < rightMark1 && lowH2 < highH1 && lowH2 > lowH1)
		{
			cout << "두 번째 사각형은 첫 번째 사각형과 겹칩니다.";
			cout << endl;
		}

		//첫 번째 사각형의 4개의 꼭지점 하나라도 두 번째 도형안에 있을 경우
		else if (reftMark1 < rightMark2 && reftMark1 > reftMark2 && reftMark1 <highH2 && reftMark1 >lowH2) 
		{
			cout << "첫 번째 사각형은 두 번째 사각형과 겹칩니다.";
			cout << endl;
		}
		else if (rightMark1 < rightMark2 && rightMark1 > reftMark2 && rightMark1 <highH2 && rightMark1 >lowH2)
		{
			cout << "첫 번째 사각형은 두 번째 사각형과 겹칩니다.";
			cout << endl;
		}
		else if (highH1 < rightMark2 && highH1 > reftMark2 && highH1 <highH2 && highH1 >lowH2)
		{
			cout << "첫 번째 사각형은 두 번째 사각형과 겹칩니다.";
			cout << endl;
		}
		else if (lowH1 < rightMark2 && lowH1 > reftMark2 && lowH1 <highH2 && lowH1 >lowH2)
		{
			cout << "첫 번째 사각형은 두 번째 사각형과 겹칩니다.";
			cout << endl;
		}

		//꼭지점이 겹치지 않지만 두 면이 겹칠경우
		else if(reftMark1 < reftMark2 && rightMark1 > rightMark2 && highH1 < highH2 && lowH1 > lowH2)
		{
			cout << "두 도형은 겹칩니다";
			cout << endl;
		}
		else if (reftMark1 > reftMark2 && rightMark1 < rightMark2 && highH1 > highH2 && lowH1 < lowH2)
		{
			cout << "두 도형은 겹칩니다";
			cout << endl;
		}

		else
		{
			cout << "두 번째 사각형과 첫 번째 사각형은 겹치지 않습니다.";
			cout << endl;
		}


	}

}
