#pragma once

typedef struct
{
	int max;
	int ptr;
	int *stk;

} IntStack;

int Initialize(IntStack *s, int max);	//���� �ʱ�ȭ

int Push(IntStack *s, int x);	//���ÿ� �����͸� Ǫ��(���� �� ���� ������ �߰�	)

int Pop(IntStack *s, int *x);	//���ÿ��� �����͸� ��(������ �� ���� �����͸� ����)

int Peek(const IntStack *s, int *x);	// ���ÿ��� �����͸� ��ũ(������ �� ���� �����͸� Ȯ��)

void Clear(IntStack *s);	//���� ����

int Capacity(const IntStack *s);	//������ �ִ�뷮

int Size(const IntStack *s);	//������ ������ ����

int IsEmpty(const IntStack *s);	//������ ����ֳ��� ?

int IsFull(const IntStack *s);	//������ ���� á���� ?

int Search(const IntStack *s, int x);	//���ÿ��� �˻�

void Print(const IntStack *s);	// ������ ��� ������ ���

void Terminate(IntStack *s);	// ���� ����