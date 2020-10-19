// CPPproject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
//C++에서 사용하는 입출력이다 c에서는 stdio 였었다
//구버전은 h 가 붙는데 신버전은 안붙는다

int main()
{
	//printf("C++ World!\n");

	//std::cout << "C++ World!!"; //메세지 출력방식이다 //std = 기능을 모아놓은 집합체
	//std::cout << std::endl; //개행하고 출력

	//이렇게 사용 가능하다 만약 using namespace가 없을 경우 cout는 인식하지 못한다.
	using namespace std;
	cout << "C++ World!!";
	cout << std::endl;

    return 0;
}

