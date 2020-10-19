#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
/*
---------------------------------------------------------------
[기수정렬(Radix Sort)]
arr : 152, 352, 350, 270, 339, 750, 670, 650, 430, 110

가장 큰 자릿수인 백의 자리부터 해당하는 큐에 삽입
or 가장 작은 자릿수인 일의 자리부터 순서대로 해당하는 큐에 삽입
-> 일의 자리부터 시작함
0 : 350, 270, 750, 670, 650, 430, 110
1 :
2 : 152, 352,
3 :
4 :
5 :
6 :
7 :
8 :
9 : 339

다음 자릿수를 해당하는 큐에 순서대로 삽입
-> 십의 자리
0 :
1 : 110
2 :
3 : 430, 339
4 :
5 : 350, 750, 650, 152, 352
6 :
7 : 270, 670,
8 :
9 :

다음 자릿수를 해당하는 큐에 순서대로 삽입
-> 백의 자리
0 :
1 : 110, 152
2 : 270
3 : 339, 350, 352
4 : 430
5 :
6 : 650, 670
7 : 750
8 :
9 :

정렬완료
---------------------------------------------------------------
*/

/*

	arr : 152, 352, 350, 270, 339, 750, 670, 650, 430, 110
	arr 배열의 크기만큼 배열 radix 생성

	1의 자리 뽑아서 radix 해당 방에 삽입
	arr 초기화

	radix에서 십의 자리 숫자 꺼내서 arr 방에 삽입
	radix 초기화

	arr 에서 백의 자리 숫자 꺼내서 radix에 삽입
	arr 초기화

*/

using namespace std;

void main(void) {

	int arr[10] = { 152, 352, 350, 270, 339, 750, 670, 650, 430, 110 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	/*
	double hundred = (152 / 100);	//100의 자리 숫자
	double ten = (152 % 100) / 10;	//10의 자리 숫자
	double one = (152 % 100) % 10;	//1의 자리 숫자
	*/

	int hundred = 0;
	int ten = 0;
	int one = 0;
	int i = 0;
	int j = 0;
	int n0, n1, n2, n3, n4, n5, n6, n7, n8, n9;
	int n10, n11, n12, n13, n14, n15, n16, n17, n18, n19;
	int n110, n111, n112, n113, n114, n115, n116, n117, n118, n119;

	n0 = n1 = n2 = n3 = n4 = n5 = n6 = n7 = n8 = n9 = 0;
	n10 = n11 = n12 = n13 = n14 = n15 = n16 = n17 = n18 = n19 = 0;
	n110 = n111 = n112 = n113 = n114 = n115 = n116 = n117 = n118 = n119 = 0;

	//radix 2차원 배열 선언
	int **radix = new int*[arrSize]();
	for (i = 0; i < arrSize; i++) 
	{
		radix[i] = new int[100]();
	}

	//radix02 2차원 배열 선언
	int **radix02 = new int*[arrSize]();
	for (i = 0; i < arrSize; i++)
	{
		radix02[i] = new int[100]();
	}


	for (i = 0; i < arrSize; i++) 
	{
		one = (arr[i] % 100) % 10;

		switch (one)
		{
		case 0:
			radix[0][n0++] = arr[i];
			break;

		case 1:
			radix[1][n1++] = arr[i];
			break;

		case 2:
			radix[2][n2++] = arr[i];
			break;

		case 3:
			radix[3][n3++] = arr[i];
			break;

		case 4:
			radix[4][n4++] = arr[i];
			break;

		case 5:
			radix[5][n5++] = arr[i];
			break;

		case 6:
			radix[6][n6++] = arr[i];
			break;

		case 7:
			radix[7][n7++] = arr[i];
			break;

		case 8:
			radix[8][n8++] = arr[i];
			break;

		case 9:
			radix[9][n9++] = arr[i];
			break;


		default:
			break;
		}

	}

	cout << "===================[ radix] ======================" << endl;
	cout << endl;
	for (i = 0 ; i < arrSize; i ++) 
	{
		for (int j = 0; j < arrSize; j++) 
		{
			cout << radix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "===============================================" << endl;
	cout << endl;

	
	for (i = 0; i <arrSize; i++) 
	{

		for (j = 0 ; j < arrSize; j++) 
		{
			
			//radix 배열 모두 탐색하고 만약 0 보다 큰 수를 발견하면 
			if (radix[i][j] > 0) 
			{
				ten = (radix[i][j] % 100) / 10;

				switch (ten)
				{
				case 0:
					radix02[0][n10++] = radix[i][j];
					break;

				case 1:
					radix02[1][n11++] = radix[i][j];
					break;

				case 2:
					radix02[2][n12++] = radix[i][j];
					break;

				case 3:
					radix02[3][n13++] = radix[i][j];
					break;

				case 4:
					radix02[4][n14++] = radix[i][j];
					break;

				case 5:
					radix02[5][n15++] = radix[i][j];
					break;

				case 6:
					radix02[6][n16++] = radix[i][j];
					break;

				case 7:
					radix02[7][n17++] = radix[i][j];
					break;

				case 8:
					radix02[8][n18++] = radix[i][j];
					break;

				case 9:
					radix02[9][n19++] = radix[i][j];
					break;


				default:
					break;
				}
			}

		}

	}

	cout << "===================[ radix02 ] ======================" << endl;
	cout << endl;
	for (i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			cout << radix02[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "====================================================" << endl;
	cout << endl;



	for (i = 0; i < arrSize; i++) 
	{
		for (j = 0; j < arrSize; j++) 
		{
			radix[i][j] = 0;
		}
	}

	for (i = 0; i <arrSize; i++)
	{

		for (j = 0; j < arrSize; j++)
		{

			if (radix02[i][j] > 0)
			{
				hundred = radix02[i][j] / 100;

				switch (hundred)
				{
				case 0:
					radix[0][n110++] = radix02[i][j];
					break;

				case 1:
					radix[1][n111++] = radix02[i][j];
					break;

				case 2:
					radix[2][n112++] = radix02[i][j];
					break;

				case 3:
					radix[3][n113++] = radix02[i][j];
					break;

				case 4:
					radix[4][n114++] = radix02[i][j];
					break;

				case 5:
					radix[5][n115++] = radix02[i][j];
					break;

				case 6:
					radix[6][n116++] = radix02[i][j];
					break;

				case 7:
					radix[7][n117++] = radix02[i][j];
					break;

				case 8:
					radix[8][n118++] = radix02[i][j];
					break;

				case 9:
					radix[9][n119++] = radix02[i][j];
					break;


				default:
					break;
				}
			}

		}

	}

	cout << "===================[ radix ] ======================" << endl;
	cout << endl;
	for (i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			cout << radix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "====================================================" << endl;
	cout << endl;

	
	vector<int> v;
	for (i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			if (radix[i][j] > 0) 
			{
				v.push_back(radix[i][j]);
			}
		}
		cout << endl;
	}

	for (i =0; i < arrSize; i++) 
	{
		cout << v[i] << " ";
	}
	
}