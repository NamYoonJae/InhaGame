#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� ����
/*����ڿ��Լ� �� ���� ������ �Է¹޾� �� ������ �����ؼ�
�� ���̿� �����ϴ� �������� ���� ����ϴ� ���α׷��� �ۼ�*/

int main(void) {

	int num1 = 0;
	int num2 = 0;
	int temp = 0;
	int i = 0;
	int total = 0;

	scanf("%d%d", &num1, &num2);

	 if (num1 > num2) 
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	for (num1; num1 < num2 +1; num1++) 
	{
		total += num1;
	}

	printf("%d", total);

	return 0;
}