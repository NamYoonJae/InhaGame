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
	cout << "[1] 노드 추가" << endl;
	cout << "[2] 노드 삭제" << endl;
	cout << "[3] 노드 검색" << endl;
	cout << "[4] 노드 출력" << endl;
	cout << endl;

	cout << "입력 > ";
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

	cout << "no를 입력하세요." << endl;
	cout << "입력 >";
	cin >> newClassMate->no;
	cout << endl;


	cout << "name을 입력하세요" << endl;
	cout << "입력 >";
	cin >> newClassMate->name;
	cout << endl;

	//머리가 없으면 헤드 포인터를 여기로 저장
	if (head->pNext == nullptr) 
	{
		head->pNext = newClassMate;
		message = "노드 추가 완료: Front";
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

			message = "노드 추가 완료 : MID";
			return message;
		}
		else if (classMate->no == temp->pNext->no)
		{
			message = "노드 추가 실패 : 같은 노드가 이미 존재합니다";
			return message;
		}


		temp = temp->pNext;
	}

	temp->pNext = classMate;
	return message = "노드 추가 완료 : Back";

}

string NodeDelete()
{
	int n = 0;
	cout << "삭제할 노드 no를 입력하세요" << endl;
	cout << "입력 > ";
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
		message = "노드 삭제 완료: Front / 노드 한개 존재할 떄";
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

					message = "노드 삭제 완료: Front/ 노드 여러개 존재할 때";
					return message;
				}

				else if (temp->pNext== NULL)
				{
					
					temp2->pNext = NULL;

					delete(temp->pNext);

					message = "노드 삭제 완료: Back";
					return message;
				}
				else
				{
					
					temp2->pNext = temp2->pNext->pNext;

					delete(temp);
					
					message = "노드 삭제 완료: Mid";
					return message;

				}//(head->pNext->no == n)
				

			}//(temp->pNext->no == n)

			temp2 = temp;
			temp = temp->pNext;

		}//while

		message = "노드 삭제 실패: 해당 노드는 존재하지 않습니다.";
		return message;
	}

}

string NodeSearch()
{
	int n = 0;
	cout << "검색할 노드 번호를 입력하세요" << endl;
	cout << "입력 >";
	cin >> n;

	system("cls");

	temp = head;

	while (temp != NULL)
	{
		if (temp->no == n) 
		{
			cout << "no: " << temp->no << endl;
			cout << "name: " << temp->name << endl;
			message = "노드 검색 완료";
			return message;
		}

		temp = temp->pNext;
	}

	message = "해당 노드는 존재하지 않습니다.";

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