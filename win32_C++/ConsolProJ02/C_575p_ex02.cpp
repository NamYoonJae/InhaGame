#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//���� 575p �������� 2��
/*
	���� ��ο��� "TestFile.txt" �ؽ�Ʈ ������ �� ��, ����ڰ� �Է��� ���ڿ��� �ڿ� �̾
	�߰��� �� �ٽ� �����ϴ� ���α׷��� �ۼ��ϼ���

*/

void main(void) {

	FILE *fp = NULL;

	fp = fopen("TestFile.txt", "a");

	char inputString[64];
	printf("�߰��� ���ڿ��� �Է��ϼ��� : ");
	scanf("%s", inputString);
	fprintf(fp, "%s", inputString);

	fclose(fp);
}