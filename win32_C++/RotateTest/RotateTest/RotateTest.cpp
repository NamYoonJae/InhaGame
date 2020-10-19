// RotateTest.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
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

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.



HWND hWndMain;
HDC hdc;
HDC hOffScreenDC;
HBITMAP hOffScreenBitmap;
HBITMAP hMemBitmap;


void OnTimer();
void RotateBlt(HDC hdc, HDC hOffScreen, int dest_x, int dest_y, int dest_width, int dest_height, HBITMAP hBit, int source_x, int source_y, DWORD dFlag, float angle, COLORREF bkColor);
HBITMAP GetRotatedBitmap(HDC hdc, HBITMAP hBitmap, int source_x, int source_y, int dest_width, int dest_height, float angle, COLORREF bkColor);

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
    LoadStringW(hInstance, IDC_ROTATETEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ROTATETEST));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ROTATETEST));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ROTATETEST);
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
			TEXT("탱크4.bmp"),
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
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.
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
	HDC sourceDC = CreateCompatibleDC(hdc);                                      // 회전할 비트맵 원본을 선택할 DC   
	HDC destDC = CreateCompatibleDC(hdc);                                      // 회전할 비트맵을 출력받을 DC   
	HBITMAP hbmResult = CreateCompatibleBitmap(hdc, dest_width, dest_height);       // 회전할 비트맵을 출력받을 메모리비트맵 핸들   

	HBITMAP hbmOldSource = (HBITMAP)SelectObject(sourceDC, hBitmap);                   // 회전할 비트맵 원본을 DC에 선택   
	HBITMAP hbmOldDest = (HBITMAP)SelectObject(destDC, hbmResult);                   // 회전할 비트맵을 출력받을 DC에, 회전할 비트맵을 출력받을 메모리비트맵 선택   

	HBRUSH hbrBack = CreateSolidBrush(bkColor);                                  // 회전으로 인한, 공백영역을 칠할 브러시핸들 생성   
	HBRUSH hbrOld = (HBRUSH)SelectObject(destDC, hbrBack);                      // 브러시핸들 선택   
	PatBlt(destDC, 0, 0, dest_width, dest_height, PATCOPY);                           // 선택된 브러시로, 회전할 비트맵을 출력받을 DC에, 미리 색상을 채워 지움   
	DeleteObject(SelectObject(destDC, hbrOld));                                     // 브러시 해제   

	angle = (float)(angle * PI / 180);                                      // 회전할 각도(360분법)를, 라디안단위의 각도로 변경   
	float cosine = (float)cos(angle);                                              // 회전이동변환 행렬에 들어갈 cos세타 값을 구함          
	float sine = (float)sin(angle);                                              // 회전이동변환 행렬에 들어갈 sin세타 값을 구함   

	SetGraphicsMode(destDC, GM_ADVANCED);                                               // 윈도우 좌표계의 회전을 위하여, 그래픽모드를 확장모드로 변경합니다.(요구사항:윈98,NT이상)   
																				// (게임 프로그래머를 위한 기초수학과 물리 Page(196) 참조.)   

	XFORM xform;                                                                        // 방정식을 표현하는 3행3열의 행렬 선언   
	xform.eM11 = cosine;                                                                // 1행 1열 성분 설정 (회전성분)   
	xform.eM12 = sine;                                                                  // 1행 2열 성분 설정 (회전성분)   
	xform.eM21 = -sine;                                                                 // 2행 1열 성분 설정 (회전성분)   
	xform.eM22 = cosine;                                                                // 2행 2열 성분 설정 (회전성분)   
	xform.eDx = (FLOAT)dest_width / 2.0f;                                               // 3행 1열 성분 설정 (X축 이동 성분)   
	xform.eDy = (FLOAT)dest_height / 2.0f;                                              // 3행 2열 성분 설정 (Y축 이동 성분)   

	SetWorldTransform(destDC, &xform);

	// 회전된 메모리DC에, 회전할 이미지를 출력   
	//cout << "dest_width: " << dest_width << endl;
	//cout << "dest_height: " << dest_height << endl;

	BitBlt(destDC, -(dest_width / 20), -(dest_height / 20), dest_width/4, dest_height/4, sourceDC, source_x, source_y, SRCCOPY);

	// 사용된 자원 해제   

	SelectObject(sourceDC, hbmOldSource);
	SelectObject(destDC, hbmOldDest);
	DeleteObject(sourceDC);
	DeleteObject(destDC);

	// 회전된 비트맵 핸들 리턴   

	return hbmResult;
}