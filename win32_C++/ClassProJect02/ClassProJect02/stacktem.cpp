#include "stdafx.h"
#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"

using namespace std;

void main(void) {

	Stack<string> st;
	char ch;
	string po;
	cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, \n" << "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch)) 
		{
			cout << '\a';
			continue;
		}

		switch (ch)
		{
		case 'A':
		case 'a': cout << "�߰��� �ֹ����� ��ȣ�� �Է��Ͻʽÿ� : ";
			cin >> po;
			if (st.isfull())
				cout << "������ ���� �� �ֽ��ϴ�.\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "������ ����ֽ��ϴ�.\n";
			else {
				st.pop(po);
				cout << "#" << "po << �ֹ����� ó���߽��ϴ�.\n";
				break;
			}
		}
		cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, \n" << "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	}
	cout << "���α׷��� �����մϴ�. \n";

}