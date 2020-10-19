#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

int int_cmp(const int *a, const int *b) 
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
	{
		return 1;
	}
	else
		return 0;
}
void *besearchx(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void*, const void *));

void main(void) {

	int i = 0;
	int key = 0;
	int nx = 0;
	int *x;
	int *p;

	printf("��� ���� �Է� : ");
	scanf_s("%d",&nx);
	x = (int*)calloc(nx, sizeof(int));

	printf("������������ �Է��ϼ���.\n");
	printf("x[0] : ");
	scanf_s("%d",&x[0]);
	for (i = 1; i < nx; i++) 
	{
		do
		{
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while ( x[i] < x[i-1] );
	}
	printf("�˻��� : ");
	scanf_s("%d",&key);

	p = (int*)besearchx(&key, x, nx , sizeof(int), (int(*)(const void *, const void *)) int_cmp);

	
	if (p == NULL)
	{
		printf("�˻��� �����߽��ϴ�");
	}
	else
	{
		printf("%d�� x[%d]�� �ֽ��ϴ�\n", key, (int)(p - x));
	}
	

	free(x);
}

void * besearchx(const void * key, const void * base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{
	/*
		key  -> �˻���
		nx -> ��� ����
		x -> ��ҵ�
		compr �Լ��� ���ϰ��� ����� ��� ������, ������ ��� ������ Ž��
	*/

	int startIndex = 0;
	int endIndex = nmemb-1;
	int middleIndex = (startIndex + endIndex) / 2;

	char *x = (char*)base;

	if (nmemb > 0)
	{
		while (1) 
		{
			int comp = compar((const void*)&x[middleIndex * size], key);

			if (comp == 0)//�˻� ����
			{
				for (; middleIndex > startIndex; middleIndex--) //key�� ���� ��Ҹ� ã�´�
					if (compar((const void*)&x[(middleIndex - 1) * size], key))//���-1 �ε��� * size �� key��
						break;
				return &x[middleIndex * size];
			}
			else if (startIndex == endIndex)
				break;
			else if (comp < 0)
				startIndex = middleIndex + 1;
			else
				endIndex = middleIndex - 1;
		}
	
	}

	return NULL;
}
