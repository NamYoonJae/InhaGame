#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� ���� ����
/*
����ڷκ��� ����ؼ� ������ �Է¹޴´�.
�� ���� ��� ���� ������
����ڰ� 0�� �Է��� ������ ��� �Ǿ���ϸ�,
0�� �ԷµǸ� �Էµ� ��� ������ ��������ϰ� ���α׷��� �����Ѵ�
*/


int main(void) {

	int nInput = 0;
	int result = 0;

	scanf("%d", &nInput);

	while (nInput!=0)
	{
		result = nInput + result;
		scanf("%d", &nInput);
	}

	printf("�� ���� %d �Դϴ�", result);


}