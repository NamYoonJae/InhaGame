#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//������ �迭�� �迭 ������ ���ε� ����� ���� ���� �ٽ� �����ϱ�
int main(void) {
	int a = 10, b = 20, c = 30;
	int *pA[3] = { NULL, NULL, NULL }; //������ �迭

	int arr[2][3] = { 10,20,30,40,50,60 };
	int(*pArr)[3] = NULL;

	pA[0] = &a;
	pA[1] = &b;
	pA[2] = &c;

	printf("%x %x %x \n", &a, &b, &c);
	printf("%x %x %x \n", pA[0], &pA[1], &pA[2]);
	printf("%x %x %x \n", *(pA+ 0), *(pA+1),*(pA+2));
	//���� 3���� ���� ���� ���;��Ѵ� //�ι�°���� �ٸ��Գ���... �����ϱ�

	//�Ʒ����� �����ϴٰ� ����
	printf("%d %d %d \n", &a, &b, &c);
	printf("%d %d %d \n", pA[0], &pA[1], &pA[2]);
	printf("%d %d %d \n", **(pA + 0), **(pA + 1), **(pA + 2));


	pArr = arr;

	printf("%d %d %d \n", pArr[0][0], pArr[0][1], pArr[0][2]);
	printf("%d %d %d \n", pArr[0][0], pArr[0][1], pArr[0][2]);


	return 0;
}