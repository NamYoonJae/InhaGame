#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/*
	로또 만들기
	1~45의 숫자 중 랜덤하게 6 개 뽑기

	Lotto함수 작성
	1. 매개변수를 복권에 표시된 자리 수
	2. 매개변수는 복권 구입자가 임의로 선택한 자리들의 수여야한다.

	함수는 임의로 선택한 수들이 정렬된 순서로 저장되어 있는 vector<int> 객체를 리턴해야한다.

*/

using namespace std;

vector<int> Lotto(int lottoMax, int draw);

void main(void) {

	int lottoMax = 0;
	int draw = 0;
	int i = 0;
	cout << "복권 max 숫자 입력: ";
	cin >> lottoMax;
	cout << endl;

	cout << "뽑을 숫자 갯수 입력: ";
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

	random_shuffle(v.begin(), v.end());	//#include <algorithm> 헤더 추가해줘야한다

	vector<int> v2;

	for (i = 0; i < draw; i++) 
	{	
		v2.push_back(v[i]);
	}



	return v2;
}
