#pragma once

typedef struct 
{
	int max;	//ť�� �ִ� �뷮
	int num;	// ������ ��� ����
	int front;	// ��ť�ϴ� ������ �� ù���� ����� �ڸ��� �����ϴ� ���
	int rear;	// ���� - ��ť�ϴ� �����͵� �� �ǳ� ����� �ϳ� ���� �ε����� �����ϴ� ��� 
				// ��, ���� ��ť�����Ͱ� �� �ڸ��� �̸� ����
	int *que;	// ť�� �� �� ��ҿ� ���� ������
}IntQueue;

int Initialize(IntQueue *q, int max);	//ť �ʱ�ȭ

int Enque(IntQueue *q, int x);	// ť�� �����͸� ��ť(�����ʹ� �ִ´�)

int Deque(IntQueue *q, int *x);	//ť���� ������ ��ť(�����͸� ������)

int Peek(IntQueue *q, int *x);	//ť���� �����͸� ��ũ(�����͸� �о�´�)

void Clear(IntQueue*q);	//ť�� ������ ��� ����

int Capacity(const IntQueue *q); //ť�� �ִ� �뷮

int Size(const IntQueue *q); //ť�� ����� ������ ����

int IsEmpty(const IntQueue *q);	//ť�� ����ִ°�?

int IsFull(const IntQueue *q);	//ť�� ����á�°�?

int Search(const IntQueue *q, int x);	//ť���� �˻�

void Print(const IntQueue *q);	//��� ������ ���

void Teminate(IntQueue *q);	//ť ����
