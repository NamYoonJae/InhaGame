#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� 364p 3�� ����
int getMoney();
int getYears();
int discount(int basicMoney, int years);
void view(int resultMoney);

//����
int main(void) {

	int basicMoney = getMoney();
	int years = getYears();
	int resultMoney = discount(basicMoney, years);
	int view(resultMoney);

	return 0;
}

//�Լ�
int getMoney()
{
	int basicMoney = 0;
	printf("�⺻ ����� �Է��ϼ��� : ");
	scanf("%d", &basicMoney);
	return basicMoney;
}

int getYears()
{
	int years = 0;
	printf("���̸� �Է��ϼ��� : ");

	scanf("%d", &years);
	return years;
}

int discount(int basicMoney, int years)
{
	int resultMoney = 0;
	if (0 <= years && years < 4)
	{
		resultMoney = basicMoney - (basicMoney * 1.0);
	}
	else if (3 <= years && years < 14)
	{
		resultMoney = basicMoney - (basicMoney * 0.50);
	}
	else if (14 <= years && years < 20)
	{
		resultMoney = basicMoney - (basicMoney * 0.75);
	}
	else
		resultMoney = basicMoney;

	printf("discount �Լ� ��� �� %d", resultMoney);

	return resultMoney;
}

void view(int resultMoney)
{
	printf("������� %d�� �Դϴ�. ", resultMoney);
}


