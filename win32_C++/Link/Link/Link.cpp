#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>


using namespace std;


struct classMate
{
	int no;
	string name;
	classMate*pNext;

};

void MainMenu();
void NodeAdd();
void reset(classMate *classMate);

string InsertNode(classMate *classMate);
string NodeDelete();
string NodeSearch();
void NodePrint();

classMate *head = new classMate;
classMate *temp;
string message;
classMate *temp2;


void main()
{
	reset(head);
	MainMenu();

}

void MainMenu()
{
	int n;
	cout << "[1] ��� �߰�" << endl;
	cout << "[2] ��� ����" << endl;
	cout << "[3] ��� �˻�" << endl;
	cout << "[4] ��� ���" << endl;
	cout << endl;

	cout << "�Է� > ";
	cin >> n;

	switch (n)
	{

	case 1:
		system("cls");
		NodeAdd();
		break;

	case 2:
		system("cls");
		NodeDelete();
		cout << message << endl;
		MainMenu();
		
		break;

	case 3:
		system("cls");
		NodeSearch();
		cout << message << endl;
		break;

	case 4:
		system("cls");
		NodePrint();
		break;



	default:
		break;
	}
}

void NodeAdd()
{
	classMate *newClassMate = new classMate;
	reset(newClassMate);

	cout << "no�� �Է��ϼ���." << endl;
	cout << "�Է� >";
	cin >> newClassMate->no;
	cout << endl;


	cout << "name�� �Է��ϼ���" << endl;
	cout << "�Է� >";
	cin >> newClassMate->name;
	cout << endl;

	//�Ӹ��� ������ ��� �����͸� ����� ����
	if (head->pNext == nullptr) 
	{
		head->pNext = newClassMate;
		message = "��� �߰� �Ϸ�: Front";
	}
	else
	{
		message = InsertNode(newClassMate);
	}
	
	cout << message << endl;
	Sleep(1000);

	system("cls");

	MainMenu();


	
}

void reset(classMate * classMate)
{
	classMate->no = 0;
	classMate->name = "";
	classMate->pNext = NULL;
}

string InsertNode(classMate * classMate)
{
	temp = head;

	while (temp->pNext != NULL)
	{
		if (classMate->no < temp->pNext->no)
		{
			classMate->pNext = temp->pNext;
			temp->pNext = classMate;

			message = "��� �߰� �Ϸ� : MID";
			return message;
		}
		else if (classMate->no == temp->pNext->no)
		{
			message = "��� �߰� ���� : ���� ��尡 �̹� �����մϴ�";
			return message;
		}


		temp = temp->pNext;
	}

	temp->pNext = classMate;
	return message = "��� �߰� �Ϸ� : Back";

}

string NodeDelete()
{
	int n = 0;
	cout << "������ ��� no�� �Է��ϼ���" << endl;
	cout << "�Է� > ";
	cin >> n;
	cout << endl;

	temp = head;

	int count = 0;

	while (temp->pNext != NULL)
	{
		temp = temp->pNext;
		count++;
	}

	temp = head;
	if (count == 1)
	{
		delete(temp->pNext);
		temp->pNext = NULL;
		message = "��� ���� �Ϸ�: Front / ��� �Ѱ� ������ ��";
		return message;
	}
	else
	{
		while (temp!= NULL) 
		{
			if (temp->no == n)
			{
				if (head->pNext->no == n)
				{
					temp->pNext = temp->pNext->pNext;

					delete(temp);

					message = "��� ���� �Ϸ�: Front/ ��� ������ ������ ��";
					return message;
				}

				else if (temp->pNext== NULL)
				{
					
					temp2->pNext = NULL;

					delete(temp->pNext);

					message = "��� ���� �Ϸ�: Back";
					return message;
				}
				else
				{
					
					temp2->pNext = temp2->pNext->pNext;

					delete(temp);
					
					message = "��� ���� �Ϸ�: Mid";
					return message;

				}//(head->pNext->no == n)
				

			}//(temp->pNext->no == n)

			temp2 = temp;
			temp = temp->pNext;

		}//while

		message = "��� ���� ����: �ش� ���� �������� �ʽ��ϴ�.";
		return message;
	}

}

string NodeSearch()
{
	int n = 0;
	cout << "�˻��� ��� ��ȣ�� �Է��ϼ���" << endl;
	cout << "�Է� >";
	cin >> n;

	system("cls");

	temp = head;

	while (temp != NULL)
	{
		if (temp->no == n) 
		{
			cout << "no: " << temp->no << endl;
			cout << "name: " << temp->name << endl;
			message = "��� �˻� �Ϸ�";
			return message;
		}

		temp = temp->pNext;
	}

	message = "�ش� ���� �������� �ʽ��ϴ�.";

	return message;

}

void NodePrint() 
{
	temp = head;

	while (temp != nullptr) 
	{
		cout << "no: " << temp->no << endl;
		cout << "name: " << temp->name << endl;
		temp = temp->pNext;
	}

	MainMenu();

}