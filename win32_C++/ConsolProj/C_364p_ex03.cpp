#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� 364p 03�� ����
int nInput();
int nInputMoney();
int nInputYears();
void yearDisc(int a, int b);

//����
int main(void) {


	int basicMoney = 0;
	int years = 0;
	int resultDis = 0;

	basicMoney = nInputMoney(); 
	years = nInputYears();
	yearDisc(basicMoney, years);


	return 0;
}

//�Լ�
int nInputMoney() 
{
	int basicMoney = 0;
	printf("�⺻ ����� �Է��ϼ���. : ", basicMoney);
	scanf("%d", &basicMoney);
	return basicMoney;
}

int nInputYears()
{	
	int years = 0;
	printf("���̸� �Է��ϼ���. : ", years);
	scanf("%d", &years);
	return years;
}

void yearDisc(int a, int b)
{	

	int resultDis;

	if (0 <= b && b< 4) {
		resultDis= a - (a*1.00);

	}else if (4 <= b && b < 14) {
		resultDis = a - (a*0.50);

	}else if (14 <= b && b< 20) {
		resultDis = a - (a*0.75);

	}
	else
	{
		resultDis = a;
	}
	
	printf("��� = %d\n",resultDis);
}
