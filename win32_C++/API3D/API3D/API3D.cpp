// API3D.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
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


// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
RECT rt;

float changeAngle;
float x;
float y;
float z;
void Draw(HDC hdc);


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
    LoadStringW(hInstance, IDC_API3D, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_API3D));

    MSG msg;

	g_pMainGame = new cMainGame;
	g_pMainGame->SetUp();
	SetTimer(g_hWnd, TIMER_ID, 10, NULL);

    // 기본 메시지 루프입니다.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_API3D));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_API3D);
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

   // >>:
   g_hWnd = hWnd;
   //<<:

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