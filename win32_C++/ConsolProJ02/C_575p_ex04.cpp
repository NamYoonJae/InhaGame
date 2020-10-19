#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//교재 575p 연습문제 04

/*


	파일명을 입력받으면 같은 폴더에 DstFile이름으로 복사하는 프로그램을 작성합니다.
	단, 문제에 나온 .txt만이 아닌 다른 확장자(예를 들어 .png 등) 역시도 처리할 수 있게 작성.
	여기에 복사의 진행 과정을 백분율로 화면에 출력하고, 한 번에 4KB 단위로 복사하게 작성.

	TIPS) 마지막 4KB 이하의 자투리 공간 처리에 주의해야 한다.


*/

void main(void) {


	FILE *fp = NULL;
	FILE *fp2 = NULL;

	char fileName[50] = { 0 };
	char inputFileName[30] = { 0 };
	char inputFileEx[10] = { 0 };
	char data[4096] = {0};

	int length = 0;
	int i = 0;
	float down = 0;

	printf("파일명을 입력하세요 \nex> test\n\n입력 >");
	scanf("%s",inputFileName);
	printf("\n\n");
	printf("확장자를 입력하세요 \nex> txt\n\n입력 >");
	scanf("%s", inputFileEx);

	sprintf(fileName, "%s.%s", inputFileName, inputFileEx);
	printf("sprintf 테스트 : %s",fileName);
	
	fp = fopen(fileName, "rb");
	if (fp == NULL) 
	{
		printf("파일이 없습니다");
		fclose(fp);
		return;
	}

	//파일 크기 구하기
	fseek(fp, 0, SEEK_END);//포인터 끝으로 이동
	length = ftell(fp);//(포인터 끝에있는 상태)현재 위치를 구하면서 파일 크기 구함

	fseek(fp, 0, SEEK_SET); //사이즈 재기위해 포인터를 END쪽으로 이동했으니 다시 시작점으로 이동

	fp2 = fopen("DstFile.jpg", "wb");
	if (fp2 == NULL) 
	{
		printf("파일이 없습니다");
		fclose(fp2);
		return;
	}

	for (i = 0; i < length/4096; i++) 
	{
		fread(data, 4096, 1, fp);//정보를 읽어옴
		fwrite(data, 4096, 1, fp2);//대상파일에 정보 복사
		printf("다운로드중 %.2f%", ((float)i / (length/4096))*100);
		system("cls");
	}

	printf("==============================================\n");
	int length2 = ftell(fp2);
	int rest = length - length2;
	printf("남은 파일크기 : %d\n", rest);
	printf("==============================================\n");
	printf("잠시후 남은파일을 다운로드합니다\n");
	printf("==============================================\n");
	fseek(fp2, length2, SEEK_SET);
	Sleep(3000);


	for (i = 0; i <rest; i++) 
	{
		fread(&data, 1, 1, fp);
		fwrite(&data, 1, 1, fp2);
		printf("다운로드중 %.2f%", ((float)i / rest) * 100);
		system("cls");
	}
	printf("다운로드 완료\n");



	fclose(fp2);
	fclose(fp);



}