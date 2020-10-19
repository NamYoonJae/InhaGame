// Win32ProjectMenu.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32ProjectMenu.h"
#include <cmath>
#define _USE_MATH_DEFINES
#include<math.h>
#include <commdlg.h>
#include <stdio.h>

#define MAX_LOADSTRING 100
static int flag = 0;
void OutFromFile(TCHAR filename[], HWND hwnd);
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
    LoadStringW(hInstance, IDC_WIN32PROJECTMENU, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECTMENU));

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



void OutFromFile(TCHAR filename[], HWND hwnd)
{
	FILE *fPtr;
	HDC hdc;
	int line;
	TCHAR buffer[500];
	line = 0;
	hdc = GetDC(hwnd);
#ifdef _UNICODE
	_tfopen_s(&fPtr, filename, _T("r, ccs = UNICODE"));
#else
	_topen_s(&fPtr, filename, _T("r"));
#endif
	while (_fgetts(buffer, 100, fPtr) != NULL)
	{
		if (buffer[_tcslen(buffer) - 1] == _T('n'))
			buffer[_tcslen(buffer) - 1] = NULL;
		TextOut(hdc, 0, line * 20, buffer, _tcslen(buffer));
		line++;
	}
	fclose(fPtr);
	ReleaseDC(hwnd, hdc);

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECTMENU));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32PROJECTMENU);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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

	OPENFILENAME ofn;
	TCHAR str[100], lpstrFile[100] = _T("");
	TCHAR filter[] = _T("Every File(*.*) \0*.*\0TectFile\0*.txt;*.doc\0");
	OPENFILENAME sfn;
	
	CHOOSECOLOR COLOR;
	static COLORREF tmp[16], color;
	HBRUSH hBrush, OldBrush;
	int i;

	static HMENU hMenu, hSubMenu;




	int mx, my;
	POINT point[10];
	long m_centerX = 200;
	long m_centerY = 200;
	long m_rSize = 50;

	long a, b, c, d, e, f, k, s_x, s_y, s_r2;


	for (i = 0; i <5; i++) 
	{

		point[2 * i].x = long(m_centerX + m_rSize * sin((72 * i) * M_PI / 180));
		point[2 * i].y = long(m_centerY - m_rSize * cos((72 * i) * M_PI / 180));
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

	s_r2 = long(sqrt(pow(s_x - m_centerX, 2) + pow(s_y - m_centerY, 2)));

	for (i = 0; i < 5; i++) 
	{
		point[2 * i + 1].x = long(m_centerX + s_r2 * sin((72 * i + 32) * M_PI / 180));
		point[2 * i + 1].y = long(m_centerY - s_r2 * cos((72 * i + 32) * M_PI / 180));
	}

    switch (message)
    {
	case WM_CREATE:
		hMenu = GetMenu(hWnd);
		hSubMenu = GetSubMenu(hMenu, 2);
		EnableMenuItem(hSubMenu, ID_DRAW_CIRCLE, MF_GRAYED);
		EnableMenuItem(hSubMenu, ID_DRAW_RECTANGLE, MF_GRAYED);
		EnableMenuItem(hSubMenu, ID_DRAW_STAR, MF_GRAYED);
		EnableMenuItem(hSubMenu, ID_FILEOPEN, MF_GRAYED);
		EnableMenuItem(hSubMenu, ID_FILESAVE, MF_GRAYED);

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
			case ID_DRAW_CIRCLE:
				//MessageBox(NULL, L"CIRCLE", L"Draw", MB_OK);
				flag = 1;
				break;
			case ID_DRAW_RECTANGLE:
				//MessageBox(NULL, L"RECTANGLE", L"Draw", MB_OK);
				flag = 2;
				break;
			case ID_DRAW_STAR:
				//MessageBox(NULL, L"STAR", L"Draw", MB_OK);
				flag = 3;
				break;

            case IDM_EXIT:
                DestroyWindow(hWnd);

			case ID_FILEOPEN:
				memset(&ofn, 0, sizeof(OPENFILENAME));
				ofn.lStructSize = sizeof(OPENFILENAME);
				ofn.hwndOwner = hWnd;
				ofn.lpstrFilter = filter;
				ofn.lpstrFile = lpstrFile;
				ofn.nMaxFile = 100;
				ofn.lpstrInitialDir = _T(".");
				if (GetOpenFileName(&ofn) != 0)
				{
					//_stprintf_s(str, _T("%s 파일을 열겠습니까?"), ofn.lpstrFile);
					//MessageBox(hWnd, str, _T("열기 선택"), MB_OK);
					OutFromFile(ofn.lpstrFile, hWnd);
				}

                break;

				
			case ID_FILESAVE:
				memset(&sfn, 0, sizeof(OPENFILENAME));
				sfn.lStructSize = sizeof(OPENFILENAME);
				sfn.hwndOwner = hWnd;
				sfn.lpstrFilter = filter;
				sfn.lpstrFile = lpstrFile;
				sfn.nMaxFile = 256;
				sfn.lpstrInitialDir = _T(".");
				if (GetSaveFileName(&sfn) != 0)
				{
					_stprintf_s(str, _T("%s 파일로 저장하겠습니까?"), sfn.lpstrFile);
					MessageBox(hWnd, str, _T("저장하기 선택"), MB_OK);
				}
			case ID_COLORDLG:
				for (i = 0; i < 16; i++)
					tmp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
				memset(&COLOR, 0, sizeof(CHOOSECOLOR));
				COLOR.lStructSize = sizeof(CHOOSECOLOR);
				COLOR.hwndOwner = hWnd;
				COLOR.lpCustColors = tmp;
				COLOR.Flags = CC_FULLOPEN;
				if (ChooseColor(&COLOR) != 0) 
				{
					color = COLOR.rgbResult;
					InvalidateRgn(hWnd, NULL, TRUE);
				}
				break;

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
		hBrush = CreateSolidBrush(color);
		OldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		Ellipse(hdc, 10, 10, 200, 200);
		SelectObject(hdc, OldBrush);
		DeleteObject(hBrush);

		switch (flag)
		{
		case 1:
			Ellipse(hdc, 100, 100, 200, 200);
			break;

		case 2:
			Rectangle(hdc, 100, 100,200,200);
			break;

		case 3:
			Polygon(hdc, point, 10);
			
			break;

		default:
			break;
		}
		EndPaint(hWnd, &ps);
		break;
	}

	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		InvalidateRect(hWnd, NULL, TRUE);
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
