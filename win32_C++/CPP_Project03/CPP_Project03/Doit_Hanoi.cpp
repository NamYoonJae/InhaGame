#include "stdafx.h"
#include <stack>
#include <iostream>
#include <string>



using namespace std;

stack<int> A;
stack<int> B;
stack<int> C;


void main(void) {
	
	int hanoi = 0;
	int i = 0;
	cout << "몇 개의 원반 을 만드시겠습니까 ? : ";
	cin >> hanoi;

	for (i = hanoi; i > 0 ; i--) 
	{
		A.push(i);
	}

	if (hanoi % 2 == 0) //짝수 일 때
	{
		B.push(A.top());
		A.pop();

		A.pop();
		C.push(A.top());


	}
	else//홀수 일 떄
	{
		C.push(A.top());
		A.pop();

		B.push(A.top());
		A.pop();

		B.push(C.top());
		C.pop();

		C.push(A.top());
		A.pop();

		A.push(B.top());
		B.pop();

		C.push(B.top());
		B.pop();

		C.push(A.top());
		A.pop();
	}



	//stack 확인
	while (A.empty() != true)
	{
		cout <<A.top() << endl;
		A.pop();
	}
	cout << "A" << endl;
	cout << endl;

	while (B.empty() != true)
	{
		cout << B.top() << endl;
		B.pop();
	}
	cout << "B" << endl;
	cout << endl;

	while (C.empty() != true)
	{
		cout << C.top() << endl;
		C.pop();
	}
	cout << "C" << endl;
	cout << endl;
}