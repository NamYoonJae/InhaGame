#include "stdafx.h"
#include <iostream>




using namespace std;

void main(void) {

	const int ArSize = 20;
	char name[ArSize];
	char desert[ArSize];

	cout << "�̸��� �Է��Ͻʽÿ� : \n";
	cin.getline(name, ArSize);
	cout << "�����ϴ� ����Ʈ�� �Է��Ͻʽÿ� : \n";
	cin.getline(desert, ArSize);
	cout << "���ִ�" << desert;
	cout << "����Ʈ�� �غ��ϰڽ��ϴ�." << name << "��!\n";

}