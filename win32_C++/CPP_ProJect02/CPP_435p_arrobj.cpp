#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

const int Seasons = 4;
const std::array<std::string, Seasons> Sname = { "Spring", "Summer", "Fail", "Winter" };

void fill(std::array<double, Seasons> *pa);
void show(std::array<double, Seasons> da);

void main(void) {

	std::array<double, Seasons> expenses;
	fill(&expenses);
	show(expenses);

}

void fill(std::array<double, Seasons>* pa)
{
	for (int i = 0; i <Seasons; i++) 
	{
		cout << Sname[i] << "�� �ҿ�Ǵ� ��� : ";
		cin >> (*pa)[i];
	}
}

void show(std::array<double, Seasons> da)
{
	double total = 0.0;
	cout << "\n������ ���\n";
	for (int i = 0; i < Seasons; i++) 
	{
		cout << Sname[i] << " : $" << da[i] << endl;
		total += da[i];
	}
	cout << "�� ��� : $" << total << endl;
}
