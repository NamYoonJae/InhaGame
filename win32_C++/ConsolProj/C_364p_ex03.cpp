#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 364p 03번 문제
int nInput();
int nInputMoney();
int nInputYears();
void yearDisc(int a, int b);

//메인
int main(void) {


	int basicMoney = 0;
	int years = 0;
	int resultDis = 0;

	basicMoney = nInputMoney(); 
	years = nInputYears();
	yearDisc(basicMoney, years);


	return 0;
}

//함수
int nInputMoney() 
{
	int basicMoney = 0;
	printf("기본 요금을 입력하세요. : ", basicMoney);
	scanf("%d", &basicMoney);
	return basicMoney;
}

int nInputYears()
{	
	int years = 0;
	printf("나이를 입력하세요. : ", years);
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
	
	printf("요금 = %d\n",resultDis);
}
