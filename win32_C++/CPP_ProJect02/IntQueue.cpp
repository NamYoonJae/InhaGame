#include "stdafx.h"
#include <stdlib.h>
#include "IntQueue.h"

void main(void) 
{
	IntQueue que;

	if (Initialize(&que, 64) == -1)
	{
		puts("큐의 생성에 실패하였습니다.");
		return;
	}

	while (1)
	{
		int m, x;

		printf("현재 데이터 수 : %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)인큐 (2)디큐 (3)피크 (0)종료\n");
		scanf("%d",&m);

		if (m == 0) break;
		switch (m)
		{
		case 1:
			printf("데이터 : "); 
			scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a 오류 : 인큐에 실패하였습니다.");
			break;

		case 2:
			if (Deque(&que, &x) == -1)
				puts("\a오류 : 디큐에 실패했습니다.");
			else
				printf("디큐한 데이터는 %d 입니다.\n\n",x);
			break;

		case 3:
			if (Peek(&que, &x) == -1)
				puts("\a 오류 : 피크에 실패했습니다.");
			else
				printf("피크한 데이터는 %d 입니다.\n\n",x);
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
		q->que[q->rear++] = x;	//rear자리가 인큐할 자리이기떄문에 그 자리에 데이터를 추가하고 rear숫자를 증가시켜둔다

		if (q->rear == q->max)	//rear자리가 최대치 숫자가 되면 초기화 처음자리로 초기화(링형 구조)
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

