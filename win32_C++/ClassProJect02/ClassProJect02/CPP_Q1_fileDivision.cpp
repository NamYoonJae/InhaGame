#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

/*
	Q1. 용량이 큰 파일을 작은 용량으로 분할해서 작은 단위의 파일로 나누는 유틸리티 프로그램을 작성하라.
	사용자로 부터 소스 파일을 입력 받은 후, 각각 분할 된 작은 파일의 바이트 값을 입력 받아야 한다.

	ex) Enter file name : test.zip
		Enter file size : 1024
		-> File test.zip.0
		-> File test.zip.1
		......
		Split Done.

	Q2. 사용자로 부터 소스 파일의 개수, 소스 파일의 이름, 목적 파일 이름을 입력받아 새로운 하나의 파일로 파일들을 조합하는 프로그래밍을 작성하라.
	
	ex) Enter file number : 2
		Enter source file : test.zip.0
		Enter source file : test.zip.1
		Enter target file : temp.zip
		...
		combine Done!

*/
using namespace std;

void main(void) {

	/*
		파일 이름 입력
		파일 사이즈 입력
	*/

	string fileName;
	int fileSize = 0;
	int fileNum = 0;
	char *readData = new char[fileSize];


	cout << "파일 이름 입력 : ";
	cin >> fileName;
	cout << "파일 사이즈 입력 : ";
	cin >> fileSize;

	fstream file;
	file.open(fileName, ios_base::in, ios_base::out);
	
	if (!file.is_open())
	{
		cout << "파일 열기 실패" << endl;
	}

	while (file.read(readData,fileSize))
	{
		ofstream out(fileName + '_'+ to_string(fileNum), ios_base::binary | ios_base::out);
		fileNum++;
		out.write(readData, fileSize);
		out.close();
	}
	file.clear();

	streamsize lastReadSize = file.gcount();
	if (lastReadSize != 0)
	{
		file.seekg(lastReadSize * -1, file.end);
		file.read(readData, lastReadSize);
		ofstream out(fileName + '_'+ to_string(fileNum), ios_base::binary | ios_base::out);
		out.write(readData, lastReadSize);
		out.close();
	}
	file.close();



}