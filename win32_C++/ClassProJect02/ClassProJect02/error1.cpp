#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

double hmean(double a, double b);

void main(void) 
{
	double x, y, z;
	cout << "두 수를 입력하십시오 : ";
	while (cin >> x >> y)
	{
		z = hmean(x, y);
		cout << x << ", " << y << "의 조회 평균은 " << z << "입니다.\n";
		cout << "다른 두 수를 입력하십시오(끝내려면 q) : ";
	}
	cout << "프로그램을 종료합니다, \n";

}

double hmean(double a, double b) 
{
	if (a == -b) 
	{
		cout << "매개변수들을 hmean()에 전달할 수 없습니다.\n";
		abort();
	}
	return 2.0 * a * b / (a + b);
}