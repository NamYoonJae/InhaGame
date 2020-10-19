#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
	�� ���� 10���� ���� �� �ִ� �κ��丮�� �ִ�.
	�����۸��� �߿䵵�� �ְ� ���԰� �ٸ���.
	�߿䵵�� ���� ���� ������ ���⸦ ���� �� �ֵ��� ���α׷��� �ۼ��϶�.

	�̸�			�߿䵵		����
	kar98k		7			4
	�Ķ�����		10			2
	������		7			4
	�ҹ��		6			6
	������		2			10
	����			3			5

	��� >	�߿䵵 ������ ��� �� �� �ֵ��� �� ��
			�߿䵵 1���� : 24
			kar98k		7	4
			�Ķ�����		10	2
			������		7	4


*/
struct weponList 
{
	char name[32];
	int importance;
	int weight;
};


void main(void) {

	struct weponList wepon[6] = { "", 0, 0};
	int i = 0;
	int j = 0;
	int impSum = 0;
	strcpy(wepon[0].name, "kar98k");
	strcpy(wepon[1].name, "�Ķ�����");
	strcpy(wepon[2].name, "������");
	strcpy(wepon[3].name, "�ҹ��");
	strcpy(wepon[4].name, "������");
	strcpy(wepon[5].name, "����");
	
	wepon[0].importance = 7;
	wepon[1].importance = 10;
	wepon[2].importance = 7;
	wepon[3].importance = 6;
	wepon[4].importance = 2;
	wepon[5].importance = 3;

	wepon[0].weight = 4;
	wepon[1].weight = 2;
	wepon[2].weight = 4;
	wepon[3].weight = 6;
	wepon[4].weight = 10;
	wepon[5].weight = 5;


	for (i = 0; i < 6; i++) 
	{
		printf("%s %d %d\n", wepon[i].name, wepon[i].importance, wepon[i].weight);
	}

	char nameTemp[32];
	int impTemp = 0;
	int weightTemp = 0;


	for (i = 0; i < 6; i++) 
	{
		for (j=i+1; j <6; j++) 
		{
			if (wepon[i].importance < wepon[j].importance) 
			{
				impTemp = wepon[i].importance;
				wepon[i].importance = wepon[j].importance;
				wepon[j].importance = impTemp;

				weightTemp = wepon[i].weight;
				wepon[i].weight = wepon[j].weight;
				wepon[j].weight = weightTemp;

				strcpy(nameTemp,wepon[i].name);
				strcpy(wepon[i].name, wepon[j].name);
				strcpy(wepon[j].name, nameTemp);
			}
		}
	}

	putchar('\n');
	putchar('\n');


	for (i = 0; i < 3; i++) 
	{
		impSum += wepon[i].importance;
	}

	printf("�� �߿䵵 %d\n\n", impSum);

	for (i = 0; i < 3; i++)
	{
		printf("%s %d %d\n", wepon[i].name, wepon[i].importance, wepon[i].weight);
	}

}