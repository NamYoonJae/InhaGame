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
		cout << "���� ����� �����Ѵ�.\n";
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


		cout << "�ϳ��� ��ü�� �ٸ� ��ü�� �ʱ�ȭ : \n";
		stringbad sailor = sports;
		cout << "sailor" << sailor << endl;
		cout << endl;

		cout << "�ϳ��� ��ü�� �ٸ� ��ü�� ���� : \n";
		stringbad knot;
		knot = headline1;
		cout << "knot : " << knot << endl;
		cout << endl;
		cout << "�� ����� �������´�.\n";
	
	*/


	}
	cout << "main()�� ��\n";
}

void callme1(stringbad & rsb)
{
	cout << "������ ���޵� Stringbad : ";
	cout << "	\"" << rsb << "\"\n";
}
void callme2(stringbad sb)
{
	cout << "������ ���޵� Stringbad : ";
	cout << "	\"" << sb << "\"\n";
}
