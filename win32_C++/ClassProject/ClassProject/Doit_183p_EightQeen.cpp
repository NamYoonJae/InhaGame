#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

void run(int a);
void print();


int col[8] = { 0 };	//가로 체크
int check1[15] = { 0 };	//대각 체크
int check2[15] = { 0 };	//대각 체크
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
		if (col[i]== 0 && check1[i+a] == 0 && check2[a-i+7]== 0) //만약 퀸을 놓을수 있는 자리이면
		{
			queenRowLocation[i] = a;	//그 위치에 퀸을 넣는다.

			if (a == 7)
			{
				print();
			}
			else
			{
				col[i] = check1[i + a] = check2[a - i + 7] = 1;	//현재 놓은 퀸의 공격범위에 닿는 곳을 1로 바꿔줌
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