#include "stdafx.h"
#include <iostream>




using namespace std;

void main(void) {

	const int ArSize = 20;
	char name[ArSize];
	char desert[ArSize];

	cout << "이름을 입력하십시오 : \n";
	cin.getline(name, ArSize);
	cout << "좋아하는 디저트를 입력하십시오 : \n";
	cin.getline(desert, ArSize);
	cout << "맛있는" << desert;
	cout << "디저트를 준비하겠습니다." << name << "님!\n";

}