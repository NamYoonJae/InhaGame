#include "stdafx.h"
#include <iostream>
#include <string>

#define N 100
/*
	아이템 목록과 출현 확률이 다음과 같은 때
	5성 A템	1%
	4성 B템 3%		4성 C템 3%
	3성 D템 5%		3성 E템 5%		3성 F템 5%
	2성 G템 10%		2성 H템 10%		2성 I템 10%		2성 J템 10%
	1성 K템 38%


	템 종류는 11개


*/
using namespace std;


void main(void) {

	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int E = 0;
	int F = 0;
	int G = 0;
	int H = 0; 
	int I = 0;
	int J = 0;
	int K = 0;


	int i = 0;
	
	while (i < N)
	{
		i++;
		int num = rand()%10;
		cout << num << endl;
		switch (num)
		{
		case 0 :
			if ((double(K) / N * 100) == 38)
			{
				i--;
				continue;
			}
			else if ((double(K) / N * 100) == 20)
			{
				if ((double(A) / N * 100) == 1)
				{
					K++;
					break;
				}
				else
				{
					A++;
					break;
				}
			}
			else
			{
				K++;
			}
			break;


		case 1:
			if((double(B) / N * 100) == 3)
			{
				i--;
				continue;
			}
			else
			{
				B++;
			}
			break;

		case 2:
			if ((double(C) / N * 100) == 3)
			{
				i--;
				continue;
			}
			else
			{
				C++;
			}
			break;

		case 3:
			if ((double(D) / N * 100) == 5)
			{
				i--;
				continue;
			}
			else
			{
				D++;
			}
			break;

		case 4:
			if ((double(E) / N * 100) == 5)
			{
				i--;
				continue;
			}
			else
			{
				E++;
			}
			break;
		case 5:
			if ((double(F) / N * 100) == 5)
			{
				i--;
				continue;
			}
			else
			{
				F++;
			}
			break;

		case 6:
			if ((double(G) / N * 100) == 10)
			{
				i--;
				continue;
			}
			else
			{
				G++;
			}
			break;

		case 7:
			if ((double(H) / N * 100) == 10)
			{
				i--;
				continue;
			}
			else
			{
				H++;
			}
			break;

		case 8:
			if ((double(I) / N * 100) == 10)
			{
				i--;
				continue;
			}
			else
			{
				I++;
			}
			break;

		case 9:
			if ((double(J) / N * 100) == 10)
			{
				i--;
				continue;
			}
			else
			{
				J++;
			}
			break;
		default:
			break;

		}

	}
	
	cout << "A템 : " << A << endl;
	cout << "B템 : " << B << endl;
	cout << "C템 : " << C << endl;
	cout << "D템 : " << D << endl;
	cout << "E템 : " << E << endl;   
	cout << "F템 : " << F << endl;
	cout << "G템 : " << G << endl;
	cout << "H템 : " << H << endl;
	cout << "I템 : " << I << endl;
	cout << "J템 : " << J << endl;
	cout << "K템 : " << K << endl;



}