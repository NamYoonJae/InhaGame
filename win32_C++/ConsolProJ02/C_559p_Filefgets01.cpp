#include <stdio.h>
#include "stdafx.h"

void main() 
{
	FILE *fp = NULL;
	char szBuffer[512] = { 0 }; 
	
	//���� szBuffer2[512]�� �ϳ� �� �����Ѵٸ� ?
	
	fp = fopen("Test.txt", "w");
	fputs("Test\n", fp); //Test �� szBuffer�� ����
	fputs("String\n", fp); //String�� szBuffer2�� ����
	fputs("Data\n", fp);
	fclose(fp);

	fp = fopen("Test.txt", "r");
	
	if (fp == NULL)
		return;

	
	while (fgets(szBuffer, sizeof(szBuffer), fp)) 
	{
		printf("%s", szBuffer);
		memset(szBuffer, 0, sizeof(szBuffer));
	}
	//���� ��� ����ϰ� ���� ���� ǥ���ϴ� ������ NULL���ڰ� �����µ�
	//�׶� NULL���� ��ȯ�ϸ鼭 while���� �������´�

	fclose(fp);

}