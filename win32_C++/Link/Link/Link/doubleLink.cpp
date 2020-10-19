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

	cout << "no를 입력하세요." << endl;
	cout << "입력 >";
	cin >> newClassMate->no;
	cout << endl;


	cout << "name을 입력하세요" << endl;
	cout << "입력 >";
	cin >> newClassMate->name;
	cout << endl;

	if (head->pNext == NULL)
	{
		head->pNext = newClassMate;
		newClassMate->pNext = head;

		head->preView = newClassMate;
		newClassMate->preView = head;

		nodeCount++;
		message = "노드 추가 완료: Front";
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
			message = "노드 추가 완료 : MID";
			return message;
		}
		else if (classMate->no == temp->pNext->no)
		{
			message = "노드 추가 실패 : 같은 노드가 이미 존재합니다";
			return message;
		}

		
		temp = temp->pNext;
	}//while (temp->pNext != NULL)

	temp->pNext->preView = classMate;
	classMate->preView = temp;


	classMate->pNext = temp->pNext;
	temp->pNext = classMate;

	nodeCount++;
	return message = "노드 추가 완료 : Back";

}

string NodeDelete() 
{
	int n = 0;
	classMate *temp2;


	cout << "삭제할 노드 no를 입력하세요" << endl;
	cout << "입력 > ";
	cin >> n;
	cout << endl;

	temp = head;

	if (nodeCount == 1)
	{
		delete(temp->pNext);
		temp->pNext = NULL;
		message = "노드 삭제 완료: Front / 노드 한개 존재할 떄";
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
					
					message = "노드 삭제 완료: Front/ 노드 여러개 존재할 때";
					nodeCount--;
					return message;
				}

				else if (head->preView->no == n)
				{
					head->preView = temp2;
					temp2->pNext = head;

					delete(temp);

					nodeCount--;
					message = "노드 삭제 완료: Back";
					return message;
				}
				else
				{
					temp2->pNext = temp->pNext;
					temp->pNext->preView = temp2;

					delete(temp);
					nodeCount--;
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

	for (int i = 0; i <nodeCount+1; i++) 
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