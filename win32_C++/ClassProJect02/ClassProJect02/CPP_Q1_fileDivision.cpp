#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

/*
	Q1. �뷮�� ū ������ ���� �뷮���� �����ؼ� ���� ������ ���Ϸ� ������ ��ƿ��Ƽ ���α׷��� �ۼ��϶�.
	����ڷ� ���� �ҽ� ������ �Է� ���� ��, ���� ���� �� ���� ������ ����Ʈ ���� �Է� �޾ƾ� �Ѵ�.

	ex) Enter file name : test.zip
		Enter file size : 1024
		-> File test.zip.0
		-> File test.zip.1
		......
		Split Done.

	Q2. ����ڷ� ���� �ҽ� ������ ����, �ҽ� ������ �̸�, ���� ���� �̸��� �Է¹޾� ���ο� �ϳ��� ���Ϸ� ���ϵ��� �����ϴ� ���α׷����� �ۼ��϶�.
	
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
		���� �̸� �Է�
		���� ������ �Է�
	*/

	string fileName;
	int fileSize = 0;
	int fileNum = 0;
	char *readData = new char[fileSize];


	cout << "���� �̸� �Է� : ";
	cin >> fileName;
	cout << "���� ������ �Է� : ";
	cin >> fileSize;

	fstream file;
	file.open(fileName, ios_base::in, ios_base::out);
	
	if (!file.is_open())
	{
		cout << "���� ���� ����" << endl;
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