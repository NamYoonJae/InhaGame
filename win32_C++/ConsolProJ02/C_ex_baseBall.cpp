#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//�߱����� �����



void main(void) {
	

	int random = 0;
	int computer[3] = { 0 };
	int i = 0;
	int j = 0;
	int input[3] = {0};
	int ball = 0;
	int strike = 0;

	srand((unsigned)time(NULL));


	for (i = 0 ; i < 3; i++) 
	{
		random = (rand() % 9) + 1;
		computer[i] = random;
		for (j = 0; j <i; j++) 
		{
			if (random == computer[j] && i!=j ) 
			{
				i--;
			}
		}
	}

	while (1)
	{
		strike = 0;
		ball = 0;
		

		printf("���ڸ� �Է��ϼ���.\n\n");
		scanf("%d %d %d", &input[0], &input[1], &input[2]);

		if (input[0] < 1 || input[0] > 9 || input[1] < 1 || input[1]>9 || input[2] < 1 || input[2]>9)
		{
			printf("�Ŀ� (1~9�� ������ �Է��ϼ���).\n\n");
			continue;
		}
		else if (input[0] == input[1] || input[0] == input[2] || input[1] == input[2])
		{
			printf("�Ŀ� (�ߺ��� ���� �Է� �Ұ����մϴ�)\n\n");
			continue;
		}
		else
		{

			for (i = 0; i <3; i++)
			{
				for (j = 0; j <3; j++)
				{
					if (computer[i] == input[j])
					{
						if (i == j)
						{
							strike++;
						}
						else
							ball++;
					}
				}
			}

		}

		if (strike == 3)
		{
			printf("3��Ʈ����ũ �Դϴ�.\n -Game Clear-\n\n");
			break;
		}
		else if (strike == 0 && ball == 0)
		{
			printf("OUT ! \n\n");
		}
		else
		{
			printf("��� : %d ��Ʈ����ũ %d �� \n\n", strike, ball);
		}


	}

}