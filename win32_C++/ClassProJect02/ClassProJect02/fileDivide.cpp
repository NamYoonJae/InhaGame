#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

/*
	Q1. 파일 내의 모든 바이트에 5를 더하도록 파일을 부호화(encoding) 하여라.
		사용자가 입력 파일 이름과 출력 파일 이름을 입력하면 
		입력 파일의 암호화된 버전을 출력 파일로 저장하는 프로그램을 작성하라.


	Q2. 암호화된 파일을 복호화(decoding)하는 프로그램을 작성하라.
		사용자가 입력 파일 이름과 출력 파일 이름을 입력하면 
		입력 파일의 암호가 풀린 버전을 출력 파일에 저장하라.


*/

using namespace std;

void main(void) {


	string inFileName;
	string outFileName;
	char temp;

	/*
	cout << "입력 파일 이름 입력: ";
	cin >> inFileName;
	cout << endl;

	cout << "출력 파일 이름 입력: ";
	cin >> outFileName;
	cout << endl;

	
	fstream fp1;
	fp1.open(inFileName, ios_base::in | ios_base::out);

	ofstream fp2;
	fp2.open(outFileName, ios_base::out);

	if (!fp1.is_open()) 
	{
		cout << "fp1 파일 열기 실패" << endl;
		exit(EXIT_FAILURE);
	}

	if (!fp2.is_open())
	{
		cout << "fp2 파일 열기 실패" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "암호화 시작" << endl;
	while (fp1.get(temp))
	{
		cout << "temp: " << temp << endl;
		temp = temp + 5;
		cout << "암호화 된 temp: "<< temp << endl;
		fp2.put(temp);
	}
	cout << "암호화 완료" << endl;

	fp1.close();
	fp2.close();
	*/

	cout << "암호화 된 파일 이름 입력: ";
	cin >> outFileName;
	cout << endl;

	cout << "복호화 할 파일 이름 입력: ";
	cin >> inFileName;
	cout << endl;

	fstream fp2;
	fp2.open(outFileName, ios_base::in | ios_base::out);

	ofstream fp1;
	fp1.open(inFileName, ios_base::out);

	if (!fp1.is_open())
	{
		cout << "fp1 파일 열기 실패" << endl;
		exit(EXIT_FAILURE);
	}

	if (!fp2.is_open())
	{
		cout << "fp2 파일 열기 실패" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "복호화 시작" << endl;
	while (fp2.get(temp))
	{
		cout << "temp: " << temp << endl;
		temp = temp - 5;
		cout << "복호화 된 temp: " << temp << endl;
		fp1.put(temp);
	}
	cout << "복호화 완료" << endl;

	fp2.close();
	fp1.close();
}