#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

/*
	한 세트의 점들이 주어졌을 때 가장 가까운 두 점을 찾아 출력하는 프로그램을 작성하라.

		x	y
	0	-1	3
	1	-1	-1
	2	1	1	
	3	2	0.5
	4	2	-1
	5	3	3
	6	4	2
	7	4	-0.5
	가장 가까운 점들은 (1, 1) and (2, 0.5)

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
	
	cout << "몇 개의 좌표를 입력 하시겠습니까 ?";
	cin >> someInput;
	cout << endl;

	for (i = 0; i < someInput; i++)
	{
		cout << i+1 << "번째 x 입력 : ";
		cin >> temp.x;
		cout << endl;

		cout << i+1 << "번째 y 입력 : ";
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

	cout << "가장 가까운 두 점 는 (" << v[minIndex1].x << ", " << v[minIndex1].y << ") ,";
	cout << "(" << v[minIndex2].x << ", " << v[minIndex2].y << ") 입니다";


	

}