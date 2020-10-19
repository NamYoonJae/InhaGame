// dijkstra.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

#define I 3000
#define NUM_NODE  8

using namespace std;

int SearchMinRoot(int cost[][NUM_NODE], int input);

int main()
{
	int aEdgeCost[NUM_NODE][NUM_NODE] =
	{
		{ 0, 2, I, I, I, 3, I, I },	//1
		{ 2, 0, 4, 1, I, I, I, I },	//2
		{ I, 4, 0, I, 3, I, I, I },	//3
		{ I, 1, I, 0, 3, I, 2, I },	//4
		{ I, I, 3, 3, 0, I, I, 4 },	//5
		{ 3, I, I, I, I, 0, 6, I },	//6
		{ I, I, I, 2, I, 6, 0, 4 },	//7
		{ I, I, I, I, 4, I, 4, 0 }	//8
	};

	int start = 0;
	int end = 0;
	int minCost = 0;
	int i = 0;
	int j = 0;
	int minRoot = 9999;
	int plusRoot = 0;

	int plusEdge[NUM_NODE] = { 0 };
	bool check[NUM_NODE] = { false };
	vector <int> rootList;

	cout << "출발 지점 입력: ";
	cin >> start;
	cout << endl;
	start = start - 1;

	cout << "도착 지점 입력: ";
	cin >> end;
	cout << endl;
	end = end - 1;

	//============================================================================================================
	for (i = 0; i < NUM_NODE; i++)
	{
		if (aEdgeCost[start][i] != 0 && aEdgeCost[start][i] != I && check[i] == false)
		{
			plusEdge[i] += aEdgeCost[start][i];
		}
	}
	check[start] = true;

	//=============
	//plusEdge 확인
	for (i = 0; i < NUM_NODE; i++)
	{
		cout << plusEdge[i] << "  ";
	}
	cout << endl;
	//plusEdge 0, 2, I, I, I, 3, I, I, I
	//============

	for (i = 0; i < NUM_NODE; i++)
	{

		if (plusEdge[i] < minRoot && plusEdge[i] != 0 && check[i] == false)
		{
			minRoot = i;
		}
	}

	//============
	//minRoot 확인
	cout << minRoot << endl;
	//============



	//============================================================================================================



	for (i = 0; i < NUM_NODE; i++)
	{
		if (aEdgeCost[minRoot][i] != 0 && aEdgeCost[minRoot][i] != I && check[i] == false)
		{
			plusEdge[i] += aEdgeCost[minRoot][i];
			plusEdge[i] += aEdgeCost[start][minRoot];
		}

	}
	check[minRoot] = true;


	//============
	//plusEdge 확인
	for (i = 0; i < NUM_NODE; i++)
	{
		cout << plusEdge[i] << "  ";
	}
	cout << endl;
	//plusEdge $, 2, 6, 3, I, 3, I, I, I
	//============


	minRoot = 9999;
	for (i = 0; i < NUM_NODE; i++)
	{
		if (plusEdge[i] < plusEdge[minRoot] && plusEdge[i] != 0 && check[i] == false)
		{
			minRoot = i;
		}
	}
	//minRoot == 4

	//============
	//minRoot 확인
	cout << minRoot << endl;
	//============


	//============================================================================================================
	for (i = 0; i < NUM_NODE; i++)
	{
		if (aEdgeCost[minRoot][i] != 0 && aEdgeCost[minRoot][i] != I&& check[i] == false)
		{
			plusEdge[i] += aEdgeCost[minRoot][i];
			plusEdge[i] += aEdgeCost[start][minRoot];
		}
	}
	check[minRoot] = true;

	//============
	//plusEdge 확인
	for (i = 0; i < NUM_NODE; i++)
	{
		cout << plusEdge[i] << "  ";
	}
	cout << endl;
	//plusEdge $, 2, 6, 3, I, 3, I, I, I
	//============

	return 0;
}

int SearchMinRoot(int cost[][NUM_NODE], int input)
{
	return 0;
}
