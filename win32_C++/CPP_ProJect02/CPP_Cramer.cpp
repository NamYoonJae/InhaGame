#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

/*
다음 2x2 1차 방정식을 크래머의 공식을 사용해 풀이하는 프로그램을 작성하라.
ax + by = e
cx + dy = f

x = (ed-bf) / (ad-bc)
y = (af-ec) / (ad - bc)

a,b,c,d,e,f 값을 입력받아 결과를 출력하라.
ad-bc = 0 이면 "해가 없음"을 출력하라

*/

using namespace std;

void main(void) {

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;

	cout << "a입력 : ";
	cin >> a;
	cout << endl;

	cout << "b입력 : ";
	cin >> b;
	cout << endl;

	cout << "c입력 : ";
	cin >> c;
	cout << endl;

	cout << "d입력 : ";
	cin >> d;
	cout << endl;

	cout << "e입력 : ";
	cin >> e;
	cout << endl;

	cout << "f입력 : ";
	cin >> f;
	cout << endl;

	int x = (((e*d) - (b*f)) / ((a*d) - (b*c)));
	int y = (((a*f) - (e*c)) / ((a*d) - (b*c)));

	if (((a*d) - (b*c)) == 0)
	{
		cout << "해가 없습니다";
	}
	else
	{
		cout << "x는 " << x << "입니다";
		cout << endl;
		cout << "y는 " << y << "입니다";
		cout << endl;
	}



}