#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� ���� ����
/*
�Է¹��� ������ ����� ����ϴ� ���α׷��� �ۼ�
1. ���� �� ���� ������ �Է� �� ������ �����, �� �� ��ŭ �Է� �޴´�.
2. ��� ���� �Ҽ��� ���� 2�ڸ����� ����Ѵ�.
*/

int main(void) {

	int howNum = 0;
	int nInput = 0;
	int i = 0;
	int total = 0;

	printf("�� ���� ������ �Է��Ͻðڽ��ϱ� ? ");
	scanf("%d", &howNum);	//���� �Է¹޴´�.

	while (i < howNum)	//�Է��� ����ŭ �ݺ��Ѵ�
	{
		scanf("%d", &nInput);
		i++;
		total += nInput; //�ݺ��ϸ鼭 total�� ��� ���Ѵ�
	}

	printf("%.2f", double(total / i));


	return 0;
}