#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
	Q. ��ȣ, �̸�, ����, ���� ����ü�� �ּҸ� �Է¹��� �� �ִ� ����ü�� �����
	�л����� �𸣴� ���� �����͸� ����ؼ� �Է¹޾� ����ϴ� �ڵ带 �����.
	���ο� �л��� �ԷµǸ� ���� ����ü�� �ּҰ� �ڵ����� �ԷµǴ� ���.
	��ü ��� ���õ� Single Linked List�� �̿��ؼ� ����ϼ���.
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
	UserData *pUserDataTemp = NULL;	// ���� ���ο� ����ü

	pUserData = (UserData*)malloc(sizeof(UserData));
	memset(pUserData, 0, sizeof(UserData));

	UserData *userDataHead = pUserData;//ó���������� ��Ÿ���� ������


	int i = 0;

	while (1) 
	{
		printf("��ȣ �̸� �ڵ�����ȣ�� �Է��ϼ��� : ");

		scanf("%d %s %s", &pUserData->szNumber, pUserData->szName, pUserData->szPhone);
		pUserData->pNext = NULL;
		//printf("������ �Է� �׽�Ʈ : %d %s %s \n\n", pUserData->szNumber, pUserData->szName, pUserData->szPhone);
		
		printf("\n����Ϸ��� ���� �Է� \n�����Ϸ��� -1�Է�\n");
		rewind(stdin);
		if (scanf("%[^\n]s", &pUserData) == -1) break;


		pUserDataTemp = (UserData*)malloc(sizeof(UserData));	//�޸� �Ҵ�
		memset(pUserDataTemp, 0, sizeof(UserData));	//�޸� �ʱ�ȭ
		pUserData->pNext = pUserDataTemp;	//pUserData->pNext�� ���� NULL�� ���⿡ pUserDataTemp�� ���������� ���� ������ ����ü�� ����
		pUserData = pUserDataTemp;	//���� ��ġ���� temp������ �ٲ�� �ϱ⋚���� ����

	}
	
	while (userDataHead !=NULL)
	{
		printf("%d %s %s\n", userDataHead->szNumber, userDataHead->szName, userDataHead->szPhone);
		userDataHead = userDataHead->pNext;
	}

	free(pUserDataTemp);
	free(pUserData);

}