#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
	번호, 이름, 성적을 입력 받을 수 있는 구조체를 만들고 
	학생수 10명인 반의 데이터를 입력받아 출력하는 코드를 만든다.
	ex)
		1. 입력 - 학생의 번호, 이름, 성적을 순차적으로 입력
		2. 검색 - 이름으로 해당 학생의 번호, 이름, 성적을 출력
		3, 전체출력 - 전체 학생의 번호, 이름, 성적을 출력
		4. 종료 - 프로그램 종료

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
		printf("핸드폰번호 이름 성적을 입력하세요 : ");
		scanf("%s %s %d", pStudent[i].phone, pStudent[i].name, &pStudent[i].grade);

	}

	//전체 출력
	for (i = 0; i < 10; i++) 
	{
		printf("%s %s %d\n", pStudent[i].phone, pStudent[i].name, pStudent[i].grade);
	}


	//학생 이름으로 정보 검색
	printf("검색할 학생 이름을 입력하세요 : ");
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