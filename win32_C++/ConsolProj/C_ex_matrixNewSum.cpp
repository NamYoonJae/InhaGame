#include "stdafx.h"
#include <conio.h>
#include <windows.h>

/*
	n x n ũ���� ����� �־�����.
	�̋�, �־��� ����� i�࿡ �ִ� ��� ���ڿ� j���� �ִ� ��� ������ ���� i�� j���� ���� ���ο� ����� ���Ϸ��� �Ѵ�.
	��, ���� ������ ���ڴ� �� ���� ���Ѵ�.
	ex) 3x3 
			1 2 3
			4 5 6
			7 8 9

		=>  17 19 21
			23 25 27
			29 31 33
		=> 1�� 1���� ���� 17 ������ �ϴ� solution �Լ��� �ۼ��϶�
		���� > 2���� �迭�� n x n �� ũ���� ����� ��Ÿ����, n�� 3�̻� 50������ �ڿ����̴�.
		�� ���Ҵ� 1�̻� 10,000������ �ڿ����̴�.
*/

void printMatrix(int matrix[][3], int size);
int sumMatrix(int matrix[][3], int size);
int sumY(int matrix[][3], int size);
//int sumX(int matrix[][3], int size);


//����
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

//�Լ�

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

	//1�� 3�� ���� ��
	for (int y = 0; y < size; y++) {
		sumY += matrix[0][y];
	}
	
	//2�� 3�� ���� ��
	for (int y = 0; y < size; y++) {
		sumY += matrix[1][y];
	}

	//3�� 3�� ���Ѱ�
	for (int y = 0; y < size; y++) {
		sumY += matrix[2][y];
	}


	printf("sumY�� �� : %d",sumY);

	return sumY;
}


