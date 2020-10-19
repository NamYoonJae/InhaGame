#include "stdafx.h"
#include <iostream>
#include "strngbad.h"

using namespace std;

void callme1(stringbad &);
void callme2(stringbad);

void main(void)
{	/*
	stringbad bad1;
	cout << "bad1 created" << endl;
	{
		stringbad bad2;
		cout << "bad2 created" << endl;
		cout << "End of Block 1" << endl;
	}
	cout << "End of Main" << endl;
	*/

	{
		cout << "내부 블록을 시작한다.\n";
		stringbad headline1("Celery Stalks at Midnight");
		stringbad headline2("Lettuce Prey");
		stringbad sports("Spinach Leaves Bowl for Dollars");
		cout << endl;

		/*


		cout << "headline1 : " << headline1 << endl;
		cout << "headline2 : " << headline2 << endl;
		cout << "sports : " << sports << endl;
		cout << endl;


		callme1(headline1);
		cout << "headline1 : " << headline1 << endl;
		cout << endl;

		callme2(headline2);
		cout << "headline2 : " << headline2 << endl;
		cout << endl;


		cout << "하나의 객체를 다른 객체로 초기화 : \n";
		stringbad sailor = sports;
		cout << "sailor" << sailor << endl;
		cout << endl;

		cout << "하나의 객체를 다른 객체에 대입 : \n";
		stringbad knot;
		knot = headline1;
		cout << "knot : " << knot << endl;
		cout << endl;
		cout << "이 블록을 빠져나온다.\n";
	
	*/


	}
	cout << "main()의 끝\n";
}

void callme1(stringbad & rsb)
{
	cout << "참조로 전달된 Stringbad : ";
	cout << "	\"" << rsb << "\"\n";
}
void callme2(stringbad sb)
{
	cout << "값으로 전달된 Stringbad : ";
	cout << "	\"" << sb << "\"\n";
}
