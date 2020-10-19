// Win32GalsPanic.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32GalsPanic.h"
#include "galsPanic.h"
#include <vector>
#pragma comment(lib, "msimg32.lib")

#define MAX_LOADSTRING 100

using namespace std;

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
    LoadStringW(hInstance, IDC_WIN32GALSPANIC, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32GALSPANIC));

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

enum
{
	enum_right = 1,
	enum_left = 2,
	enum_up = 3,
	enum_down = 4,

};
vector <POINT> vPointList;
vector <POINT> vLine;

HBITMAP hDoubleBufferImage;
HBITMAP hDoubleBufferImage2;
HBITMAP hDoubleBufferImage3;
HBITMAP backgroundImage;
RECT rectView;
BITMAP bitBack;

static Charactor newCharactor(400, 400);

void CreateBitmap();
void DoubleBuffering(HDC hdc);
void DeleteBitmap();
void DrawLine(HDC hdc);

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32GALSPANIC));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32GALSPANIC);
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
      CW_USEDEFAULT, 0, 900, 1000, nullptr, nullptr, hInstance, nullptr);

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
    switch (message)
    {
	case WM_CREATE:

		CreateBitmap();
		GetClientRect(hWnd, &rectView);
		SetTimer(hWnd, 1, 70, NULL);
		AllocConsole();
		freopen("CONOUT$", "wt", stdout);

		vPointList.push_back({ 400,400 });
		vPointList.push_back({ 500,400 });
		vPointList.push_back({ 500,500 });
		vPointList.push_back({ 400,500 }); 
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
            //HDC hdc = BeginPaint(hWnd, &ps);
			DoubleBuffering(hdc);
			
			if (vLine.size() != 0) 
			{
				DrawLine(hdc);
			}
			
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_TIMER:
		InvalidateRect(hWnd, NULL, FALSE);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RIGHT:
			newCharactor.Move(hdc, enum_right, hWnd);
			break;

		case VK_LEFT:
			newCharactor.Move(hdc, enum_left, hWnd);
			break;

		case VK_UP:
			newCharactor.Move(hdc, enum_up, hWnd);
			break;

		case VK_DOWN:
			newCharactor.Move(hdc, enum_down, hWnd);
			break;
		default:
			break;
		}
		break;

	case WM_KEYUP:
		POINT tempPoint;
		tempPoint.x = newCharactor.GetCenterX();
		tempPoint.y = newCharactor.GetCenterY();
		vLine.push_back(tempPoint);
		break;

    case WM_DESTROY:
		DeleteBitmap();
        PostQuitMessage(0);
		FreeConsole();
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


void CreateBitmap()
{
	backgroundImage = (HBITMAP)LoadImage(NULL, TEXT("¼öÁö.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	GetObject(backgroundImage, sizeof(BITMAP), &bitBack);
}

void DoubleBuffering(HDC hdc)
{
	HDC hMemDC;
	HDC hMemDC2;
	HDC hMemDC3;

	HBITMAP hOldBitmap;
	HBITMAP hOldBitmap2;
	HBITMAP hOldBitmap3;
	int bx, by;

	hMemDC = CreateCompatibleDC(hdc);

	if (hDoubleBufferImage == NULL)
		hDoubleBufferImage = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hDoubleBufferImage);


	hMemDC2 = CreateCompatibleDC(hMemDC);
	if (hDoubleBufferImage2 == NULL)
		hDoubleBufferImage2 = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);

	hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hDoubleBufferImage2);
	{
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, backgroundImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;

		TransparentBlt(hMemDC, 0, 0, bx, by, hMemDC2, 0, 0, bx, by, RGB(255, 0, 255));
		SelectObject(hMemDC2, hOldBitmap2);
	}

	hMemDC3 = CreateCompatibleDC(hMemDC);

	if (hDoubleBufferImage3 == NULL)
		hDoubleBufferImage3 = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
	hOldBitmap3 = (HBITMAP)SelectObject(hMemDC3, hDoubleBufferImage3);

	{
		hOldBitmap3 = (HBITMAP)SelectObject(hMemDC3, hDoubleBufferImage3);

		HBRUSH Brush, oBrush;
		Brush = CreateSolidBrush(RGB(0, 100, 255));
		oBrush = (HBRUSH)SelectObject(hMemDC3, Brush);
		Rectangle(hMemDC3, 0, 0, rectView.right, rectView.bottom);

		SelectObject(hMemDC3, oBrush);

		Brush = CreateSolidBrush(RGB(255, 0, 255));
		oBrush = (HBRUSH)SelectObject(hMemDC3, Brush);

		Polygon(hMemDC3, &vPointList[0], vPointList.size());

		TransparentBlt(hMemDC, 0, 0, rectView.right, rectView.bottom,
			hMemDC3, 0, 0, rectView.right, rectView.bottom, RGB(255, 0, 255));

		DeleteObject(Brush);
	}

	BitBlt(hdc, 0, 0, rectView.right, rectView.bottom, hMemDC, 0, 0, SRCCOPY);
	SelectObject(hMemDC, hOldBitmap);

	DeleteDC(hMemDC3);
	DeleteDC(hMemDC2);
	DeleteDC(hMemDC);

	newCharactor.Draw(hdc);
}

void DeleteBitmap()
{
	DeleteObject(backgroundImage);
	DeleteObject(hDoubleBufferImage);
	DeleteObject(hDoubleBufferImage2);
	DeleteObject(hDoubleBufferImage3);
}

void DrawLine(HDC hdc)
{
	int i = 0;
	for (i = 0; i < vLine.size()-1; i++) 
	{
		MoveToEx(hdc, vLine[i].x, vLine[i].y, NULL);
		LineTo(hdc, vLine[i + 1].x, vLine[i + 1].y);
	}
}


