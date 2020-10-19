// dijkstra.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

#define I 3000
#define NUM_NODE  8

using namespace std;

//void search(int aEdgeCost[][NUM_NODE], int aNodeArray[NUM_NODE], bool check, int oldNode);

int main()
{
	int aEdgeCost[NUM_NODE][NUM_NODE] =
	{
		{0, 2, I, I, I, 3, I, I},	//1
		{2, 0, 4, 1, I, I, I, I},	//2
		{I, 4, 0, I, 3, I, I, I},	//3
		{I, 1, I, 0, 3, I, 2, I},	//4
		{I, I, 3, 3, 0, I, I, 4},	//5
		{3, I, I, I, I, 0, 6, I},	//6
		{I, I, I, 2, I, 6, 0, 4},	//7
		{I, I, I, I, 4, I, 4, 0}	//8
	};

	/*
	int mincost[NUM_NODE][NUM_NODE] = 
	{
		{0, 2, 6, 3, 6, 3, 5, 9},
		{},
		{},
		{},
		{},
		{},
		{},
		{}
	};
	*/

	int aNodeArray[NUM_NODE] = { 0 };
	bool check[NUM_NODE] = { false };
	bool checkTemp[NUM_NODE] = { false };


	int start = 0;
	int end = 0;

	int oldNode = 0;
	int oldNodeIndex = 0;

	int minNode = 9999;	//�ּ� ��带 ���� ����
	int plusNode = 0;
	vector<int> vRootList;
	
	int i = 0;
	int k = 0;
	int minIndex = 0;


	cout << "��� �Է�: ";
	cin >> start;
	cout << "���� �Է�: ";
	cin >> end;

	start = start - 1;
	end = end - 1;

	oldNode = start;

	while (1)
	{
		//ù��° �˻�
		check[oldNodeIndex] = true;
		vRootList.push_back(oldNode);
		for (i = 0; i < NUM_NODE; i++)
		{
			if (aEdgeCost[oldNode][i] != I && check[i] == false)
			{
				aNodeArray[i] += aEdgeCost[oldNode][i];
				aNodeArray[i] += plusNode;
			}
		}

		for (i = 0; i < NUM_NODE; i++)
		{
			if (aEdgeCost[oldNode][i] != 0 && aEdgeCost[oldNode][i] < minNode && check[i] == false)
			{
				minNode = aEdgeCost[oldNode][i];
				oldNodeIndex = i;

			}

		}
		plusNode += minNode;


		oldNode = oldNodeIndex;
		minNode = 9999;



		if (check[end] == true) 
		{
			break;
		}


	}

	//�ּҺ�� �迭�� ���� �� plusNode�� �ּҺ�뺸�� ũ�� �ش� node���
	/*
	if (aNodeArray[end] < plusNode)
	{
		checkTemp[oldNodeIndex] = true;
		for (k = 0; k < NUM_NODE; k++)
		{
			aNodeArray[i] = checkTemp[i];
		}
		oldNode = start;
		vRootList.clear();
		plusNode = 0;
		oldNodeIndex = 0;
	}
	*/



	for (i = 0; i < NUM_NODE; i++)
	{
		cout << aNodeArray[i] << " ";
	}
	cout << endl;
	cout << "minNode: " << minNode << endl;
	cout << "oldNodeIndex: " << oldNodeIndex << endl;
	cout << "plusNode: " << plusNode << endl;
	for (i = 0; i < NUM_NODE; i++)
	{
		cout << "check: " << check[i] << " ";
	}
	cout << endl;

	for (i = 0; i < vRootList.size(); i++) 
	{
		cout << "vRootList: " << vRootList[i]+1 << " ";
	}





}


