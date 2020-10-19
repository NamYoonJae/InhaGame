// Win32ProjectJDivision.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <windows.h>
#pragma comment(lib, "msimg32.lib")
#include <TCHAR.h>
#include "Resource.h"
#define _USE_MATH_DEFINES
#include<math.h>

#define MAX_LOADSTRING 100
enum 
{
	enum_circle = 1,
	enum_rectangle = 2,
	enum_star = 3,
};

static int shape;
double r_size = 50;
POINT point[10];

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// >>:
#define IDC_CHILD_BTN 100
#define IDC_CHILD_BTN1 101
#define IDC_CHILD_BTN2 102
RECT rectView;

HWND childHwnd[3];
LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChildWndProc2(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChildWndProc3(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

// >>:

void DrawCircle(HDC hdc, int x, int y);
void DrawRectangle(HDC hdc, int x, int y);
void DrawStar(HDC hdc, int x, int y);
void DrawStar(HDC hdc);


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
    LoadStringW(hInstance, IDC_WIN32PROJECTJDIVISION, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECTJDIVISION));

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



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECTJDIVISION));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32PROJECTJDIVISION);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWndProc;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child1");
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWndProc2;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child2");
	RegisterClassExW(&wcex);
	
	wcex.lpfnWndProc = ChildWndProc3;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child3");
	RegisterClassExW(&wcex);

	
    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
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

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc = GetDC(hWnd);
	SetTimer(hWnd, 1, 70, NULL);
    switch (message)
    {
	case WM_CREATE:
		GetClientRect(hWnd, &rectView);
		
		childHwnd[0] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child1"), NULL,
			WS_CHILD | WS_VISIBLE,
			0, 0, rectView.right / 2 - 1, rectView.bottom / 2 - 1,
			hWnd, NULL, hInst, NULL);

		childHwnd[1] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child2"),
			NULL,
			WS_CHILD | WS_VISIBLE,
			0, rectView.bottom / 2 + 1, rectView.right / 2 - 1, rectView.bottom / 2 - 1,
			hWnd, NULL, hInst, NULL);

		childHwnd[2] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child3"),
			NULL,
			WS_CHILD | WS_VISIBLE,
			rectView.right / 2, 0, rectView.right, rectView.bottom,
			hWnd, NULL, hInst, NULL);
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
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;

    case WM_DESTROY:
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


LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc = GetDC(hWnd);
	SetTimer(hWnd, 1, 70, NULL);
	int x, y;
	switch (iMsg)
	{
	case WM_CREATE:
		break;

	case WM_PAINT:
		break;
	case WM_TIMER:

		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);

		if (shape == enum_circle) 
		{
			DrawCircle(hdc, x, y);
		}
		else if (shape == enum_rectangle) 
		{
			DrawRectangle(hdc, x, y);
		}
		else if (shape == enum_star) 
		{
			DrawStar(hdc, x, y);
		}
		break;
		InvalidateRect(hWnd, NULL, FALSE);
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		break;

	default:
		break;
	}

	ReleaseDC(hWnd, hdc);
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

LRESULT CALLBACK ChildWndProc2(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc = GetDC(hWnd);

	SetTimer(hWnd, 1, 70, NULL);
	switch (iMsg)
	{
	case WM_CREATE:
		break;

	case WM_TIMER:
		if (shape == enum_circle) 
		{
			Ellipse(hdc, 100, 100, 200, 200);
		}
		else if (shape == enum_rectangle) 
		{
			
			Rectangle(hdc, 250, 100, 350, 200);
		}
		else if (shape == enum_star) 
		{
			DrawStar(hdc);
			Polygon(hdc, point, 10);
		}

		break;
		InvalidateRect(hWnd, NULL, FALSE);
	default:
		break;
	}
	ReleaseDC(hWnd, hdc);
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

LRESULT CALLBACK ChildWndProc3(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hButton, hButton1, hButton2;
	SetTimer(hWnd, 1, 70, NULL);


	switch (iMsg)
	{

	case WM_CREATE:
		hButton = CreateWindow(_T("button"), _T("원"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 200, 10, 100, 25, hWnd, (HMENU)IDC_CHILD_BTN, hInst, NULL);
		hButton1 = CreateWindow(_T("button"), _T("사각형"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 200, 40, 100, 25, hWnd, (HMENU)IDC_CHILD_BTN1, hInst, NULL);
		hButton2 = CreateWindow(_T("button"), _T("별"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 200, 70, 100, 25, hWnd, (HMENU)IDC_CHILD_BTN2, hInst, NULL);
		break;
	case WM_COMMAND:
		
		switch (LOWORD(wParam))
		{
		case IDC_CHILD_BTN:
			shape = enum_circle;
			break;

		case IDC_CHILD_BTN1:
			shape = enum_rectangle;
			break;

		case IDC_CHILD_BTN2:
			shape = enum_star;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

void DrawCircle(HDC hdc, int x, int y)
{
	Ellipse(hdc, x - r_size, y - r_size, x + r_size, y + r_size);
}

void DrawRectangle(HDC hdc, int x, int y)
{
	Rectangle(hdc, x - r_size, y - r_size, x + r_size, y + r_size);
}

void DrawStar(HDC hdc, int x, int y)
{
	int centerX = x, centerY = y;

	double a, b, c, d, e, f, k, s_x, s_y, s_r2;
	int i = 0;
	//센터 x,y  반지름 r

	for (i = 0; i <5; i++)
	{

		point[2 * i].x = long(centerX + r_size * sin((72 * i) * M_PI / 180));
		point[2 * i].y = long(centerY - r_size * cos((72 * i) * M_PI / 180));
	}
	a = point[4].y - point[0].y;
	b = point[0].x - point[4].x;
	c = point[2].y - point[8].y;
	d = point[8].x - point[2].x;
	e = a*point[0].x + b*point[0].y;
	f = c*point[2].x + d*point[2].y;

	k = a*d - b * c;

	s_x = (e*d - b*f) / k;
	s_y = (a*f - e*c) / k;

	s_r2 = long(sqrt(pow(s_x - centerX, 2) + pow(s_y - centerY, 2)));

	for (i = 0; i < 5; i++)
	{
		point[2 * i + 1].x = long(centerX + s_r2 * sin((72 * i + 32) * M_PI / 180));
		point[2 * i + 1].y = long(centerY - s_r2 * cos((72 * i + 32) * M_PI / 180));
	}

	Polygon(hdc, point, 10);
}



void DrawStar(HDC hdc)
{
	int centerX = 450, centerY = 150;
	int i = 0;

	double a, b, c, d, e, f, k, s_x, s_y, s_r2;

	//센터 x,y  반지름 r
	
	for (i = 0; i <5; i++)
	{

		point[2 * i].x = long(centerX + r_size * sin((72 * i) * M_PI / 180));
		point[2 * i].y = long(centerY - r_size * cos((72 * i) * M_PI / 180));
	}
	a = point[4].y - point[0].y;
	b = point[0].x - point[4].x;
	c = point[2].y - point[8].y;
	d = point[8].x - point[2].x;
	e = a*point[0].x + b*point[0].y;
	f = c*point[2].x + d*point[2].y;

	k = a*d - b * c;

	s_x = (e*d - b*f) / k;
	s_y = (a*f - e*c) / k;

	s_r2 = long(sqrt(pow(s_x - centerX, 2) + pow(s_y - centerY, 2)));

	for (i = 0; i < 5; i++)
	{
		point[2 * i + 1].x = long(centerX + s_r2 * sin((72 * i + 32) * M_PI / 180));
		point[2 * i + 1].y = long(centerY - s_r2 * cos((72 * i + 32) * M_PI / 180));
	}
	

}
