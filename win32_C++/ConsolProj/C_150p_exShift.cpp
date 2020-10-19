
#include "stdafx.h"
#include <conio.h>

int main(void) {

	//개인문제
	//문제 // 3*8/4 를 *과 / 를 쓰지 않고 계산하기
	//2진수 비트에서 <<1 하면 왼쪽으로 비트가 밀리니 2곱하기는 격이다 >>1은 2를 나누는 격

	int x = 3;

	printf("%d\n", x << 3 >> 2);

	return 0;
}

