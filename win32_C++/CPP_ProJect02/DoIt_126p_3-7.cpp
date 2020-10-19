#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

typedef struct 
{
	char name[10];
	int height;
	int weight;
}Person;

int npcmp(const Person *x, const Person *y) 
{
	return strcmp(x->name, y->name);
}

void main(void) 
{
	Person x[] =
	{
		{"�迵��", 179, 79},
		{"������", 172, 63},
		{"�̼���", 176, 52},
		{"������", 165, 51},
		{"������", 181, 73},
		{"ȫ����", 172, 84},

	};

	int nx = sizeof(x) / sizeof(x[0]);
	int retry;
	puts("�̸����� �˻��մϴ�.");
	do 
	{
		Person temp, *p;
		printf("�̸� : ");
		scanf_s("%s", temp.name,sizeof(temp.name));
		p = (Person*)bsearch(&temp, x, nx, sizeof(Person),
			(int(*)(const void *, const void *))npcmp);

		if (p == NULL)
			puts("�˻��� �����߽��ϴ�.");
		else
		{
			puts("�˻� ���� !! �Ʒ� ��Ҹ� ã�ҽ��ϴ�.");
			printf("x[%d] : %s %dcm %dkg\n", (int)(p-x),p->name, p ->height, p->weight);
		}
		printf("�ٽ� �˻��ұ�� ? (1)�� / (0)�ƴϿ� : ");
		scanf_s("%d", &retry,sizeof(&retry));
	} while (retry == 1);

}