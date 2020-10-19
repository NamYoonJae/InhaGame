// Thread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <process.h>

//createThread�� ���� ���۳� �޸� �Ҵ� �� �� �������� �ʴ�
//�׷��� ������ beginThread�� ��ȣ�ϴ°� ����

int Value = 0;
int ValuePlusOne = 0;

int Cnt = 0;	// : Value > ValuePlusOne���� �߻��� ��� üũ�غ����� �ϴ� ����
bool isChecked = false;

CRITICAL_SECTION cs;

DWORD WINAPI ThFunc1(LPVOID lpParam) 
{
	while (1)
	{
		//isChecked = false;//<1> //<1>, <2>, <3> �� ������ �۵��� ���� �ִ� �̰� �����ϱ� ���� isChecked�� �̿��ؼ� ����ش�
		EnterCriticalSection(&cs);	//ũ��Ƽ�� ������ ����ؼ� �� �۾��� ������ ���� �ٸ� �۾����� ����Ī���� ���ϰ� �Ѵ�.
		Value = rand() % 1000;
		ValuePlusOne = Value + 1;	//<3>
		//isChecked = true;
		LeaveCriticalSection(&cs);
	}

	return 0;
}

DWORD WINAPI ThFunc2(LPVOID lpParam)
{
	while (1)
	{
		//if (isChecked) 
		//{
			EnterCriticalSection(&cs);
			if (Value > ValuePlusOne)	//<2>
				printf("%d\n", Cnt++);
			LeaveCriticalSection(&cs);
		//}
	}

	return 0;
}

unsigned __stdcall ThFunc7(LPVOID lpParam);

unsigned __stdcall ThFunc8(LPVOID lpParam);


int main()
{
	InitializeCriticalSection(&cs);	//ũ��Ƽ�� ������ ����ϰڴٰ� �����Ѵ�

	DWORD dwThID1, dwThID2;
	HANDLE hThread[2];

	unsigned long ulStackSize = 0;

	dwThID1 = 0; dwThID2 = 0;
	hThread[0] = NULL; hThread[1] = NULL;

	//������ ���� 1�� ���
	//hThread[0] = CreateThread(NULL, ulStackSize, ThFunc1, NULL, CREATE_SUSPENDED, &dwThID1);	//CREATE_SUSPENDED�����ϰ� �ٷ� �����̾ƴ� ��� ���·� �����
	//hThread[1] = CreateThread(NULL, ulStackSize, ThFunc1, NULL, CREATE_SUSPENDED, &dwThID2);

	//������ ���� 2�� ���
	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, (unsigned(__stdcall*)(void*))ThFunc7, NULL, 0, (unsigned*)&dwThID1);
	hThread[1] = (HANDLE)_beginthreadex(NULL, 0, (unsigned(__stdcall*)(void*))ThFunc8, NULL, 0, (unsigned*)&dwThID2);

	if (hThread[0] == 0 || hThread[1] == 0) 
	{
		exit(1);
	}

	ResumeThread(hThread[0]);
	ResumeThread(hThread[1]);

	WaitForMultipleObjects(2, hThread, TRUE, INFINITE);

	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);

	DeleteCriticalSection(&cs);

    return 0;
}

unsigned __stdcall ThFunc7(LPVOID lpParam)
{
	while (1)
	{
		EnterCriticalSection(&cs);
		Value = rand() % 1000;
		ValuePlusOne = Value + 1;
									
		LeaveCriticalSection(&cs);
	}
	return 0;
}

unsigned __stdcall ThFunc8(LPVOID lpParam)
{
	while (1)
	{

		EnterCriticalSection(&cs);
		if (Value > ValuePlusOne)
			printf("%d\n", Cnt++);
		LeaveCriticalSection(&cs);

	}
	return 0;
}
