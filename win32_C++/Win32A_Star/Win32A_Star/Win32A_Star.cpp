// Win32A_Star.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Win32A_Star.h"
#include "A_Star_Class.h"
#include <iostream>
#include <vector>

#define MAX_LOADSTRING 100

using namespace std;

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.


static vector <AStar*> vAStarList;
void CreateMap();


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
    LoadStringW(hInstance, IDC_WIN32A_STAR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32A_STAR));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32A_STAR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32A_STAR);
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

	case WM_LBUTTONDOWN:
		{
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		//��� ��ü�� ���������� �Ÿ� ���� ���� ���� �Ÿ��� ����



		}
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			HBRUSH Brush, oBrush;
            // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.
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
	//������ centerX �� centerY �� ��� Ȧ���̸� ���� ����
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
	// ����
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