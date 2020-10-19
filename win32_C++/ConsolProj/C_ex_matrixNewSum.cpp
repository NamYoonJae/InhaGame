#include "stdafx.h"
#include <conio.h>
#include <windows.h>

/*
	n x n 크기의 행렬이 주어진다.
	이떄, 주어진 행렬의 i행에 있는 모든 숫자와 j열에 있는 모든 숫자의 합이 i행 j열의 값인 새로운 행렬을 구하려고 한다.
	단, 교차 지점의 숫자는 한 번만 더한다.
	ex) 3x3 
			1 2 3
			4 5 6
			7 8 9

		=>  17 19 21
			23 25 27
			29 31 33
		=> 1행 1열의 값은 17 리턴을 하는 solution 함수를 작성하라
		제한 > 2차원 배열로 n x n 의 크기의 행렬을 나타내며, n은 3이상 50이하의 자연수이다.
		각 원소는 1이상 10,000이하의 자연수이다.
*/

void printMatrix(int matrix[][3], int size);
int sumMatrix(int matrix[][3], int size);
int sumY(int matrix[][3], int size);
//int sumX(int matrix[][3], int size);


//메인
int main(void) 
{

	int x = 0;
	int y = 0;
	int num = 1;
	int nSize = 3;
	int matrix[3][3];

	
	for (x = 0; x < 3; ++x)
	{
		for (y = 0; y < 3; ++y)
		{
			matrix[x][y] = num++;
		}

	}
	
	printMatrix(matrix, 3);
	sumY(matrix, 3);
	//sumX(matrix, 3);
	//sumMatrix(matrix, 3);


	return 0;
}

//함수

void printMatrix(int matrix[][3], int size)
{
	for (int x = 0; x < size; x++) 
	{
		for (int y = 0; y <size; y++) 
		{
			printf("%d\t", matrix[x][y]);
		}
		printf("\n\n");
	}
}

int sumMatrix(int matrix[][3], int size)
{
	int x = 0;
	int y = 0;
	int a = 0;
	int b = 0;

	for (x = 0; x <size; ++x) 
	{
		for (y = 0; y < size; ++y) 
		{
		
		}
		printf("\n\n");
	}


	

	return 0;
}

int sumY(int matrix[][3], int size)
{	
	
	int sumY =0;

	//1행 3개 더한 값
	for (int y = 0; y < size; y++) {
		sumY += matrix[0][y];
	}
	
	//2행 3개 더한 값
	for (int y = 0; y < size; y++) {
		sumY += matrix[1][y];
	}

	//3행 3개 더한값
	for (int y = 0; y < size; y++) {
		sumY += matrix[2][y];
	}


	printf("sumY의 합 : %d",sumY);

	return sumY;
}


