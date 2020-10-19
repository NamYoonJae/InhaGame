#include "stdafx.h"
#include <iostream>

using namespace std;

void swapr(int & a, int &b);
void swapp(int *p, int *q);
void swapv(int a, int b);


void main(void) 
{
	int wallet1 = 3000;
	int wallet2 = 3500;

	cout << "지갑 1 = " << wallet1 << "원";
	cout << endl;
	cout << "지갑 2 = " << wallet2 << "원\n";
	cout << endl;

	cout << "참조를 이용하여 내용들을 교환 : \n";
	swapr(wallet1, wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << endl;
	cout << "지갑 2 = " << wallet2 << "원\n";
	cout << endl;

	cout << "포인터를 이용하여 내용들을 다시교환 : \n";
	swapp(&wallet1, &wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << endl;
	cout << "지갑 2 = " << wallet2 << "원\n";
	cout << endl;

	cout << "값으로 전달하여 내용 교환 시도 : \n";
	swapv(wallet1, wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << endl;
	cout << "지갑 2 = " << wallet2 << "원\n";
	cout << endl;


}

void swapr(int & a, int & b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;

}

void swapp(int * p, int * q)
{
	int temp;

	temp = *p;
	*p = *q;
	*q = temp;

}

void swapv(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;

}
