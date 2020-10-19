// RotateTest.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "RotateTest.h"
#include <windows.h>   
#include <math.h>  
#include <iostream>

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#define MAX_LOADSTRING 100
#define PI          3.141592654  

using namespace std;

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.



HWND hWndMain;
HDC hdc;
HDC hOffScreenDC;
HBITMAP hOffScreenBitmap;
HBITMAP hMemBitmap;


void OnTimer();
void RotateBlt(HDC hdc, HDC hOffScreen, int dest_x, int dest_y, int dest_width, int dest_height, HBITMAP hBit, int source_x, int source_y, DWORD dFlag, float angle, COLORREF bkColor);
HBITMAP GetRotatedBitmap(HDC hdc, HBITMAP hBitmap, int source_x, int source_y, int dest_width, int dest_height, float angle, COLORREF bkColor);

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
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

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ROTATETEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ROTATETEST));

    MSG msg;

    // �⺻ �޽��� �����Դϴ�.
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
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ROTATETEST));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ROTATETEST);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

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
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		hWndMain = hWnd;
		hdc = GetDC(hWnd);
		hOffScreenDC = CreateCompatibleDC(hdc);
		hOffScreenBitmap = CreateCompatibleBitmap(hdc, 800, 600);

		SelectObject(hOffScreenDC, hOffScreenBitmap);
		PatBlt(hOffScreenDC, 0, 0, 800, 600, WHITENESS);

		hMemBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL),
			TEXT("��ũ4.bmp"),
			IMAGE_BITMAP,
			0,
			0,
			LR_DEFAULTSIZE | LR_LOADFROMFILE);

		SetTimer(hWnd, 1, 20, NULL);
		break;

	case WM_TIMER:
		OnTimer();
		break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �޴� ������ ���� �м��մϴ�.
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
            // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.
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

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
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

void OnTimer() 
{
	
	static FLOAT angle = 0.0f;
	static BOOL bRotate = FALSE;

	if (GetKeyState(VK_LBUTTON) & 0x8000) { bRotate = TRUE; }

	if (bRotate)
	{
		angle += 5.0f;
		bRotate = FALSE;
		/*
		if (angle >= 360.0f)
		{
			bRotate = FALSE;
			angle = 0.0f;
		}
		*/

	}

	PatBlt(hOffScreenDC, 0, 0, 800, 600, WHITENESS);

	
	RECT Rt;
	GetClientRect(hWndMain, &Rt);
	
	RotateBlt(hdc, hOffScreenDC, 50, 50, 500, 500,
		hMemBitmap, 0, 0, SRCAND, angle, RGB(255, 0, 255));
	
	/*
	RotateBlt(hdc, hOffScreenDC, Rt.left, Rt.top, Rt.right, Rt.bottom,
		hMemBitmap, 60, 0, SRCPAINT, angle, RGB(0, 0, 0));
	*/

	BitBlt(hdc, 0, 0, 800, 600, hOffScreenDC, 0, 0, SRCCOPY);
	
};

void RotateBlt(HDC hdc, HDC hOffScreen, int dest_x, int dest_y, int dest_width, int dest_height,
	HBITMAP hBit, int source_x, int source_y, DWORD dFlag, float angle, COLORREF bkColor)
{
	static HDC hTempMemDC;
	HBITMAP hTempBitmap, hOldBitmap;

	if (!hTempMemDC) hTempMemDC = CreateCompatibleDC(hdc);

	hTempBitmap = GetRotatedBitmap(hdc, hBit, source_x, source_y, dest_width, dest_height, angle, bkColor);	

	hOldBitmap = (HBITMAP)SelectObject(hTempMemDC, hTempBitmap);

	BitBlt(hOffScreen, dest_x/* - dest_width/2*/, dest_y/* - dest_height/2*/, dest_width, dest_height,
		hTempMemDC, 0, 0, dFlag);


	SelectObject(hTempMemDC, hOldBitmap);
	DeleteObject(hTempBitmap);
}

HBITMAP GetRotatedBitmap(HDC hdc, HBITMAP hBitmap, int source_x, int source_y, int dest_width, int dest_height, float angle, COLORREF bkColor) 
{
	HDC sourceDC = CreateCompatibleDC(hdc);                                      // ȸ���� ��Ʈ�� ������ ������ DC   
	HDC destDC = CreateCompatibleDC(hdc);                                      // ȸ���� ��Ʈ���� ��¹��� DC   
	HBITMAP hbmResult = CreateCompatibleBitmap(hdc, dest_width, dest_height);       // ȸ���� ��Ʈ���� ��¹��� �޸𸮺�Ʈ�� �ڵ�   

	HBITMAP hbmOldSource = (HBITMAP)SelectObject(sourceDC, hBitmap);                   // ȸ���� ��Ʈ�� ������ DC�� ����   
	HBITMAP hbmOldDest = (HBITMAP)SelectObject(destDC, hbmResult);                   // ȸ���� ��Ʈ���� ��¹��� DC��, ȸ���� ��Ʈ���� ��¹��� �޸𸮺�Ʈ�� ����   

	HBRUSH hbrBack = CreateSolidBrush(bkColor);                                  // ȸ������ ����, ���鿵���� ĥ�� �귯���ڵ� ����   
	HBRUSH hbrOld = (HBRUSH)SelectObject(destDC, hbrBack);                      // �귯���ڵ� ����   
	PatBlt(destDC, 0, 0, dest_width, dest_height, PATCOPY);                           // ���õ� �귯�÷�, ȸ���� ��Ʈ���� ��¹��� DC��, �̸� ������ ä�� ����   
	DeleteObject(SelectObject(destDC, hbrOld));                                     // �귯�� ����   

	angle = (float)(angle * PI / 180);                                      // ȸ���� ����(360�й�)��, ���ȴ����� ������ ����   
	float cosine = (float)cos(angle);                                              // ȸ���̵���ȯ ��Ŀ� �� cos��Ÿ ���� ����          
	float sine = (float)sin(angle);                                              // ȸ���̵���ȯ ��Ŀ� �� sin��Ÿ ���� ����   

	SetGraphicsMode(destDC, GM_ADVANCED);                                               // ������ ��ǥ���� ȸ���� ���Ͽ�, �׷��ȸ�带 Ȯ����� �����մϴ�.(�䱸����:��98,NT�̻�)   
																				// (���� ���α׷��Ӹ� ���� ���ʼ��а� ���� Page(196) ����.)   

	XFORM xform;                                                                        // �������� ǥ���ϴ� 3��3���� ��� ����   
	xform.eM11 = cosine;                                                                // 1�� 1�� ���� ���� (ȸ������)   
	xform.eM12 = sine;                                                                  // 1�� 2�� ���� ���� (ȸ������)   
	xform.eM21 = -sine;                                                                 // 2�� 1�� ���� ���� (ȸ������)   
	xform.eM22 = cosine;                                                                // 2�� 2�� ���� ���� (ȸ������)   
	xform.eDx = (FLOAT)dest_width / 2.0f;                                               // 3�� 1�� ���� ���� (X�� �̵� ����)   
	xform.eDy = (FLOAT)dest_height / 2.0f;                                              // 3�� 2�� ���� ���� (Y�� �̵� ����)   

	SetWorldTransform(destDC, &xform);

	// ȸ���� �޸�DC��, ȸ���� �̹����� ���   
	//cout << "dest_width: " << dest_width << endl;
	//cout << "dest_height: " << dest_height << endl;

	BitBlt(destDC, -(dest_width / 20), -(dest_height / 20), dest_width/4, dest_height/4, sourceDC, source_x, source_y, SRCCOPY);

	// ���� �ڿ� ����   

	SelectObject(sourceDC, hbmOldSource);
	SelectObject(destDC, hbmOldDest);
	DeleteObject(sourceDC);
	DeleteObject(destDC);

	// ȸ���� ��Ʈ�� �ڵ� ����   

	return hbmResult;
}