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

	cout << "[1] 삽입" << endl;
	cout << "[2] 삭제" << endl;
	cout << "[3] 검색" << endl;
	cout << "[4] 출력" << endl;
	cout << "[0] 종료" << endl;


	switch (n)
	{
	case 0:
		break;

	case 1: 
		int number;

		cout << "삽입 할 데이터를 입력" << endl;
		cout << "번호: ";
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
