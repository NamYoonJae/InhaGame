
#include "stdafx.h"
#include <conio.h>

int main(void) {
	//���ΰ���
	//scanf �̿��Ͽ� �Է¹ް�
	// ��� 
	//>> no 1 88
	//>> no 2 99
	//>> no 3 33

	int num = 0;
	int i = 1;

	scanf("%d", &num);
	printf("no.%d %d\n", i++, num);

	scanf("%d", &num);
	printf("no.%d %d\n", i++, num);

	scanf("%d", &num);
	printf("no.%d %d\n", i++, num);

	return 0;

}

