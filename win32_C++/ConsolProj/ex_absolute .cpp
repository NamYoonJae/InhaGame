#include "stdafx.h"
#include <conio.h>
#include <windows.h>

/*���밪�� ���ϴ� �Լ� ABS() �����϶�. (Ű���带 ���� �Է� �޴� ���� ���� ���� ���ϴ� ���α׷�)
ex)������ �Է��Ͻÿ� : -34
���� ���� 34�Դϴ�

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
	printf("���ڸ� �Է��Ͻÿ� : ");
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
	printf("���밪�� %d�Դϴ�", absolNum);

}
