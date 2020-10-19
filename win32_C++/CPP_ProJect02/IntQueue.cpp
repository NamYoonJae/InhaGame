#include "stdafx.h"
#include <stdlib.h>
#include "IntQueue.h"

void main(void) 
{
	IntQueue que;

	if (Initialize(&que, 64) == -1)
	{
		puts("ť�� ������ �����Ͽ����ϴ�.");
		return;
	}

	while (1)
	{
		int m, x;

		printf("���� ������ �� : %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)��ť (2)��ť (3)��ũ (0)����\n");
		scanf("%d",&m);

		if (m == 0) break;
		switch (m)
		{
		case 1:
			printf("������ : "); 
			scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a ���� : ��ť�� �����Ͽ����ϴ�.");
			break;

		case 2:
			if (Deque(&que, &x) == -1)
				puts("\a���� : ��ť�� �����߽��ϴ�.");
			else
				printf("��ť�� �����ʹ� %d �Դϴ�.\n\n",x);
			break;

		case 3:
			if (Peek(&que, &x) == -1)
				puts("\a ���� : ��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d �Դϴ�.\n\n",x);
			break;

		case 4:
			Print(&que);
			break;
		}

	}

	Teminate(&que);
}

int Initialize(IntQueue * q, int max)
{
	q->num = q->front = q->rear = 0;
	if ((q->que = (int*)calloc(max, sizeof(int))) == NULL)
	{
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

int Enque(IntQueue * q, int x)
{
	if (q->num >= q->max) 
		return-1;
	else
	{
		q->num++;
		q->que[q->rear++] = x;	//rear�ڸ��� ��ť�� �ڸ��̱⋚���� �� �ڸ��� �����͸� �߰��ϰ� rear���ڸ� �������ѵд�

		if (q->rear == q->max)	//rear�ڸ��� �ִ�ġ ���ڰ� �Ǹ� �ʱ�ȭ ó���ڸ��� �ʱ�ȭ(���� ����)
			q->rear = 0;

		return 0;
	}
}

int Deque(IntQueue * q, int * x)
{
	if (q->num <= 0)
		return -1;
	else
	{
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)
			q->front = 0;
		return 0;
	}
}

int Peek(IntQueue * q, int * x)
{
	if (q->num <= 0)
		return -1;
	*x = q->que[q->front];
	return 0;
}

void Clear(IntQueue * q)
{
	q->num = q->front = q->rear = 0;
}

int Capacity(const IntQueue * q)
{
	return q->max;
}

int Size(const IntQueue * q)
{
	return q->num;
}

int IsEmpty(const IntQueue * q)
{
	return q->num  <= 0;
}

int IsFull(const IntQueue * q)
{
	return q->num >= q->max;
}

int Search(const IntQueue * q, int x)
{
	int i, idx;
	for (i =0; i <q->num; i++) 
	{
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;
	}
	return -1;
}

void Print(const IntQueue * q)
{
	int i;
	for (i = 0; i < q->num; i++)
		printf("%d ", q->que[(i + q->front) % q->max]);
	putchar('\n');
}

void Teminate(IntQueue * q)
{

	if (q->que != NULL)
		free(q->que);
	q->max = q->num = q->front = q->rear = 0;

}

