
#include "stdafx.h"
#include <conio.h>

//교재 204p 기본문제
int main(void) {

	int bus = 1000;
	int year = 0;

	int baby = 0;
	int oldBaby = 0;
	int adult = 0;
	int youngOldAdult = 0;

	scanf("%d", &year);

	if (4 <= year && year <= 13) {
		baby = bus - bus*0.50;

		printf("최종요금 %d원\n", baby);
	}
	else if (14 <= year && year <= 19) {
		oldBaby = bus - bus*0.25;

		printf("최종요금 %d원\n", oldBaby);
	}
	else if (20 <= year && year <= 64) {
		adult = bus;

		printf("최종요금 %d원\n", adult);
	}
	else {
		youngOldAdult = bus - bus*1.00;

		printf("최종요금 %d원\n", youngOldAdult);
	}
}

