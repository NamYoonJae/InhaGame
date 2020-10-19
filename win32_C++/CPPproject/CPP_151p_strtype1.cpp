#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main(void) {

	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";


	cout << "고양이과 동물 한 종을 입력하시오";
	cin >> charr1;

	cout << "고양이과의 또 다른 동물 한 종을 입력하시오";
	cin >> str1;

	cout << "아래 동물들은 모두 고양이과입니다 : \n";
	cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;

	cout << charr2 << "에서 3번째 글자 : " << charr2[2] << endl;
	cout << str2 << "에서 3번째 글자 : " << str2[2] << endl;

}