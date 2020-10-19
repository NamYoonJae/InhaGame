#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//���� 575p �������� 04

/*


	���ϸ��� �Է¹����� ���� ������ DstFile�̸����� �����ϴ� ���α׷��� �ۼ��մϴ�.
	��, ������ ���� .txt���� �ƴ� �ٸ� Ȯ����(���� ��� .png ��) ���õ� ó���� �� �ְ� �ۼ�.
	���⿡ ������ ���� ������ ������� ȭ�鿡 ����ϰ�, �� ���� 4KB ������ �����ϰ� �ۼ�.

	TIPS) ������ 4KB ������ ������ ���� ó���� �����ؾ� �Ѵ�.


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

	printf("���ϸ��� �Է��ϼ��� \nex> test\n\n�Է� >");
	scanf("%s",inputFileName);
	printf("\n\n");
	printf("Ȯ���ڸ� �Է��ϼ��� \nex> txt\n\n�Է� >");
	scanf("%s", inputFileEx);

	sprintf(fileName, "%s.%s", inputFileName, inputFileEx);
	printf("sprintf �׽�Ʈ : %s",fileName);
	
	fp = fopen(fileName, "rb");
	if (fp == NULL) 
	{
		printf("������ �����ϴ�");
		fclose(fp);
		return;
	}

	//���� ũ�� ���ϱ�
	fseek(fp, 0, SEEK_END);//������ ������ �̵�
	length = ftell(fp);//(������ �����ִ� ����)���� ��ġ�� ���ϸ鼭 ���� ũ�� ����

	fseek(fp, 0, SEEK_SET); //������ ������� �����͸� END������ �̵������� �ٽ� ���������� �̵�

	fp2 = fopen("DstFile.jpg", "wb");
	if (fp2 == NULL) 
	{
		printf("������ �����ϴ�");
		fclose(fp2);
		return;
	}

	for (i = 0; i < length/4096; i++) 
	{
		fread(data, 4096, 1, fp);//������ �о��
		fwrite(data, 4096, 1, fp2);//������Ͽ� ���� ����
		printf("�ٿ�ε��� %.2f%", ((float)i / (length/4096))*100);
		system("cls");
	}

	printf("==============================================\n");
	int length2 = ftell(fp2);
	int rest = length - length2;
	printf("���� ����ũ�� : %d\n", rest);
	printf("==============================================\n");
	printf("����� ���������� �ٿ�ε��մϴ�\n");
	printf("==============================================\n");
	fseek(fp2, length2, SEEK_SET);
	Sleep(3000);


	for (i = 0; i <rest; i++) 
	{
		fread(&data, 1, 1, fp);
		fwrite(&data, 1, 1, fp2);
		printf("�ٿ�ε��� %.2f%", ((float)i / rest) * 100);
		system("cls");
	}
	printf("�ٿ�ε� �Ϸ�\n");



	fclose(fp2);
	fclose(fp);



}