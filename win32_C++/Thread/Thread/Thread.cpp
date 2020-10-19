// Thread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <process.h>

//createThread는 정적 버퍼나 메모리 할당 할 때 안전하지 않다
//그렇기 떄문에 beginThread를 선호하는게 좋다

int Value = 0;
int ValuePlusOne = 0;

int Cnt = 0;	// : Value > ValuePlusOne경우는 발생할 경우 체크해보려고 하는 변수
bool isChecked = false;

CRITICAL_SECTION cs;

DWORD WINAPI ThFunc1(LPVOID lpParam) 
{
	while (1)
	{
		//isChecked = false;//<1> //<1>, <2>, <3> 번 순서도 작동할 떄가 있다 이걸 방지하기 위해 isChecked를 이용해서 잡아준다
		EnterCriticalSection(&cs);	//크리티컬 섹션을 사용해서 이 작업이 끝날때 까지 다른 작업으로 스위칭되지 못하게 한다.
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
	InitializeCriticalSection(&cs);	//크리티컬 섹션을 사용하겠다고 정의한다

	DWORD dwThID1, dwThID2;
	HANDLE hThread[2];

	unsigned long ulStackSize = 0;

	dwThID1 = 0; dwThID2 = 0;
	hThread[0] = NULL; hThread[1] = NULL;

	//쓰레드 생성 1번 방법
	//hThread[0] = CreateThread(NULL, ulStackSize, ThFunc1, NULL, CREATE_SUSPENDED, &dwThID1);	//CREATE_SUSPENDED생성하고 바로 실행이아닌 대기 상태로 만든다
	//hThread[1] = CreateThread(NULL, ulStackSize, ThFunc1, NULL, CREATE_SUSPENDED, &dwThID2);

	//쓰레드 생성 2번 방법
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
