// API3D.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "API3D.h"
#include "cMainGame.h"

#define MAX_LOADSTRING 100

// >>:
HWND g_hWnd;
cMainGame * g_pMainGame;
#define TIMER_ID 123
// <<:


// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.
RECT rt;

float changeAngle;
float x;
float y;
float z;
void Draw(HDC hdc);


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
    LoadStringW(hInstance, IDC_API3D, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_API3D));

    MSG msg;

	g_pMainGame = new cMainGame;
	g_pMainGame->SetUp();
	SetTimer(g_hWnd, TIMER_ID, 10, NULL);

    // �⺻ �޽��� �����Դϴ�.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

	KillTimer(g_hWnd, TIMER_ID);
	delete g_pMainGame;

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_API3D));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_API3D);
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

   // >>:
   g_hWnd = hWnd;
   //<<:

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
	if (g_pMainGame) 
	{
		g_pMainGame->WndProc(hWnd, message, wParam, lParam);
	}

    switch (message)
    {
	case WM_TIMER:
		if (g_pMainGame)
			g_pMainGame->Update();
		InvalidateRect(hWnd, NULL, FALSE);
		break;

	case WM_CREATE:
		{
		GetClientRect(hWnd, &rt);
		changeAngle = 0;
		x = y = z = 0;
		}
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

			//>>:
			if (g_pMainGame)
				g_pMainGame->Render(hdc);
			//<<:


			//Draw(hdc);


    		
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


void Draw(HDC hdc)
{
	cMatrix matrix(4);

	
	
	matrix = matrix.Pipeline(rt);
	matrix.Print();
	
	vector<int> dir = { -1, 1 };
	vector<cVector3> rectangle;
	vector<cVector3> polygon;
	vector<cVector3> coord;

	vector<cVector3> GridColumn;
	vector<cVector3> GridRow;
	
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				rectangle.emplace_back(dir[i], dir[j], dir[k]);
			}	
		}	
	}

	
	polygon.emplace_back(1, 5, 3);
	polygon.emplace_back(5, 7, 3);
	polygon.emplace_back(1, 0, 2);
	polygon.emplace_back(1, 3, 2);
	polygon.emplace_back(0, 4, 2);
	polygon.emplace_back(4, 6, 2);
	polygon.emplace_back(4, 5, 7);
	polygon.emplace_back(4, 6, 7);
	polygon.emplace_back(1, 4, 5);
	polygon.emplace_back(1, 4, 0);
	polygon.emplace_back(3, 7, 6);
	polygon.emplace_back(3, 2, 6);


	for(cVector3 c_vector3:rectangle)
	{
		coord.push_back(cVector3::Transformcoord(c_vector3, matrix));
	}

	for (cVector3 poly : polygon)
	{
		MoveToEx(hdc, coord[poly.get_x()].get_x(), coord[poly.get_x()].get_y(), NULL);
		LineTo(hdc, coord[poly.get_y()].get_x(), coord[poly.get_y()].get_y());
		LineTo(hdc, coord[poly.get_z()].get_x(), coord[poly.get_z()].get_y());
		LineTo(hdc, coord[poly.get_x()].get_x(), coord[poly.get_x()].get_y());
	}

	for (int i = -9; i < 10; i += 2)
	{
		GridColumn.emplace_back(i, 0, 9);
		GridColumn.emplace_back(i, 0, -9);
	}

	for (int i = -9; i < 10; i += 2)
	{
		GridRow.emplace_back(9, 0, i);
		GridRow.emplace_back(-9, 0, i);
	}

	for (int i = 0; i < GridColumn.size(); i++)
	{
		GridColumn[i] = cVector3::Transformcoord(GridColumn[i], matrix);
	}

	for (int i = 0; i < GridRow.size(); i++)
	{
		GridRow[i] = cVector3::Transformcoord(GridRow[i], matrix);
	}

	for (int i = 0; i < 20; i += 2)
	{
		MoveToEx(hdc, GridColumn[i].get_x(), GridColumn[i].get_y(), NULL);
		LineTo(hdc, GridColumn[i + 1].get_x(), GridColumn[i + 1].get_y());
	}
	for (int i = 0; i < 20; i += 2)
	{
		MoveToEx(hdc, GridRow[i].get_x(), GridRow[i].get_y(), NULL);
		LineTo(hdc, GridRow[i + 1].get_x(), GridRow[i + 1].get_y());
	}
	
}