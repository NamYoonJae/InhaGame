#include "stdafx.h"
#include <conio.h>
#include <windows.h>

/*
	��Ģ���� ���α׷��� �Լ� ȣ�� ���·� ������
	1. �޴� ���
	2. �� �Է�
	3. ����
	4. ��� ���

	���� �Լ��� ����� ȣ���ؼ� ����� �� �ֵ��� �� ��

*/

int menu();
void nInput(int *num1, int *num2);
int howResult(int num1, int num2, int how);
void printResult(int result);

int main(void) {

	while (1) 
	{
		int how = menu();//���� ����� ȣ���ؼ� how�� ����

		int num1;
		int num2;

		nInput(&num1, &num2); //�ΰ��� �� �Է¹��� �Լ� ȣ��
		int result = howResult(num1, num2, how);

		printResult(result);
	}

	return 0;
}

int menu()
{
	int how = 0;
	printf("1.����\n2.����\n3.����\n4.������\n");

	scanf("%d", &how);
	return how;
}


void nInput( int *num1, int *num2) //�Է��ϴ� �� ��
{

	printf("�� ���� ���ڸ� �Է��ϼ���.\n");
	scanf("%d %d", num1, num2);

}

int howResult(int num1, int num2, int how) 
{	
	int result = 0;
	if (how == 1)
	{
		int sum(int num1, int num2);
		result = num1 + num2;
	}
	else if (how ==2) 
	{
		result = num1 - num2;
	}
	else if (how == 3) {
		result = num1 * num2;
	}

	else if (how ==4) {
		result = num1/num2;
	}
	return result;
}


void printResult(int result)
{
	printf("��� : %d\n\n", result);
}