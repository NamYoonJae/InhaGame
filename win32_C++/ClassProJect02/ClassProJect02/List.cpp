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
Q1. 입력 순서와 상관없이 번호 순서대로 정렬된 리스트를 구현하는 프로그램을 작성하라.

	1. 리스트 초기화
	2. 노드 추가
		2.1 제일 앞에 추가
		2.2 맨 뒤에 추가
		2.3 사이에 추가
	3. 노드 삭제
		3.1 제일 앞 노드 삭제
		3.2 맨 뒤 노드 삭제
		3.3 사이 노드 삭제
	4. 검색
		번호를 입력 받아서 해당 번호의 이름 출력
	5. 출력
		리스트 전체 데이타 출력

*/

void NodeAdd(classMate *pNode, classMate *head);



void main(void) {

	classMate *pNode = new classMate();
	classMate *head = NULL;

	
	int input = 0;
	cout << "1. 리스트 초기화" << endl;
	cout << "2. 노드 추가" << endl;
	cout << "3. 노드 삭제" << endl;
	cout << "4. 검색" << endl;
	cout << "5. 출력" << endl;

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
	cout << "노드 번호 입력: ";
	cin >> noInput;
	cout << endl;

	cout << "노드 이름 입력: ";
	cin >> nameInput;
	cout << endl;

	//첫 데이터 입력
	
	if (head == NULL)
	{
		head->pNext = pNode;
		pNode->no = noInput;
		pNode->name = nameInput;
		pNode->pNext = NULL;
		cout << "헤드 생성 완료" << endl;
	}
	else 
	{
		cout << "추가" << endl;
	}
	

	cout << pNode->no << endl;
	cout << pNode->name << endl;


}
