#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//����Լ� �Ἥ �ѹ� �� �غ���
/*A�� �����̸� Ű��� �ִ�
�Ѵ޿� �ѹ� ������ ���´�
������ �Ѵ� �� ��� �ż� ������ ���´�
�����̰� 1�⸸�� �������� ���ٰ� �����ϰ� �����̰� �Ŵ� ������ ������ 1�� �� ��ü ������ ���� ������ ���Ͻÿ�
*/

//���� �� �Է�

int monthInput();
int incredal(int dal, int month, int adult);


//����
int main(void) {
	
	int adult = 0;
	int dal = 1;
	int month=monthInput();
	incredal(dal, month, adult);

	return 0;
}


//�Լ�
int monthInput()
{
	int month = 0;
	printf("�� ���� ? : ");
	scanf("%d",&month);
	return month;
}

int incredal(int dal, int month, int adult)
{
	int total = 0;
	int temp = 0;
	int i = 0;
	for (i = 0; i < month-1; i++) {
		int total = 0;
		temp = adult;
		adult = adult + dal;
		dal = temp;
	}
	total = adult + dal;
	printf("���� �� �����̴� %d ���� �Դϴ�", total);

	return 0;
}


