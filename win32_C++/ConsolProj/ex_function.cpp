#include "stdafx.h"
#include <conio.h>
#include <windows.h>

/*
	사칙연산 프로그램을 함수 호출 형태로 만들어라
	1. 메뉴 출력
	2. 값 입력
	3. 연산
	4. 결과 출력

	각각 함수로 만들고 호출해서 사용할 수 있도록 할 것

*/

int menu();
void nInput(int *num1, int *num2);
int howResult(int num1, int num2, int how);
void printResult(int result);

int main(void) {

	while (1) 
	{
		int how = menu();//셈이 어떤건지 호출해서 how에 담음

		int num1;
		int num2;

		nInput(&num1, &num2); //두개의 값 입력받을 함수 호출
		int result = howResult(num1, num2, how);

		printResult(result);
	}

	return 0;
}

int menu()
{
	int how = 0;
	printf("1.덧셈\n2.뺄셈\n3.곱셈\n4.나눗셈\n");

	scanf("%d", &how);
	return how;
}


void nInput( int *num1, int *num2) //입력하는 두 수
{

	printf("두 개의 숫자를 입력하세요.\n");
	scanf("%d %d", num1, num2);

}

int howResult(int num1, int num2, int how) 
{	
	int result = 0;
	if (how == 1)
	{
		int sum(int num1, int num2);
		result = num1 + num2;
	}
	else if (how ==2) 
	{
		result = num1 - num2;
	}
	else if (how == 3) {
		result = num1 * num2;
	}

	else if (how ==4) {
		result = num1/num2;
	}
	return result;
}


void printResult(int result)
{
	printf("결과 : %d\n\n", result);
}