// virus.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void main()
{
	int infection = 0;
	int virusDrainage = 0;
	int time = 0;

	cout << "초기감염자: " << endl;
	cin >> infection;

	cout << "바이러스 시간당 증가 배수: " << endl;
	cin >> virusDrainage;

	cout << "바이러스가 퍼져나간 시간: " << endl;
	cin >> time;

	cout << "결과: " << infection * pow(virusDrainage, time) << endl;

	long long int result1 = infection * pow(virusDrainage, time);
	long long int result2 = result1 % 1000000007;

	cout << "요구 결과: " << result2 << endl;
    


}

