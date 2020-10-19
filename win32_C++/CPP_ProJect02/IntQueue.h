#pragma once

typedef struct 
{
	int max;	//큐의 최대 용량
	int num;	// 현재의 요소 개수
	int front;	// 인큐하는 데이터 중 첫번쨰 요소의 자리를 저장하는 멤버
	int rear;	// 리어 - 인큐하는 데이터들 중 맨끝 요소의 하나 뒤의 인덱스를 저장하는 멤버 
				// 즉, 다음 인큐데이터가 올 자리를 미리 마련
	int *que;	// 큐의 맨 앞 요소에 대한 포인터
}IntQueue;

int Initialize(IntQueue *q, int max);	//큐 초기화

int Enque(IntQueue *q, int x);	// 큐에 데이터를 인큐(데이터는 넣는다)

int Deque(IntQueue *q, int *x);	//큐에서 데이터 디큐(데이터를 빼낸다)

int Peek(IntQueue *q, int *x);	//큐에서 데이터를 피크(데이터를 읽어온다)

void Clear(IntQueue*q);	//큐의 데이터 모두 삭제

int Capacity(const IntQueue *q); //큐의 최대 용량

int Size(const IntQueue *q); //큐에 저장된 데이터 개수

int IsEmpty(const IntQueue *q);	//큐가 비어있는가?

int IsFull(const IntQueue *q);	//큐가 가득찼는가?

int Search(const IntQueue *q, int x);	//큐에서 검색

void Print(const IntQueue *q);	//모든 데이터 출력

void Teminate(IntQueue *q);	//큐 종료
