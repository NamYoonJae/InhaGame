// Win32Collision.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32Collision.h"
#include <iostream>
#include "cShape.h"
#include  <cstdlib>
#include <vector>
#include <ctime>
#include <random>

#define MAX_LOADSTRING 100
const int  r = 30;
using namespace std;
static vector<cShape*> shapeList;
int mode = 1;

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
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

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32COLLISION, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32COLLISION));

    MSG msg;

    // Main message loop:
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

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32COLLISION));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32COLLISION);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	int mx, my;
	static RECT rt;
	

    switch (message)
    {
	case WM_CREATE:
		SetTimer(hWnd, 1, 20, NULL);
		srand((unsigned int)time(NULL));
		GetClientRect(hWnd, &rt);
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
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

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			if (shapeList.size() > 0) 
			{
				for (int i = 0; i < shapeList.size(); i++)
				{
					if (shapeList.size() > 0)
						shapeList[i]->Draw(hdc);
				}
			}


            EndPaint(hWnd, &ps);
        }
        break;

	case WM_LBUTTONDOWN:
	{
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		int random = rand() % 3;
		//random = 3;
		if (random == 0) 
		{
			cCircle* newCircle = new cCircle(mx, my, r);
			shapeList.push_back(newCircle);
		}

		else if(random == 1)
		{
			cRect*newRect = new cRect(mx, my, r);
			shapeList.push_back(newRect);
		}

		else
		{
			cStar*newStar = new cStar(mx, my, r);
			shapeList.push_back(newStar);
		}
		InvalidateRect(hWnd, NULL, TRUE);
	}

		break;

	case WM_TIMER:
	{
		int i = 0;
		int j = 0;
		int result = 0;
		//for (i = 0; i < shapeList.size(); i++) 
		//{
			//모드
			switch (mode)
			{
			//1일 경우 충돌 시 튕기기
			case 1:
				for (i = 0; i < shapeList.size(); i++)
				{
					shapeList[i]->Move();
					shapeList[i]->Spin();
					shapeList[i]->Collision(shapeList, i, rt, 1);
				}
				break;
			//2일 경우 충돌 시 합치기
			case 2:
				for (i = 0; i < shapeList.size(); i++)
				{
					shapeList[i]->Move();
					shapeList[i]->Spin();
					result = shapeList[i]->Collision(shapeList, i, rt, 2);
					if (result == 1)
						break;

				}
				break;
			//3일 경우 충돌 시 쪼개기
			case 3:
				for (i = 0; i < shapeList.size(); i++)
				{
					shapeList[i]->Move();
					shapeList[i]->Spin();
					result = shapeList[i]->Collision(shapeList, i, rt, 3);
					if (result == 1)

						break;

				}
				break;
			default:
				break;
			}
			
		//}

		InvalidateRect(hWnd, NULL, TRUE);
	}
		break;

	case WM_CHAR:
		switch (wParam)
		{
		case '1':
			mode = 1;
			break;
		case '2':
			mode = 2;
			break;
		case '3':
			mode = 3;
			break;

		default:
			break;
		}
		break;

    case WM_DESTROY:
		KillTimer(hWnd, 1);
        PostQuitMessage(0);
        break;


    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
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