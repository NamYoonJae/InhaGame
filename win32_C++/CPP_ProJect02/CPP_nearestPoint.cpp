#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

/*
	�� ��Ʈ�� ������ �־����� �� ���� ����� �� ���� ã�� ����ϴ� ���α׷��� �ۼ��϶�.

		x	y
	0	-1	3
	1	-1	-1
	2	1	1	
	3	2	0.5
	4	2	-1
	5	3	3
	6	4	2
	7	4	-0.5
	���� ����� ������ (1, 1) and (2, 0.5)

*/
using namespace std;

struct Radius
{
	float x, y;
};

void main(void) 
{
	vector<Radius> v;
	Radius temp;
	int i = 0;
	int j = 0;
	int someInput = 0;
	float betwwen = 0;
	int minBetwwen = 9999;
	int minIndex1 = 0;
	int minIndex2 = 0;
	//v.push_back();
	
	cout << "�� ���� ��ǥ�� �Է� �Ͻðڽ��ϱ� ?";
	cin >> someInput;
	cout << endl;

	for (i = 0; i < someInput; i++)
	{
		cout << i+1 << "��° x �Է� : ";
		cin >> temp.x;
		cout << endl;

		cout << i+1 << "��° y �Է� : ";
		cin >> temp.y;
		cout << endl;
		v.push_back(temp);

		for (j = 0; j < i; j++) 
		{
			betwwen = sqrt(pow(v[i].x - v[j].x, 2) + pow(v[i].y - v[j].y, 2));
			
			if (betwwen < minBetwwen)
			{
				minBetwwen = betwwen;
				minIndex1 = i;
				minIndex2 = j;
			}
		}
	}

	cout << "���� ����� �� �� �� (" << v[minIndex1].x << ", " << v[minIndex1].y << ") ,";
	cout << "(" << v[minIndex2].x << ", " << v[minIndex2].y << ") �Դϴ�";


	

}