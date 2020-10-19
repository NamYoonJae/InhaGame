#include "stdafx.h"
#include <iostream>
#include <cmath>
/*
	chap 3. Q1. 비행기의 가속도 a와 이륙속도 v가 주어졌을 때,
	비행기가 이륙하기 위한 최소 활주 길이를 계산하는 프로그램을 작성하라

	길이 = v^2 / 2a

	사용자에게 미터당 초(m/s) 단위로 v와 미터/초^2(m/s^2) 단위로 가속도 a를 입력하도록 알려주고,
	최소 활주 길이를 출력하라
	ex) Speed and Accelerration :  60  3.5
		minimum runaway length : 512.286

*/

using namespace std;

void main(void) {

	float inputV = 0;	// 이륙속도
	float inputA = 0;	// 가속도
	float length = 0;
	cout << "이륙 속도를 미터당 초(m/s)를 입력하세요" << endl;
	cin >> inputV;

	cout << "가속도를 미터/초 단위로 입력하세요" << endl;
	cin >> inputA;

	length = pow(inputV,2) / (2*inputA);

	cout << "Speed and Accelerration : " << inputV << endl;
	cout << "minimum runaway lenth : " << length << endl;






}
