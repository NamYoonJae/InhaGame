#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
	��ȣ, �̸�, ������ �Է� ���� �� �ִ� ����ü�� ����� 
	�л��� 10���� ���� �����͸� �Է¹޾� ����ϴ� �ڵ带 �����.
	ex)
		1. �Է� - �л��� ��ȣ, �̸�, ������ ���������� �Է�
		2. �˻� - �̸����� �ش� �л��� ��ȣ, �̸�, ������ ���
		3, ��ü��� - ��ü �л��� ��ȣ, �̸�, ������ ���
		4. ���� - ���α׷� ����

*/

struct Student
{
	char phone[32];
	char name[32];
	int grade;

};




int main(void) {

	
	Student *pStudent = NULL;
	pStudent = (Student*)malloc(sizeof(Student)*128);
	

	int i = 0;
	int j = 0;
	char findName[32] = {0};

	
	for (i = 0; i <10; i++) 
	{	
		printf("�ڵ�����ȣ �̸� ������ �Է��ϼ��� : ");
		scanf("%s %s %d", pStudent[i].phone, pStudent[i].name, &pStudent[i].grade);

	}

	//��ü ���
	for (i = 0; i < 10; i++) 
	{
		printf("%s %s %d\n", pStudent[i].phone, pStudent[i].name, pStudent[i].grade);
	}


	//�л� �̸����� ���� �˻�
	printf("�˻��� �л� �̸��� �Է��ϼ��� : ");
	scanf("%s", findName);


	for (i = 0; i < 10; i++) 
	{

		for (j = 0; j <strlen(pStudent[i].name); j++)
		{
			if (strcmp(findName, pStudent[i].name) == 0)
			{
				printf("%s %s %d\n", pStudent[i].phone, pStudent[i].name, pStudent[i].grade);
				free(pStudent);
				return 0;
			}
		}

	}
	

	free(pStudent);
	return 0;
}