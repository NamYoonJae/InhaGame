
#include "stdafx.h"
#include <conio.h>

int main(void) {


	//���� 114~115p

	int x = 10;

	//int*int -> %d
	printf("%d\n", x * 10);

	//int * double ->��� �Ұ��� �ֳ��ϸ� ���°ݿ� ���Ͽ� double������ ���󰡱� ������ 
	printf("%d\n", x * 10.0);

	//int * int �� int���̸� �Ҽ����� ����ȴ�
	printf("%d\n", x / 10);

	//�Ҽ��� ���ϰ� ����ǹǷ� ��ǻ� ���� 2�� %f�� ����ϴ� ���̴�
	printf("%d\n", 5 / 2);

	//int / int �� int���̹Ƿ� %f�� ����� �� ����
	printf("%f\n", 5 / 2);

	//double / int �� double���̴�
	printf("%f\n", 5.0 / 2);

	return 0;
}

