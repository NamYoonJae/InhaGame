#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main(void) {

	HANDLE hBuffer[2]; // ���۸� ������ �ڵ�
	//HANDLE g_hScreen[2];
	int nScreenIndex; //���� ���õ� ���۰� �������� ����

	//1. ���� ����
	{
		COORD size = { 80, 25 }; //����ũ����� ����ü
		SMALL_RECT rect; //â ũ�� ���� ����ü
		rect.Left = 0;
		rect.Right = 80 - 1;
		rect.Top = 0;
		rect.Bottom = 25 - 1;
		//���۸� �����ϱ� ���� ������ ũ��� â�� ũ�⸦ ������ ����ü COORD�� SMALL_RECT�� �������ְ� ���ϴ� ũ�� �Ҵ�

		//ù��° ���� ����
		hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);//���� ���� �Լ��̴�
		SetConsoleScreenBufferSize(hBuffer[0], size); //�ܼ� ������ ũ�� ���� //���� ũ����� ����ü�� �����ŭ
		SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);//�ܼ� â ũ�� ����

		//�ι�° ���� ����
		hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);//���� ���� �Լ��̴�
		SetConsoleScreenBufferSize(hBuffer[1], size);
		SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);


	}

	//2. ���� ����
	{
		int x = 0;
		int y = 0;
		char a[20] = "�Է��� ���ڿ�";

		DWORD dw; //��ǥ�� �����ϱ� ���� ����ü ����
		COORD CursorPosition = { x ,y }; //��ǥ ����
		SetConsoleCursorPosition(hBuffer[nScreenIndex], CursorPosition);	//��ǥ �̵� //ù��° ���� ǥ���ܼ��ڵ鰪�̸� �ι�° ���� ��ġ���̴�
		//WriteFile(hBuffer[nScreenIndex], a, strlen(a), &dw, NULL); //���ۿ� ��
		//������ ȯ�濡�� ���Ͽ� ����� �� ���
		//

	}

	//3. ���� ��ȯ
	{
		Sleep(33);
		SetConsoleActiveScreenBuffer(hBuffer[nScreenIndex]);//���۸� Ȱ��ȭ �����ν� ȭ�鿡 ���۳����� �ѹ��� ���
		nScreenIndex = !nScreenIndex;//nScreenIndex���� 0�� 1�� ü����
	}

	//4. ���� ���� �����
	{
		DWORD dw; //����° ���� �Լ��� ���� ����ü
		COORD Coor = { 0, 0 }; //��ǥ����
		FillConsoleOutputCharacter(hBuffer[nScreenIndex], ' ', 80 * 25, Coor, &dw);
		//������ ��� ������ �����̽� �ٸ� �־� ȭ���� ���� �� �� ó�� �����

	}

	//5. ���� ����
	{
		CloseHandle(hBuffer[0]);//���� ����
		CloseHandle(hBuffer[1]);//���� ����
	}




}
