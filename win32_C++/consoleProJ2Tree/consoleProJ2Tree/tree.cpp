#include <iostream>
#include <string>


using namespace std;

typedef struct bnode 
{
	struct left;
	struct right;

} BinNode;



int Insert(int number);

void main(void) {

	int n;
	int input;

	cout << "[1] ����" << endl;
	cout << "[2] ����" << endl;
	cout << "[3] �˻�" << endl;
	cout << "[4] ���" << endl;
	cout << "[0] ����" << endl;


	switch (n)
	{
	case 0:
		break;

	case 1: 
		int number;

		cout << "���� �� �����͸� �Է�" << endl;
		cout << "��ȣ: ";
		cin >> number;

		Insert(number);
		

		break;

	case 2:
		break;

	case 3:

		break;

	case 4:
		break;

	default:
		break;
	}
}

int Insert(int number)
{


}
