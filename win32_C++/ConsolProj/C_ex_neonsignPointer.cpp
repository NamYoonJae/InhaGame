#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//Ű���� �Է½� ���ο� ���� �Է�ĭ�� ������
// �Է��ϸ� �װ����� �ٲ�� �׿»������� �����
//���� ���ε� �Ϸ�
int main(void) {

	int i = 0;
	//kbhit �Է� ������ 1 ������ 0

	//����Ʈ ���� ����
	char *pszBuffer = NULL;
	char *nInput = NULL;
	//���� �޸� �Ҵ�
	pszBuffer = (char*)malloc(128);
	sprintf(pszBuffer, "%s", "Hello");
	while (1)
	{
		if (_kbhit())
		{
			printf("���ο� ������ �Է��ϼ��� : ");
			char * nInput = (char*)malloc(sizeof(char) * 128);
			memset(nInput, 0, 128); //�޸� �ʱ�ȭ �Լ�, 0�����ϸ� �ڵ����� NULL���� ����
			scanf("%s", nInput);//�ʱ�ȭ�� �Ƚ����ָ� ������ ���� ���� //scanf�� ���� ����� �� �д´�
			printf("nInput �� %s\n", nInput);
			int temp = strlen(nInput)+1;//+1�� ������ �־����. strlen�� ������ ���ö����������̹Ƿ� +1�� ������� �ְڴٴ� �ǹ�
			memcpy(pszBuffer, nInput, temp);
			printf("pszBuffer �� %s\n", pszBuffer);
			
		
			
		}

		int pszStr = strlen(pszBuffer)+1; //���̸� ���Ѵ�


		char pszTemp = pszBuffer[0];


		for (i = 0; i <pszStr-1; i++)
		{	
			pszBuffer[i] = pszBuffer[i + 1];
		}

		pszBuffer[pszStr-2] = pszTemp;

		printf("%s", pszBuffer);

		free(nInput);
		
		Sleep(2000);
		system("cls");
		
		
	}


	return 0;
}