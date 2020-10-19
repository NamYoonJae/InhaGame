#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
	Q. 번호, 이름, 성적, 다음 구조체의 주소를 입력받을 수 있는 구조체를 만들고
	학생수를 모르는 반의 데이터를 계속해서 입력받아 출력하는 코드를 만든다.
	새로운 학생이 입력되면 다음 구조체의 주소가 자동으로 입력되는 방식.
	전체 출력 역시도 Single Linked List를 이용해서 출력하세요.
*/

typedef struct UserData
{
	int szNumber;
	char szName[32];
	char szPhone[32];
	struct UserData *pNext;

} UserData;


void main(void) {

	UserData *pUserData= NULL;
	UserData *pUserDataTemp = NULL;	// 다음 새로운 구조체

	pUserData = (UserData*)malloc(sizeof(UserData));
	memset(pUserData, 0, sizeof(UserData));

	UserData *userDataHead = pUserData;//처음시작점을 나타내는 포인터


	int i = 0;

	while (1) 
	{
		printf("번호 이름 핸드폰번호를 입력하세요 : ");

		scanf("%d %s %s", &pUserData->szNumber, pUserData->szName, pUserData->szPhone);
		pUserData->pNext = NULL;
		//printf("데이터 입력 테스트 : %d %s %s \n\n", pUserData->szNumber, pUserData->szName, pUserData->szPhone);
		
		printf("\n계속하려면 엔터 입력 \n종료하려면 -1입력\n");
		rewind(stdin);
		if (scanf("%[^\n]s", &pUserData) == -1) break;


		pUserDataTemp = (UserData*)malloc(sizeof(UserData));	//메모리 할당
		memset(pUserDataTemp, 0, sizeof(UserData));	//메모리 초기화
		pUserData->pNext = pUserDataTemp;	//pUserData->pNext은 현재 NULL값 여기에 pUserDataTemp를 연결함으로 새로 생성된 구조체랑 연결
		pUserData = pUserDataTemp;	//이제 위치점을 temp쪽으로 바꿔야 하기떄문에 대입

	}
	
	while (userDataHead !=NULL)
	{
		printf("%d %s %s\n", userDataHead->szNumber, userDataHead->szName, userDataHead->szPhone);
		userDataHead = userDataHead->pNext;
	}

	free(pUserDataTemp);
	free(pUserData);

}