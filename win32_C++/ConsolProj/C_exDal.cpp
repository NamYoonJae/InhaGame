#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//재귀함수 써서 한번 더 해보기
/*A는 달팽이를 키우고 있다
한달에 한번 새끼를 낳는다
새끼는 한달 후 어른이 돼서 새끼를 낳는다
달팽이가 1년만에 죽을리는 없다고 가정하고 달팽이가 매달 새끼를 낳으면 1년 후 전체 달팽이 수는 몇인지 구하시오
*/

//개월 수 입력

int monthInput();
int incredal(int dal, int month, int adult);


//메인
int main(void) {
	
	int adult = 0;
	int dal = 1;
	int month=monthInput();
	incredal(dal, month, adult);

	return 0;
}


//함수
int monthInput()
{
	int month = 0;
	printf("몇 개월 ? : ");
	scanf("%d",&month);
	return month;
}

int incredal(int dal, int month, int adult)
{
	int total = 0;
	int temp = 0;
	int i = 0;
	for (i = 0; i < month-1; i++) {
		int total = 0;
		temp = adult;
		adult = adult + dal;
		dal = temp;
	}
	total = adult + dal;
	printf("현재 총 달팽이는 %d 마리 입니다", total);

	return 0;
}


