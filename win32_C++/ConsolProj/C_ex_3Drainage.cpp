#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//개인 과제 제출
/*
사용자로부터 양의 정수를 하나 입력받는다.
그 수 만큼 3의 배수를 출력하는 프로그램을 작성하라.
*/
int main() {

	int number = 0;
	int i = 1;

	scanf("%d", &number);

	if (number < 0) 
	{
		printf("정수만 입력 가능합니다\n");
	}
	else if (i < number + 1) 
	{
		while (i < number+1)
		{
			printf("%d", 3 * i);
			++i;
		}
		
	}
	return 0;

}