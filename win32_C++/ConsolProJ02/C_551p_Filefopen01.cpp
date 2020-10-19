#include <stdio.h>
#include "stdafx.h"

//에디터 상에는 그 위의 파일에 텍스트 파일이 생성된다
//그러나 그 경로의 디버그 폴더에 실행파일이 있는데 그것을 실행하면 바로 그 경로(디버그경로)에 생성된다.
void main() 
{
	FILE *fp = NULL;
	FILE *fp2 = NULL;
	FILE *fp3 = NULL;

	fp = fopen("Test.txt", "w");
	fp2 = fopen("Test2.txt", "w");
	fp3 = fopen("Test3.txt", "w");


	if (fopen == NULL) 
	{
		puts("Error : Failed to open file!");
			return;
	}

	//fclose;

	//교재 552p
	//닫힌 파일 갯수 출력해보기
	int nClose = fcloseall();
	printf("Count : %d\n", nClose);



}