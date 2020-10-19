// Win32A_Star.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Win32A_Star.h"
#include "A_Star_Class.h"
#include <iostream>
#include <vector>

#define MAX_LOADSTRING 100

using namespace std;

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.


static vector <AStar*> vAStarList;
void CreateMap();


// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32A_STAR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32A_STAR));

    MSG msg;

    // 기본 메시지 루프입니다.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32A_STAR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32A_STAR);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int mx, my;
    switch (message)
    {
	case WM_CREATE:
		CreateMap();
		SetTimer(hWnd, 1, 70, NULL);


		AllocConsole();
		freopen("CONOUT$", "wt", stdout);
		break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다.
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;

            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;

            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

	case WM_LBUTTONDOWN:
		{
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		//모든 객체의 센터점과의 거리 비교후 가장 작은 거리의 도형



		}
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			HBRUSH Brush, oBrush;
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.
			int state = 0;

			if (vAStarList.size() > 0) 
			{
				for (int i = 0; i < vAStarList.size(); i++)
				{
					state = vAStarList[i]->GetState();

					if (state == 0)
					{
						Brush = CreateSolidBrush(RGB(255, 255, 255));
						oBrush = (HBRUSH)SelectObject(hdc, Brush);
						vAStarList[i]->DrawAMap(hdc);
						SelectObject(hdc, oBrush);
						DeleteObject(Brush);
					}
					else if (state == 1)
					{
						Brush = CreateSolidBrush(RGB(50, 50, 50));
						oBrush = (HBRUSH)SelectObject(hdc, Brush);
						vAStarList[i]->DrawAMap(hdc);
						SelectObject(hdc, oBrush);
						DeleteObject(Brush);
					}
					
				}
			}
			
			
            EndPaint(hWnd, &ps);
        }
        break;

	case WM_TIMER:
		InvalidateRect(hWnd, NULL, FALSE);
		break;

    case WM_DESTROY:
		FreeConsole();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


void CreateMap()
{

	int i = 0;
	int j = 0;
	int x = 20;
	int y = 20;
	int temp = 0;

	for (i = 0; i <15; i++) 
	{
		for (j = 0; j <15; j++) 
		{
			AStar* newAStar = new AStar(x, y);
			vAStarList.push_back(newAStar);
			x = x + 40;
		}
		x = 20;
		y = y + 40;
	}

	/*
	int tempX = 0;
	int tempY = 0;
	//도형의 centerX 와 centerY 가 모두 홀수이면 벽돌 생성
	cout << "CreateMap" << endl;
	
	for (i = 0; i< vAStarList.size(); i++)
	{
		tempX = vAStarList[i]->GetCenterX();
		tempY = vAStarList[i]->GetCenterY();

		if (tempX % 2 == 1 && tempY % 2 == 1) 
		{
			vAStarList[i]->ChangeState();
		}


	}
	*/

	/*
	// 벽돌
	for (i = 48; i<57; i++) 
	{
		vAStarList[i]->ChangeState();
	}
	temp = 47;
	for (i = 0; i<6; i++)
	{
		vAStarList[temp]->ChangeState();
		temp += 16;
	}
	temp = 64;
	for (i = 0; i<4; i++)
	{
		vAStarList[temp]->ChangeState();
		temp += 16;
	}

	
	temp = 85;
	for (i = 0; i<8; i++) 
	{
		vAStarList[temp]->ChangeState();
		temp += 15;
	}

	temp = 106;
	for (i = 0; i<6; i++)
	{
		vAStarList[temp]->ChangeState();
		temp += 16;
	}

	temp = 121;
	for (i = 0; i<6; i++)
	{
		vAStarList[temp]->ChangeState();
		temp += 16;
	}

	for (i = 202; i<209; i++)
	{
		vAStarList[i]->ChangeState();
	}
	
	*/
}