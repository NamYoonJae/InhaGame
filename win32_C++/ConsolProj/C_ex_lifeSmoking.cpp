
#include "stdafx.h"
#include <conio.h>


int main(void) {
	int limitLife = 100 * 365 * 24 * 60; //인간 100년 수명(분) 52,560,000 분
	int todaySmoking = 0; //하루에 몇 개피 피는지(개당 2분)

	int breakLife = 0; //단축 수명(총 분)
	int mLimitLife = 0; //기대 수명(총 분)

	int nMlife = 0; //단축 수명 (분)
	int nHLife = 0; //단축 수명 (시간)
	int nDayLife = 0; //단축 시간(일)
	int nMonLife = 0; //단축 시간(달)
	int nYearLife = 0; //단축 시간(년)

	int mLife = 0;	//기대 수명 (분)
	int hLife = 0; //기대 수명(시간)
	int dayLife = 0; //기대 수명 (일)
	int monLife = 0; //기대 수명(달)
	int yearLife = 0; //기대 수명(년)



	printf("하루에 피는 담배는?");

	scanf("%d", &todaySmoking);

	breakLife = todaySmoking * 2 * 365 * 20; //1개비당 2분 *  1년 * 20년피우면 깍이는 수명(분)으로 표현
	printf("단축 수명 %d분 입니다\n", breakLife);

	mLimitLife = limitLife - breakLife;
	printf("기대 수명 %d분 입니다\n", mLimitLife);



	//단축 수명
	nYearLife = breakLife / (60 * 24 * 30.41 * 12);
	nMonLife = (breakLife % int(60 * 24 * 30.41666666666667 * 12)) / (60 * 24 * 30.41666666666667); //기대 수명(분) -> 개월
	nDayLife = (breakLife % int(60 * 24 * 30.41666666666667 * 12)) % int(60 * 24 * 30.41666666666667) / (60 * 24); //기대 수명(분) -> 일
	nHLife = (breakLife % int(60 * 24 * 30.41666666666667 * 12)) % int(60 * 24 * 30.41666666666667) % (60 * 24) / 60; //기대 수명(분) -> 시간
	nMlife = (breakLife % int(60 * 24 * 30.41666666666667 * 12)) % int(60 * 24 * 30.41666666666667) % (60 * 24) % 60; //기대 수명(분)



	 //기대 수명
	yearLife = mLimitLife / (60 * 24 * 30.41 * 12);
	monLife = (mLimitLife % int(60 * 24 * 30.41666666666667 * 12)) / (60 * 24 * 30.41666666666667); //기대 수명(분) -> 개월
	dayLife = (mLimitLife % int(60 * 24 * 30.41666666666667 * 12)) % int(60 * 24 * 30.41666666666667) / (60 * 24); //기대 수명(분) -> 일
	hLife = (mLimitLife % int(60 * 24 * 30.41666666666667 * 12)) % int(60 * 24 * 30.41666666666667) % (60 * 24) / 60; //기대 수명(분) -> 시간
	mLife = (mLimitLife % int(60 * 24 * 30.41666666666667 * 12)) % int(60 * 24 * 30.41666666666667) % (60 * 24) % 60; //기대 수명(분)


	printf("단축 수명 %d년 %d개월 %d일 %d시간 %d분 입니다\n", nYearLife, nMonLife, nDayLife, nHLife, nMlife);
	printf("기대 수명 %d년 %d개월 %d일 %d시간 %d분 입니다\n", yearLife, monLife, dayLife, hLife, mLife);


	return 0;


}

