// Win32Collision.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32Collision.h"
#include <math.h>

#define MAX_LOADSTRING 100
#define BSIZE 40

double LengthPts(int x1, int y1, int x2, int y2) 
{
	return (sqrt((float)((x2 - x1)*(x2 - x1) + (y2 - y1)* (y2 - y1))));
}

BOOL InCircle(int x, int y, int mx, int my) 
{
	if (LengthPts(x, y, mx, my) < BSIZE) return TRUE;
	else return FALSE;
}

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
	static int x, y;
	//static RECT rectView;
	static BOOL Selection;
	int mx, my;

	

    switch (message)
    {
	case WM_CREATE:
		//�����찡 ó�� ������� WM_CREAT�� �߻�
		//GetClientRect(hWnd, &rectView);	//�������� ũ�⸦ ����
		//x = 20; y = 20;	//��ǥ���� ����
		x = 50; y = 50;
		Selection = FALSE;
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
			//Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
			if (Selection)
				Rectangle(hdc, x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);
			Ellipse(hdc, x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);

            EndPaint(hWnd, &ps);
        }
        break;

	case WM_KEYDOWN:
		//kEYDOWN �߻���
		//if (wParam == VK_RIGHT) SetTimer(hWnd, 1, 70, NULL); //������Ű�� ��� Ÿ�̸Ӹ� �����Ѵ� 1�� Ÿ�̸ӿ� 0.07�� ����
		//0.07�ʸ��� Ÿ�̸Ӹ޼����� �߻��ϰ� WinProc���� �� �޼����� ó���Ѵ�
		break;

	case WM_TIMER:
		//x += 40;	//x ��ǥ 40 �� ����
		//if (x + 20 > rectView.right)x -= 40; //x��ǥ�� ������ ������ ��迡 �Ѿ���ϸ� ������ 40�� ���� ������ ���ο� �ӹ������Ѵ�.
		//InvalidateRgn(hWnd, NULL, TRUE);//InvalidateRgn()�Լ��� ���� WM_PAINT �޼����� �߻��ϹǷ� �ٲ� ��ǥ�� ���� �ٽ� �׸���
		break;

	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);	//���콺 ���� Ŭ���� �ش� x ��ǥ���� mx�� ����
		my = HIWORD(lParam);	//���콺 ���� Ŭ���� �ش� y ��ǥ���� my�� ����
		if (InCircle(x, y, mx, my)) Selection = TRUE;
		InvalidateRgn(hWnd, NULL, TRUE);
		break;

	case WM_LBUTTONUP:
		Selection = FALSE;
		InvalidateRgn(hWnd, NULL, TRUE);
		break;

	case WM_MOUSEMOVE:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		if (Selection) 
		{
			x = mx;
			y = my;
			InvalidateRgn(hWnd, NULL, TRUE);
		}
		break;


    case WM_DESTROY:
		//KillTimer(hWnd, 1);//1�� Ÿ�̸��� ������ ���ߵ��� �Ѵ�
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
