#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
	���α׷� �󿡼� ���� 99.txt �� ���� �� ���Ͽ� �������� �����ϴ� ���α׷��� �ۼ��϶�.
	fprintf()�Լ��� �̿��� ��

	-fseek() �Լ��� �̿��ؼ� ���ϴ� ���� ���븸 ã�Ƽ� ����ϴ� ���α׷��� �ۼ��϶�.

*/



void main(void) {

	FILE * fp = NULL;
	FILE * fp2 = NULL;
	int i = 0;
	int j = 0;
	int input = 0;
	char szBuffer[32];
	/*
	int num1, num2, num3;
	char ch1, ch2;
	*/
	fp = fopen("99.txt","w");

	
	if (fp == NULL)
	{
		printf("fp ���� ����");
		return;
	}

	for (i = 2; i < 10; i++) 
	{
		for (j = 1; j < 10; j++) 
		{
			fprintf(fp, "%d * %d = %2d\n", i, j, i*j);
		}
	}

	fclose(fp);

	printf("���ϴ� ���� �Է��ϼ��� : ");
	scanf("%d",&input);

	fp = fopen("99.txt", "r");

	fseek(fp, (input-2)*12*9, SEEK_CUR);

	for (i = 0; i < 9; i++) 
	{
		fprintf(stdout, "%s\n", fgets(szBuffer, sizeof(szBuffer), fp));
	}

	//system("notepad.exe 99.txt");


}