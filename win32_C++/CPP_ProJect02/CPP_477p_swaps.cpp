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

	cout << "���� 1 = " << wallet1 << "��";
	cout << endl;
	cout << "���� 2 = " << wallet2 << "��\n";
	cout << endl;

	cout << "������ �̿��Ͽ� ������� ��ȯ : \n";
	swapr(wallet1, wallet2);
	cout << "���� 1 = " << wallet1 << "��";
	cout << endl;
	cout << "���� 2 = " << wallet2 << "��\n";
	cout << endl;

	cout << "�����͸� �̿��Ͽ� ������� �ٽñ�ȯ : \n";
	swapp(&wallet1, &wallet2);
	cout << "���� 1 = " << wallet1 << "��";
	cout << endl;
	cout << "���� 2 = " << wallet2 << "��\n";
	cout << endl;

	cout << "������ �����Ͽ� ���� ��ȯ �õ� : \n";
	swapv(wallet1, wallet2);
	cout << "���� 1 = " << wallet1 << "��";
	cout << endl;
	cout << "���� 2 = " << wallet2 << "��\n";
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
