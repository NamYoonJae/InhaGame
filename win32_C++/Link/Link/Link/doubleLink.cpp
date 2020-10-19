#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

struct classMate
{
	int no;
	string name;
	classMate *pNext;
	classMate *preView;
};

void reset(classMate *classMate);
void MainMenu();
void NodeAdd();


string InsertNode(classMate *classMate);
string NodeDelete();
string NodeSearch();

void NodePrint();

classMate *head = new classMate;
classMate *temp;
string message;

int nodeCount = 0;

void main(void) 
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
		MainMenu();
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

	if (head->pNext == NULL)
	{
		head->pNext = newClassMate;
		newClassMate->pNext = head;

		head->preView = newClassMate;
		newClassMate->preView = head;

		nodeCount++;
		message = "��� �߰� �Ϸ�: Front";
	}
	else
	{
		InsertNode(newClassMate);
	}

	cout << message << endl;
	Sleep(1000);

	system("cls");

	MainMenu();
}

void reset(classMate *classMate) 
{
	classMate->no = 0;
	classMate->name = "";
	classMate->pNext = NULL;
	classMate->preView = NULL;
}

string InsertNode(classMate *classMate) 
{
	temp = head;

	while (temp->pNext != head) 
	{
	
		if (classMate->no < temp->pNext->no)
		{
			classMate->pNext = temp->pNext;
			temp->pNext = classMate;

			temp->pNext->pNext->preView = classMate;
			classMate->preView = temp;

			nodeCount++;
			message = "��� �߰� �Ϸ� : MID";
			return message;
		}
		else if (classMate->no == temp->pNext->no)
		{
			message = "��� �߰� ���� : ���� ��尡 �̹� �����մϴ�";
			return message;
		}

		
		temp = temp->pNext;
	}//while (temp->pNext != NULL)

	temp->pNext->preView = classMate;
	classMate->preView = temp;


	classMate->pNext = temp->pNext;
	temp->pNext = classMate;

	nodeCount++;
	return message = "��� �߰� �Ϸ� : Back";

}

string NodeDelete() 
{
	int n = 0;
	classMate *temp2;


	cout << "������ ��� no�� �Է��ϼ���" << endl;
	cout << "�Է� > ";
	cin >> n;
	cout << endl;

	temp = head;

	if (nodeCount == 1)
	{
		delete(temp->pNext);
		temp->pNext = NULL;
		message = "��� ���� �Ϸ�: Front / ��� �Ѱ� ������ ��";
		nodeCount--;
		return message;
	}
	else 
	{
		while (temp != NULL)
		{
			if (temp->no == n)
			{
				if (head->pNext->no == n)
				{
					temp2->pNext = temp->pNext;
					temp->pNext->preView = temp2;
					delete(temp);
					
					message = "��� ���� �Ϸ�: Front/ ��� ������ ������ ��";
					nodeCount--;
					return message;
				}

				else if (head->preView->no == n)
				{
					head->preView = temp2;
					temp2->pNext = head;

					delete(temp);

					nodeCount--;
					message = "��� ���� �Ϸ�: Back";
					return message;
				}
				else
				{
					temp2->pNext = temp->pNext;
					temp->pNext->preView = temp2;

					delete(temp);
					nodeCount--;
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

	for (int i = 0; i <nodeCount+1; i++) 
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

	for (int i = 0; i < nodeCount + 1; i++)
	{
		cout << "no: " << temp->no << endl;
		cout << "name: " << temp->name << endl;
		cout << "pNext: " << temp->pNext << endl;
		cout << "preView: " << temp->preView << endl;
		cout << endl;
		temp = temp->pNext;
	}

	MainMenu();
}