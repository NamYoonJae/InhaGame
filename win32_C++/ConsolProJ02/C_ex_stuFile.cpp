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

	menuPrint();	//메뉴 출력 함수




}

void menuPrint()
{
	int n = 0;

	printf("==================\n");
	printf("메뉴를 선택하세요\n");
	printf("==================\n");
	printf("1. 데이터 추가\n");
	printf("2. 검색 출력\n");
	printf("3. 변경\n");
	printf("4. 복구\n");
	printf("5. 종료\n");
	printf("==================\n\n");
	printf("입력 >");

	scanf("%d", &n);
	system("cls");

	switch (n)
	{
	case 1:

		inputStudentNN();

		break;
	case 2:
		printf("==================\n");
		printf("2. 검색 출력\n");
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
		printf("프로그램을 종료하시겠습니까?\n");
		printf("1. [Yes]\t");
		printf("2. [No]\n");
		printf("=============================\n");
		printf("입력 > ");
		scanf("%d", &n);
		if (n == 1)
		{
			printf("프로그램을 종료합니다\n");
			return;
		}
		else if (n == 2)
		{
			system("cls");
			menuPrint();
		}

	default:
		printf("유효한 숫자가 아닙니다.\n\n");
		printf("1. [이전메뉴]\t");
		printf("2. [종료]");
		scanf("%d", &n);
		system("cls");
		if (n==1) 
		{
			menuPrint();
		}
		else if(n==2)
		{
			printf("프로그램을 종료합니다\n");
			return;
		}
		else 
		{
			printf("유효하지 않은 숫자입니다\n");
			printf("프로그램을 종료합니다\n");
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

	//save.dat ad(있으면 기존내용에서 추가 없으면 새로만듬)
	//saveFp = fopen("save.dat", "rb");
	//fread(&impormBuffer, sizeof(impormation) , 1, saveFp);
	printf("==================\n");
	printf("1. 데이터 추가\n");
	printf("==================\n\n");

	printf("1. 학생 번호를 입력하세요 \n  > ");
	scanf("%d", &studentNumber);
	if (studentNumber == impormStuN.number)
	{
		printf("같은 번호 학생이 이미 존재합니다.\n");
		printf("1. [메인 메뉴]\n");
		printf("2. [다시 입력]\n  >");
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
			printf("유효하지 않은 숫자입니다\n");
			printf("프로그램을 종료합니다\n");
		}
	}

	printf("2. 학생 이름을 입력하세요 \n  > ");
	scanf("%s", studentName);
	
	fseek(saveFp, 0, SEEK_END);
	saveLength = ftell(saveFp);
	fseek(saveFp, 0, SEEK_SET);
	printf("saveLength Test : %d\n",saveLength);

	//oldFp.dat 기존내용 지우고 열기
	oldFp = fopen("old.dat","wb");
	if (oldFp == NULL) 
	{
		printf("old.dat 파일이 없습니다.");
		fclose(oldFp);
		return;
	}

	//saveFp 를 oldFp에 복사
	for (i = 0;  i < saveLength; i++) 
	{
		fread(&data, 1, 1, saveFp);
		fwrite(&data, 1, 1, oldFp);
		printf("oldFp 붙여넣기 중 %.2f%", ((float)i / saveLength) * 100);
		system("cls");
	}
	fclose(oldFp);
	
	//saveFp 갱신
	
	fprintf(saveFp, "%d",studentNumber);
	fprintf(saveFp, "%s\n", studentName);
	



	fclose(saveFp);
	
	printf("데이터 추가 완료\n\n");
	printf("1. [메뉴로 이동]\t");
	printf("2. [프로그램 종료]\n  >");
	scanf("%d", &n);
	if (n==1) 
	{
		system("cls");
		menuPrint();
	}
	else if (n==2) 
	{
		printf("프로그램을 종료합니다");
		return;
	}
	else 
	{
		printf("유효하지 않은 숫자입니다.\n");
		printf("프로그램을 종료합니다.");
		return;
	}
	

}
