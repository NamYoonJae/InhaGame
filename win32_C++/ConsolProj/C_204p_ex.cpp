
#include "stdafx.h"
#include <conio.h>

//���� 204p �⺻����
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

		printf("������� %d��\n", baby);
	}
	else if (14 <= year && year <= 19) {
		oldBaby = bus - bus*0.25;

		printf("������� %d��\n", oldBaby);
	}
	else if (20 <= year && year <= 64) {
		adult = bus;

		printf("������� %d��\n", adult);
	}
	else {
		youngOldAdult = bus - bus*1.00;

		printf("������� %d��\n", youngOldAdult);
	}
}

