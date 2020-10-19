#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 364p 3번 문제
int getMoney();
int getYears();
int discount(int basicMoney, int years);
void view(int resultMoney);

//메인
int main(void) {

	int basicMoney = getMoney();
	int years = getYears();
	int resultMoney = discount(basicMoney, years);
	int view(resultMoney);

	return 0;
}

//함수
int getMoney()
{
	int basicMoney = 0;
	printf("기본 요금을 입력하세요 : ");
	scanf("%d", &basicMoney);
	return basicMoney;
}

int getYears()
{
	int years = 0;
	printf("나이를 입력하세요 : ");

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

	printf("discount 함수 결과 값 %d", resultMoney);

	return resultMoney;
}

void view(int resultMoney)
{
	printf("최종요금 %d원 입니다. ", resultMoney);
}


