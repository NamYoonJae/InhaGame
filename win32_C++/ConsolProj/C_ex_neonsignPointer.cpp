#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

//키보드 입력시 새로운 문자 입력칸이 나오고
// 입력하면 그것으로 바뀌는 네온사인으로 만들기
//과제 업로드 완료
int main(void) {

	int i = 0;
	//kbhit 입력 있으면 1 없으면 0

	//포인트 변수 선언
	char *pszBuffer = NULL;
	char *nInput = NULL;
	//동적 메모리 할당
	pszBuffer = (char*)malloc(128);
	sprintf(pszBuffer, "%s", "Hello");
	while (1)
	{
		if (_kbhit())
		{
			printf("새로운 내용을 입력하세요 : ");
			char * nInput = (char*)malloc(sizeof(char) * 128);
			memset(nInput, 0, 128); //메모리 초기화 함수, 0으로하면 자동으로 NULL값이 들어간다
			scanf("%s", nInput);//초기화를 안시켜주면 쓰레기 값이 들어간다 //scanf를 쓰면 띄어쓰기는 못 읽는다
			printf("nInput 값 %s\n", nInput);
			int temp = strlen(nInput)+1;//+1은 공백을 넣어줬다. strlen은 공백이 나올때까지측정이므로 +1로 공백까지 넣겠다는 의미
			memcpy(pszBuffer, nInput, temp);
			printf("pszBuffer 값 %s\n", pszBuffer);
			
		
			
		}

		int pszStr = strlen(pszBuffer)+1; //길이를 구한다


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