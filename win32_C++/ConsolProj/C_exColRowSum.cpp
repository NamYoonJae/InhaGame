#include "stdafx.h"
#include <conio.h>
#include <windows.h>


/*
n * n 크기의 행렬이 주어진다
이때, 주어진 행렬의 i행에 있는 모든 숫자와 j열에 있는 모든 숫자의 합이 i행 j열의 값인 새로운 행렬을 구하려고 한다.
단, 교차 지점의 숫자는 한 번만 더해야 한다.

ex) 3 * 3
1 2 3           17 19 21
4 5 6     =>     23 25 27
7 8 9              29 31 33

제한 사항 > 2차원 배열로 n * n 의 크기의 행렬을 나타내며
n은 3이상 50 이하의 자연수이다.
각 원소는 1이상 10,000 이하의 자연수이다.

*/

void calculation(int row, int col);




int main(void) {

	int row = 3;
	int col = 3;


	calculation(row, col);

	return 0;
}

void calculation(int row, int col)
{
	int x = 0;
	int y = 0;
	int num = 1;
	int matrix[3][3] = { 0 };
	int sumX[3] = { 0 };
	int sumY[3] = { 0 };
	int sumMatrix[3][3] = { 0 };


	for (x = 0; x < 3; ++x)
	{
		for (y = 0; y < 3; ++y)
		{
			matrix[x][y] = num++;
		}
	}

	for (x = 0; x <3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			printf("%d", matrix[x][y]);

		}
		printf("\n");
	}



	for (x = 0; x <3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			sumX[x] += matrix[x][y];
			sumY[y] += matrix[x][y];
		}
	}

	for (x = 0; x <3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			sumMatrix[x][y] = sumX[x] + sumY[y] - matrix[x][y];

		}
	}


	for (x = 0; x <3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			printf("%d\t", sumMatrix[x][y]);

		}
		printf("\n");
	}


}
