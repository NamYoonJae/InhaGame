#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//522p �ణ �������� ����غ��� //�Է��� ���� �� �����ϴ� ���

typedef struct USERDATA 
{
	int nAge[32] = {0};
	char szName[32] = {0};
	char szPhone[32] = {0};
};



void main(void) {

	USERDATA userList[4];
	/*
	userList[0].nAge = 10;	//�������̶� strcpy �� �ƴ� �׳� �������� �ؾ��Ѵ�
	userList[1].nAge = 11;
	userList[2].nAge = 12;
	userList[3].nAge = 13;

	strcpy(userList[0].szName, "�����");
	strcpy(userList[1].szName, "������");
	strcpy(userList[2].szName, "������");
	strcpy(userList[3].szName, "����");


	strcpy(userList[0].szphone, "1234");
	strcpy(userList[1].szphone, "2345");
	strcpy(userList[2].szphone, "3456");
	strcpy(userList[3].szphone, "4567");
	*/

	int i = 0;

	// userList[3].no = "2005"; �̰� �Ұ����ϴ�
	//strcpy �� ����ؾ��Ѵ�
	
	for (i = 0; i < 1; ++i) 
	{
		/*
		printf("%d��\t %s\t %s\n",
			userList[i].nAge,userList[i].szName,
			userList[i].szphone);
		*/
		printf("%d�� ���� �̸� �ڵ�����ȣ�� �Է��ϼ��� : ",i+1);
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