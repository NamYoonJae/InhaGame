#include "stdafx.h"
#include <iostream>
#include <string>

#define N 100
/*
	������ ��ϰ� ���� Ȯ���� ������ ���� ��
	5�� A��	1%
	4�� B�� 3%		4�� C�� 3%
	3�� D�� 5%		3�� E�� 5%		3�� F�� 5%
	2�� G�� 10%		2�� H�� 10%		2�� I�� 10%		2�� J�� 10%
	1�� K�� 38%


	�� ������ 11��


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
	
	cout << "A�� : " << A << endl;
	cout << "B�� : " << B << endl;
	cout << "C�� : " << C << endl;
	cout << "D�� : " << D << endl;
	cout << "E�� : " << E << endl;   
	cout << "F�� : " << F << endl;
	cout << "G�� : " << G << endl;
	cout << "H�� : " << H << endl;
	cout << "I�� : " << I << endl;
	cout << "J�� : " << J << endl;
	cout << "K�� : " << K << endl;



}