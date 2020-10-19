#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



struct impormation
{
	int number = 0;
	char name[32] = { 0 };
};

void menuPrint();
void inputStudentNN();


void main(void) {

	FILE *fp = NULL;

	fp = fopen("student.txt","a");
	if (fp == NULL) return;

	menuPrint();	//�޴� ��� �Լ�




}

void menuPrint()
{
	int n = 0;

	printf("==================\n");
	printf("�޴��� �����ϼ���\n");
	printf("==================\n");
	printf("1. ������ �߰�\n");
	printf("2. �˻� ���\n");
	printf("3. ����\n");
	printf("4. ����\n");
	printf("5. ����\n");
	printf("==================\n\n");
	printf("�Է� >");

	scanf("%d", &n);
	system("cls");

	switch (n)
	{
	case 1:

		inputStudentNN();

		break;
	case 2:
		printf("==================\n");
		printf("2. �˻� ���\n");
		printf("==================\n");
		break;

	case 3:
		printf("==================\n");
		printf("==================\n");
		break;
	case 4:
		printf("==================\n");
		printf("==================\n");
		break;
	case 5:
		printf("=============================\n");
		printf("���α׷��� �����Ͻðڽ��ϱ�?\n");
		printf("1. [Yes]\t");
		printf("2. [No]\n");
		printf("=============================\n");
		printf("�Է� > ");
		scanf("%d", &n);
		if (n == 1)
		{
			printf("���α׷��� �����մϴ�\n");
			return;
		}
		else if (n == 2)
		{
			system("cls");
			menuPrint();
		}

	default:
		printf("��ȿ�� ���ڰ� �ƴմϴ�.\n\n");
		printf("1. [�����޴�]\t");
		printf("2. [����]");
		scanf("%d", &n);
		system("cls");
		if (n==1) 
		{
			menuPrint();
		}
		else if(n==2)
		{
			printf("���α׷��� �����մϴ�\n");
			return;
		}
		else 
		{
			printf("��ȿ���� ���� �����Դϴ�\n");
			printf("���α׷��� �����մϴ�\n");
		}

			

		break;
	}
}

void inputStudentNN()
{
	int studentNumber = 0;
	char studentName[32] = { 0 };
	char student[50] = { 0 };
	int saveLength = 0;
	int i = 0;
	int n = 0;
	char data;
	FILE *saveFp = NULL;
	FILE *oldFp = NULL;
	impormation impormStuN;
	impormation impormBuffer;

	//save.dat ad(������ �������뿡�� �߰� ������ ���θ���)
	//saveFp = fopen("save.dat", "rb");
	//fread(&impormBuffer, sizeof(impormation) , 1, saveFp);
	printf("==================\n");
	printf("1. ������ �߰�\n");
	printf("==================\n\n");

	printf("1. �л� ��ȣ�� �Է��ϼ��� \n  > ");
	scanf("%d", &studentNumber);
	if (studentNumber == impormStuN.number)
	{
		printf("���� ��ȣ �л��� �̹� �����մϴ�.\n");
		printf("1. [���� �޴�]\n");
		printf("2. [�ٽ� �Է�]\n  >");
		scanf("%d",&n);
		if (n==1) 
		{
			menuPrint();
		}
		else if (n==2) 
		{
			inputStudentNN();
		}
		else
		{
			printf("��ȿ���� ���� �����Դϴ�\n");
			printf("���α׷��� �����մϴ�\n");
		}
	}

	printf("2. �л� �̸��� �Է��ϼ��� \n  > ");
	scanf("%s", studentName);
	
	fseek(saveFp, 0, SEEK_END);
	saveLength = ftell(saveFp);
	fseek(saveFp, 0, SEEK_SET);
	printf("saveLength Test : %d\n",saveLength);

	//oldFp.dat �������� ����� ����
	oldFp = fopen("old.dat","wb");
	if (oldFp == NULL) 
	{
		printf("old.dat ������ �����ϴ�.");
		fclose(oldFp);
		return;
	}

	//saveFp �� oldFp�� ����
	for (i = 0;  i < saveLength; i++) 
	{
		fread(&data, 1, 1, saveFp);
		fwrite(&data, 1, 1, oldFp);
		printf("oldFp �ٿ��ֱ� �� %.2f%", ((float)i / saveLength) * 100);
		system("cls");
	}
	fclose(oldFp);
	
	//saveFp ����
	
	fprintf(saveFp, "%d",studentNumber);
	fprintf(saveFp, "%s\n", studentName);
	



	fclose(saveFp);
	
	printf("������ �߰� �Ϸ�\n\n");
	printf("1. [�޴��� �̵�]\t");
	printf("2. [���α׷� ����]\n  >");
	scanf("%d", &n);
	if (n==1) 
	{
		system("cls");
		menuPrint();
	}
	else if (n==2) 
	{
		printf("���α׷��� �����մϴ�");
		return;
	}
	else 
	{
		printf("��ȿ���� ���� �����Դϴ�.\n");
		printf("���α׷��� �����մϴ�.");
		return;
	}
	

}
