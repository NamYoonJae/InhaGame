#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct  classMate
{

	int no;
	string name;
	struct classMate* pNext;

};

/*
Q1. �Է� ������ ������� ��ȣ ������� ���ĵ� ����Ʈ�� �����ϴ� ���α׷��� �ۼ��϶�.

	1. ����Ʈ �ʱ�ȭ
	2. ��� �߰�
		2.1 ���� �տ� �߰�
		2.2 �� �ڿ� �߰�
		2.3 ���̿� �߰�
	3. ��� ����
		3.1 ���� �� ��� ����
		3.2 �� �� ��� ����
		3.3 ���� ��� ����
	4. �˻�
		��ȣ�� �Է� �޾Ƽ� �ش� ��ȣ�� �̸� ���
	5. ���
		����Ʈ ��ü ����Ÿ ���

*/

void NodeAdd(classMate *pNode, classMate *head);



void main(void) {

	classMate *pNode = new classMate();
	classMate *head = NULL;

	
	int input = 0;
	cout << "1. ����Ʈ �ʱ�ȭ" << endl;
	cout << "2. ��� �߰�" << endl;
	cout << "3. ��� ����" << endl;
	cout << "4. �˻�" << endl;
	cout << "5. ���" << endl;

	cin >> input;

	switch (input)
	{
	case 1:
	{


	}
		break;

	case 2: 
	{
		NodeAdd(pNode, head);
	}

		break;

	case 3:

		break;

	case 4:

		break;

	case 5: 

		break;

	default:
		break;
	}
}

void NodeAdd(classMate *pNode, classMate *head)
{
	int noInput;
	string nameInput;
	cout << "��� ��ȣ �Է�: ";
	cin >> noInput;
	cout << endl;

	cout << "��� �̸� �Է�: ";
	cin >> nameInput;
	cout << endl;

	//ù ������ �Է�
	
	if (head == NULL)
	{
		head->pNext = pNode;
		pNode->no = noInput;
		pNode->name = nameInput;
		pNode->pNext = NULL;
		cout << "��� ���� �Ϸ�" << endl;
	}
	else 
	{
		cout << "�߰�" << endl;
	}
	

	cout << pNode->no << endl;
	cout << pNode->name << endl;


}
