#include "stdafx.h"
#include <conio.h>
#include <windows.h>

/*절대값을 구하는 함수 ABS() 구현하라. (키보드를 통해 입력 받는 값의 절대 값을 구하는 프로그램)
ex)정수를 입력하시오 : -34
절대 값은 34입니다

*/
int nInput();
int absol(int num);
void print(int absolNum);

int main(void) {

	int number =nInput();
	int absolNum = absol(number);
	print(absolNum);

	return 0;
}

int nInput() {
	int num = 0;
	printf("숫자를 입력하시오 : ");
	scanf("%d",&num);

	return num;
}

int absol(int num)
{
	int result = 0;
	if (num<0) 
	{

		result = num*-1;
	}
	else

		result = num;

	return result;
}

void print(int absolNum)
{
	printf("절대값은 %d입니다", absolNum);

}
