#include "stdafx.h"
#include <conio.h>
#include <windows.h>

int main(void) {

	int array[3] = { 10, 20, 30 };
	/*
	printf("%x %x %x\n", array, array + 0, &array[0]);
	printf("%x %x \n", array + 1, &array[1]);
	printf("%x %x \n", array + 2, &array[2]);
	//&array[0]) array[0]�� ù��° �ּ�

	printf("%d %d %d \n", sizeof(array), sizeof(array[0]), sizeof(array[1]));
	//array �迭�� ��ü ũ�� // int�� 3�� ������ �����Ƿ� ��� 12 �� ��µ�
	//array 0��°�� ũ�� //4�� ��� ��
	//array 1��°�� ũ�� // 4�� ��� ��
	*/


	//�迭�� �ּҸ� ��Ÿ���� ����� �ٸ��� �غ���
	printf("%d %d %d \n", *array, *(array+0), *&array[0]);
	printf("%d %d \n", *(array + 1), *&array[1]);
	printf("%d %d \n", *(array + 2), *&array[2]);

	/*
	*(array + i) == *&array[i] == array[i] 
	*/

	int *p = NULL;
	p = array;

	//�ּҸ� ǥ���غ���
	printf("%x %x %x \n", p, p + 0, &p[0]);
	printf("%x %x \n", p + 1, &p[1]);
	printf("%x %x \n", p + 2, &p[2]);

	//���� ǥ���غ���
	printf("%d %d %d \n", *p, *(p + 0), *&p[0]);
	printf("%d %d \n", *(p + 1), *&p[1]);	//*&p[1]) *&�� ������ ���ȴ� �����ϰ� ���ֵ� �ȴ�
	printf("%d %d \n", *(p + 2), *&p[2]);	//*&p[2]) *&�� ������ ���ȴ� �����ϰ� ���ֵ� �ȴ�

	for (int i = 0; i < 3; i++) 
	{
		printf("%d %d %d\n", *(array+i), *&array[i], array[i]);
		printf("%d %d %d\n", *(p + 1), *&p[i], p[i]);
	}

	printf("�迭�� ũ�� :  %d, �������� ũ�� : %d\n", sizeof(array), sizeof(p));

	//�ּҿ� �����ϴ� ���
	p = array+2; // = &array[1]�� ���� ��, ù��° ���� �ּ�

	printf("%d %d %d\n", *(p-2), *(p - 1), *(p)); //�̰� 10 20 30 �� ���´�
	
	//���� ��
	// p+1 �߱� ������ p = p+1 �̶�� �����ؾ��Ѵ�.
	//�׷��� p+2�� ������ ���� ���´�.


	p = array;
	*p = 40;

	p = array + 1;
	*p = 50;

	p = array + 2;
	*p = 60;

	printf("%d %d %d\n", *(p-2), *(p-1), *p);



	return 0;
}