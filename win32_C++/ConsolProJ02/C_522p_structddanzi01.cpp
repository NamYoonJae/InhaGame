#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//522p 약간 변형시켜 사용해보자 //입력을 받은 값 저장하는 방법

typedef struct USERDATA 
{
	int nAge[32] = {0};
	char szName[32] = {0};
	char szPhone[32] = {0};
};



void main(void) {

	USERDATA userList[4];
	/*
	userList[0].nAge = 10;	//정수형이라서 strcpy 가 아닌 그냥 대입으로 해야한다
	userList[1].nAge = 11;
	userList[2].nAge = 12;
	userList[3].nAge = 13;

	strcpy(userList[0].szName, "김어준");
	strcpy(userList[1].szName, "정봉주");
	strcpy(userList[2].szName, "주진우");
	strcpy(userList[3].szName, "김용민");


	strcpy(userList[0].szphone, "1234");
	strcpy(userList[1].szphone, "2345");
	strcpy(userList[2].szphone, "3456");
	strcpy(userList[3].szphone, "4567");
	*/

	int i = 0;

	// userList[3].no = "2005"; 이건 불가능하다
	//strcpy 를 사용해야한다
	
	for (i = 0; i < 1; ++i) 
	{
		/*
		printf("%d살\t %s\t %s\n",
			userList[i].nAge,userList[i].szName,
			userList[i].szphone);
		*/
		printf("%d번 나이 이름 핸드폰번호를 입력하세요 : ",i+1);
		scanf("%s %s %s",userList[i].nAge, userList[i].szName, userList[i].szPhone);
		printf("\n");

	}

	for (i = 0; i < 1; i++) 
	{
		printf("%s %s %s\n", userList[i].nAge, userList[i].szName, userList[i].szPhone);
	}

	/*
	while (i<4)
	{
		scanf("%d %s %s", userList[i].nAge, userList[i].szName, userList[i].szPhone);
	}
	*/
}