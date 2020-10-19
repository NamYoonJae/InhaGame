#pragma once

typedef struct
{
	int max;
	int ptr;
	int *stk;

} IntStack;

int Initialize(IntStack *s, int max);	//스택 초기화

int Push(IntStack *s, int x);	//스택에 데이터를 푸쉬(스택 맨 위에 데이터 추가	)

int Pop(IntStack *s, int *x);	//스택에서 데이터를 팝(스택의 맨 위의 데이터를 꺼냄)

int Peek(const IntStack *s, int *x);	// 스택에서 데이터를 피크(스택의 맨 위의 데이터를 확인)

void Clear(IntStack *s);	//스택 비우기

int Capacity(const IntStack *s);	//스택의 최대용량

int Size(const IntStack *s);	//스택의 데이터 개수

int IsEmpty(const IntStack *s);	//스택이 비어있나요 ?

int IsFull(const IntStack *s);	//스택이 가득 찼나요 ?

int Search(const IntStack *s, int x);	//스택에서 검색

void Print(const IntStack *s);	// 스택의 모든 데이터 출력

void Terminate(IntStack *s);	// 스택 종료