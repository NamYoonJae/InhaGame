#include "stdafx.h"
#include <conio.h>

int main(void) {


	//���� 117p �ʼ� �ǽ����� 04-01

	float x = 0; //�Ҽ��� �� ��° ���� ǥ���� ���̱⿡ �Ǽ������� ����
	float y = 0;

	printf("ù��° ������ �Է��ϼ���");

	scanf("%f*c", &x); //�Ǽ����̱⿡ %f ��� / *c ���� �Է� ������ ���� ���

	printf("�ι�° ������ �Է��ϼ���");

	scanf("%f*c", &y);


	printf("%0.2f\n", x + y); //�Ҽ��� �� ��° ���� ǥ���ϱ����� 0.2 �Ǵ� .2�� ����
	printf("%0.2f\n", x - y);
	printf("%0.2f\n", x * y);
	printf("%0.2f\n", x / y);

	return 0;
}

