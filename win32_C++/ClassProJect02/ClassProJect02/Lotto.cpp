#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/*
	�ζ� �����
	1~45�� ���� �� �����ϰ� 6 �� �̱�

	Lotto�Լ� �ۼ�
	1. �Ű������� ���ǿ� ǥ�õ� �ڸ� ��
	2. �Ű������� ���� �����ڰ� ���Ƿ� ������ �ڸ����� �������Ѵ�.

	�Լ��� ���Ƿ� ������ ������ ���ĵ� ������ ����Ǿ� �ִ� vector<int> ��ü�� �����ؾ��Ѵ�.

*/

using namespace std;

vector<int> Lotto(int lottoMax, int draw);

void main(void) {

	int lottoMax = 0;
	int draw = 0;
	int i = 0;
	cout << "���� max ���� �Է�: ";
	cin >> lottoMax;
	cout << endl;

	cout << "���� ���� ���� �Է�: ";
	cin >> draw;
	cout << endl;

	vector<int> winners;
	winners = Lotto(lottoMax, draw);

	for (i = 0; i < draw; i++) 
	{
		cout << winners[i] << " ";
	}

}

vector<int> Lotto(int lottoMax, int draw)
{
	vector<int> v;
	int i = 0;
	int n = 1;

	for (i = 0; i < lottoMax; i++) 
	{
		v.push_back(n);
		n++;
	}

	random_shuffle(v.begin(), v.end());	//#include <algorithm> ��� �߰�������Ѵ�

	vector<int> v2;

	for (i = 0; i < draw; i++) 
	{	
		v2.push_back(v[i]);
	}



	return v2;
}
