#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

void run(int a);
void print();


int col[8] = { 0 };	//���� üũ
int check1[15] = { 0 };	//�밢 üũ
int check2[15] = { 0 };	//�밢 üũ
int queenRowLocation[8] = { 0 };

void main(void) 
{
	run(0);
}

void run(int a) 
{
	int i = 0;

	for (i = 0; i <8; i++) 
	{
		if (col[i]== 0 && check1[i+a] == 0 && check2[a-i+7]== 0) //���� ���� ������ �ִ� �ڸ��̸�
		{
			queenRowLocation[i] = a;	//�� ��ġ�� ���� �ִ´�.

			if (a == 7)
			{
				print();
			}
			else
			{
				col[i] = check1[i + a] = check2[a - i + 7] = 1;	//���� ���� ���� ���ݹ����� ��� ���� 1�� �ٲ���
				run(a + 1);
				col[i] = check1[i + a] = check2[a- i+ 7] = 0;
			}
		}
	}
}

void print() 
{
	int i = 0;
	for (i = 0; i < 8; i++) 
	{
		cout << queenRowLocation[i];
	}
	cout << endl;
	
}