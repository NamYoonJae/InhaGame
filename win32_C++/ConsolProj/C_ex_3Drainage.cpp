#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� ���� ����
/*
����ڷκ��� ���� ������ �ϳ� �Է¹޴´�.
�� �� ��ŭ 3�� ����� ����ϴ� ���α׷��� �ۼ��϶�.
*/
int main() {

	int number = 0;
	int i = 1;

	scanf("%d", &number);

	if (number < 0) 
	{
		printf("������ �Է� �����մϴ�\n");
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