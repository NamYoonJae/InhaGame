#include "stdafx.h"
#include <conio.h>
#include <windows.h>


/*
n * n ũ���� ����� �־�����
�̶�, �־��� ����� i�࿡ �ִ� ��� ���ڿ� j���� �ִ� ��� ������ ���� i�� j���� ���� ���ο� ����� ���Ϸ��� �Ѵ�.
��, ���� ������ ���ڴ� �� ���� ���ؾ� �Ѵ�.

ex) 3 * 3
1 2 3           17 19 21
4 5 6     =>     23 25 27
7 8 9              29 31 33

���� ���� > 2���� �迭�� n * n �� ũ���� ����� ��Ÿ����
n�� 3�̻� 50 ������ �ڿ����̴�.
�� ���Ҵ� 1�̻� 10,000 ������ �ڿ����̴�.

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
