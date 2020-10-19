#include "stdafx.h"
#include <conio.h>


//교재 168p 최댓값 구하기
int main(void) {

	int nMax = 0;
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	a <= b ? (nMax = b) : (nMax = a);
	nMax <= c ? (nMax = c) : (nMax = b);

	printf("MAX : %d\n", nMax);

	return 0;
}

