#include <stdio.h>
#include "stdafx.h"

//***** 일반 재귀 *****//
int FactorialRec(int n) {
	if (n == 1)
		return 1;
	else
		return n*FactorialRec(n - 1);
}

//***** 꼬리 재귀 *****//
int FactorialTailRec(int n, int res) {
	if (n == 1)
		return res;
	return FactorialTailRec(n - 1, res*n);
}

int FactorialTail(int n) {
	return FactorialTailRec(n, 1);
}

//***** 꼬리 재귀 -> 반복문 *****//
//***** 컴파일러 최적화시 변경된 코드 *****//
int FactorialTailRecLoop(int n) {
	int res = 1;
	for (; n > 0; n--) {
		res = res * n;
	}
	return res;
}

int main(int arc, char** argv) {
	printf("%d\n", FactorialRec(5));
	printf("%d\n", FactorialTail(5));
	printf("%d\n", FactorialTailRecLoop(5));
}