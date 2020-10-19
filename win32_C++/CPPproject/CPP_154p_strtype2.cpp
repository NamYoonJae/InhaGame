#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main(void) {

	string s1 = "penguin";
	string s2, s3;

	cout << "string 객체를 string 객체에 대입할 수 있다 : s2 = s1\n";
	s2 = s1;

	cout << "s1 : " << s1 << ", s2" << s2 << endl;
	cout << "string 객체에 c스타일 문자열을 대입 할 수 있다.\n";
	cout << "s2 = \"buzzard\"\n";
	
	cout << "s2 : " << s2 << endl;
	cout << "string 객체들을 결합 할 수 있다 : s3 = s1 + s2\n";
	s3 = s1 + s2;

	cout << "s3 :" << s3 << endl;
	cout << "string 객체들을 추가 할 수 있다.\n";
	s1 += s2;

	cout << "s1 += s2 ->> s1 = " << s1 << endl;
	s2 += "for a day";
	cout << "s2 += \"for a day\" --> s2 = " << s2 << endl;

}