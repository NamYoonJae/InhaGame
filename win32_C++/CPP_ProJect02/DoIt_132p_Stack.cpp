#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

//스택 포인터 ptr -> 스택에 쌓여있는 데이터의 개수를 나타낸다
//스택 배열 stk -> 스택으로 푸시된 데이터를 저장할 용도의 배열을 가리키는 포인터

//스택 초기화
int Initialize(IntStack * s, int max)
{
	s->ptr = 0;

	if ((s->stk = (int*)calloc(max,sizeof(int))) == NULL) 
	{
		s->max = 0;
		return -1;
	}

	s->max = max;
	return 0;
}

//데이터 푸쉬 (맨 위에 넣기)
int Push(IntStack * s, int x)
{
	if (s->ptr >= s->max)	//데이터 양이 max치를 초과하면 -1 리턴
		return -1;

	s->stk[s->ptr++] = x;
	return 0;
}

//데이터 팝 (맨 위의 데이터 꺼내기)
int Pop(IntStack * s, int *x)
{
	if (s->ptr <= 0)
		return -1;

	*x = s->stk[s->ptr-1];
	s->ptr--;

	return 0;
}

//데이터 피크 (맨 위의 데이터 확인)
int Peek(const IntStack * s, int *x)
{
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr - 1];

	return 0;
}

void Clear(IntStack * s)
{
	s->ptr = 0;

}

//스택 최대 용량 확인
int Capacity(const IntStack * s)
{
	return s->max;
}

//스택의 데이터 개수 확인
int Size(const IntStack * s)
{
	return s->ptr;
}

//스택이 비어있는가 ?
int IsEmpty(const IntStack * s)
{
	return s->ptr <=0;
}

 //스택이 가득 찼는가 ?
int IsFull(const IntStack * s)
{
	return s->ptr >= s->max;
}

//스택에서 검색
int Search(const IntStack * s, int x)
{
	int i;
	for (i = s->ptr - 1; i >= 0; i--) //맨 위쪽부터 아래쪽으로 선형검색
		if (s->stk[i] == x)
			return i;
	return -1;
}

//모든 데이터 출력
void Print(const IntStack * s)
{
	int i;
	for (i = 0; i < s->ptr; i++)
		printf("%d", s->stk[i]);
	putchar('\n');
}

//스택 종료
void Terminate(IntStack * s)
{
	if (s->stk != NULL)
		free(s->stk);	//동적 할당한 배열 해제
	s->max = s->ptr = 0;
}

int main(void) 
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("스택 생성에 실패하였습니다.\n");
		return 1;
	}

	while (1)
	{

		int menu, x;
		printf("현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)푸쉬 (2)팝 (3)피크 (4)출력 (0)종료\n");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case 1 :
			printf("데이터 : ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a오류 : 푸쉬에 실패하였습니다\n");
			break;

		case 2 :
			if (Pop(&s, &x) == -1)
				puts("\a오류 : 팝에 실패하였습니다\n");
			else
				printf("팝 데이터는 %d 입니다.\n", x);
			break;

		case 3 :
			if (Peek(&s, &x) == -1)
				puts("\a오류 : 피크에 실패하였습니다\n");
			else
				printf("피크의 데이터는 %d 입니다.\n", x);
			break;

		case 4 :
			Print(&s);
			break;
		}
	}
	Terminate(&s);

}