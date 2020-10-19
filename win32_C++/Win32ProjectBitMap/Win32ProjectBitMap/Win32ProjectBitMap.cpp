// Win32ProjectBitMap.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <windows.h>
#include "Win32ProjectBitMap.h"
#pragma comment(lib, "msimg32.lib")
#include <TCHAR.h>
#include "Resource.h"


#define MAX_LOADSTRING 100

// Global Variables:
//HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// >> :
HBITMAP hBackImage;
BITMAP bitBack;

HBITMAP hTransparentImage;
BITMAP bitTransparent;


HBITMAP hAniImage;
BITMAP bitAni;

BOOL CALLBACK Dlg6_1Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE hInst;


#define IDC_CHILD_BTN 100
#define IDC_CHILD_BTN2 101
#define IDC_CHILD_BTN3 102
#define IDC_CHILD_BTN4 103

HWND childHwnd[3];
LRESULT CALLBACK ChildWndProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChildWndProc2(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

const int Sprite_Size_X = 57;
const int Sprite_Size_Y = 52;
int Run_Frame_Max = 0;
int Run_Frame_Min = 0;
int cur_Frame = Run_Frame_Min;

RECT rectView;
void DrawRectText(HDC hdc);

HBITMAP hDoubleBuffurImage;
void DrawBitmapDoubleBuffering(HWND hWnd, HDC hdc);



void CreateBitmap();
void DrawBitmap(HWND hWnd, HDC hdc);
void DleleteBitmap();
void UpdateFrame(HWND hWnd);
VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);


// >> :
VOID CALLBACK KeyStateProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

TCHAR sKeyState[128];



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
    LoadStringW(hInstance, IDC_WIN32PROJECTBITMAP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);



    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECTBITMAP));

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
	//wcex.lpfnWndProc = FrameWndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECTBITMAP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32PROJECTBITMAP);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWndProc;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child2");
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWndProc2;
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
    switch (message)
    {
	case WM_CREATE:
		CreateBitmap();
		SetTimer(hWnd, 123, 100, NULL);
		SetTimer(hWnd, 123, 100, AniProc);
		//GetClientRect(hWnd, &rectView);

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
			rectView.right/2 , 0, rectView.right, rectView.bottom,
			hWnd, NULL, hInst, NULL);
		

		break;

		/*
	case WM_TIMER:
		UpdateFrame(hWnd);
		InvalidateRgn(hWnd, NULL, false);
		break;
		*/
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
			//DrawBitmap(hWnd, hdc);

			DrawBitmapDoubleBuffering(hWnd, hdc);
			DrawRectText(hdc);

            EndPaint(hWnd, &ps);
        }
        break;


		DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dlg6_1Proc);

		break;

    case WM_DESTROY:
		DleleteBitmap();
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


int yPos = 0;
void DrawRectText(HDC hdc)
{
	TCHAR strText[] = _T("텍스트 출력");
	TextOut(hdc, 10, yPos, strText, _tcslen(strText));
	TextOut(hdc, 100, 100, sKeyState, _tcslen(sKeyState));
	//yPos += 5;
	//if (yPos > rectView.bottom) yPos = 0;
}

void DrawBitmapDoubleBuffering(HWND hWnd, HDC hdc)
{
	static HDC hMemDC;
	HBITMAP hOldBitmap;
	int bx, by;

	HDC hMemDC2;
	HBITMAP hOldBitmap2;

	hMemDC = CreateCompatibleDC(hdc);
	if (hDoubleBuffurImage == NULL)
		hDoubleBuffurImage = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hDoubleBuffurImage);

	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hBackImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;

		BitBlt(hMemDC, 0, 0, bx, by, hMemDC2, 0, 0, SRCCOPY);

		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}

	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hTransparentImage);
		bx = bitTransparent.bmWidth;
		by = bitTransparent.bmHeight;

		TransparentBlt(hMemDC, 0, 0, bx/2, by/2, hMemDC2, 0, 0, bx, by, RGB(255, 0, 255));

		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}

	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hAniImage);
		bx = bitAni.bmWidth / 16;
		by = bitAni.bmHeight / 2;

		int xStart = cur_Frame * bx;
		int yStart = 0;

		TransparentBlt(hMemDC, 200, 100, bx*2, by*2, hMemDC2, xStart, yStart, bx, by, RGB(255, 0, 255));


		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}
	BitBlt(hdc, 0, 0, rectView.right/2, rectView.bottom/2, hMemDC, 0, 0, SRCCOPY);
	SelectObject(hMemDC, hOldBitmap);

	//DeleteDC(hMemDC);
}

void CreateBitmap()
{
	
	{
		hBackImage = (HBITMAP)LoadImage(NULL, TEXT("수지.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		GetObject(hBackImage, sizeof(BITMAP), &bitBack);
	}

	/*
		hTransparentImage = (HBITMAP)LoadImage(NULL, TEXT("sigong.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		GetObject(hTransparentImage, sizeof(BITMAP), &bitTransparent);
	}
	*/
	{
		hAniImage = (HBITMAP)LoadImage(NULL, TEXT("zero_run.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		GetObject(hAniImage, sizeof(BITMAP), &bitAni);
		Run_Frame_Max = bitAni.bmWidth / Sprite_Size_X - 1;
		Run_Frame_Min = 2;
		cur_Frame = Run_Frame_Min;
	}
}

void DrawBitmap(HWND hWnd, HDC hdc)
{
	HDC hMemDC;
	HBITMAP hOldBitmap;
	int bx, by;
	
	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBackImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;

		BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);

		SelectObject(hMemDC, hOldBitmap);
	}
	
	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hTransparentImage);
		bx = bitTransparent.bmWidth;
		by = bitTransparent.bmHeight;

		BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);
		TransparentBlt(hdc, 200, 100, bx, by, hMemDC, 0, 0, bx, by, RGB(255, 0, 255));

		SelectObject(hMemDC, hOldBitmap);
		
	}
	
	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hAniImage);
		bx = bitAni.bmWidth / 16;
		by = bitAni.bmHeight / 2;

		int xStart = cur_Frame * bx;
		int yStart = 0;


		TransparentBlt(hdc, 200, 100, bx, by, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255));

		//BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY); //그려진 이미지 전체를 넘겨준다



		SelectObject(hMemDC, hOldBitmap);
	}
	DeleteDC(hMemDC);
}

void DleleteBitmap()
{
	DeleteObject(hBackImage);
	DeleteObject(hTransparentImage);
}

void UpdateFrame(HWND hWnd)
{
	cur_Frame++;
	if (cur_Frame > Run_Frame_Max)
		cur_Frame = Run_Frame_Min;
	

}

VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	UpdateFrame(hWnd);
	{
		yPos += 5;
		if (yPos > rectView.bottom) yPos = 0;
	}
	InvalidateRgn(hWnd, NULL, false);


}

VOID CALLBACK KeyStateProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{

	if (GetKeyState('A') & 0x8000)
	{
		wsprintf(sKeyState, TEXT("%s"), _T("A-Key"));
	}
	else if (GetKeyState('S') & 0x8000)
	{
		wsprintf(sKeyState, TEXT("%s"), _T("S-Key"));
	}
	else if (GetKeyState('D') & 0x8000)
	{
		wsprintf(sKeyState, TEXT("%s"), _T("D-Key"));
	}
	else if (GetKeyState('W') & 0x8000)
	{
		wsprintf(sKeyState, TEXT("%s"), _T("W-Key"));
	}
	else
	{
		wsprintf(sKeyState, TEXT(""));
	}

	return VOID();
}

BOOL CALLBACK Dlg6_1Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	//RECT rt;
	//GetClientRect(hDlg, &rt);
	TCHAR word[256];


	static int Check[3], Radio;
	TCHAR hobby[][30] = { _T("독서"), _T("음악감상"), _T("컴퓨터게임") };
	TCHAR sex[][30] = { _T("여자"), _T("남자") };
	TCHAR output[200];


	static HWND hCombo;
	static int selection;
	TCHAR name[30];


	switch (iMsg)
	{
	case WM_INITDIALOG:
		//SetWindowPos(hDlg, NULL, ())
	{
		//HWND hButton;
		//hButton = GetDlgItem(hDlg, ID_BUTTON_PRINT);
		//EnableWindow(hButton, FALSE); // 버튼 비활성화 기능

		CheckRadioButton(hDlg, IDC_RADIO_FEMALE, IDC_RADIO_MALE, IDC_RADIO_FEMALE);
		//female에서 male 까지이며 디폴드값 female
	}


	{
		hCombo = GetDlgItem(hDlg, IDC_COMBO_LIST);
	}

	return (INT_PTR)TRUE;

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			/*
			case ID_BUTTON_PRINT:
			{
			HDC hdc = GetDC(hDlg);
			TextOut(hdc, 10, 10, _T("Hello Dialog"), 12);
			ReleaseDC(hDlg, hdc);
			}
			break;
			*/
		case IDC_BUTTON_COPY:
			GetDlgItemText(hDlg, IDC_EDIT_INPUT, word, 256);
			SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, word);
			break;
		case IDC_BUTTON_DELETE:
			SetDlgItemText(hDlg, IDC_EDIT_INPUT, _T(""));
			SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, _T(""));
			break;
		case ID_BUTTON_END:
			EndDialog(hDlg, 0);
			break;

		case IDC_CHECK_READING:
			Check[0] = 1 - Check[0];
			break;

		case IDC_CHECK_MUSIC:
			Check[1] = 1 - Check[1];
			break;

		case IDC_CHECK_COMPUTERGAME:
			Check[2] = 1 - Check[2];
			break;


		case IDC_RADIO_FEMALE:
			Radio = 0;
			break;

		case IDC_RADIO_MALE:
			Radio = 1;
			break;


		case ID_BUTTON_OUTPUT:
			_stprintf_s(output, _T("선택한 취미는 %s %s %s 입니다.\r\n")_T("선택한 성별은 %s 입니다"),
				Check[0] ? hobby[0] : _T(""),
				Check[1] ? hobby[1] : _T(""),
				Check[2] ? hobby[2] : _T(""),
				sex[Radio]
			);
			SetDlgItemText(hDlg, IDC_EDIT_SAMPLE, output);
			break;

		case IDC_INSERT:
			GetDlgItemText(hDlg, IDC_EDIT_NAME, name, 30);
			if (_tcscmp(name, _T("")))
			{
				SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)name);
				return 0;
			}
			return 0;
			break;

		case IDC_DELETE2:
			SendMessage(hCombo, CB_DELETESTRING, selection, 0);
			return 0;
			break;

		case IDC_COMBO_LIST:
			if (HIWORD(wParam) == CBN_SELCHANGE)
				selection = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			break;

		}

	}
	break;
	}
	return 0;
}

LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	SetTimer(hWnd, 1, 70, NULL);
	HDC hdc = GetDC(hWnd);
	
	static RECT rt;

	switch (iMsg)
	{
	case WM_CREATE:
		break;

	case WM_PAINT:
		Ellipse(hdc, 100, 100, 200, 200);
		break;
	case WM_TIMER:
		GetClientRect(hWnd, &rt);
		InvalidateRect(hWnd, &rt, FALSE);
		break;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		break;

	default:
		break;
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

LRESULT CALLBACK ChildWndProc2(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hButton;
	HWND hButton1;
	HWND hButton2;
	HWND hButton3;

	switch (iMsg)
	{
	case WM_CREATE:
		hButton = CreateWindow(_T("button"), _T("확인"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 200, 10, 100, 25, hWnd, (HMENU)IDC_CHILD_BTN, hInst, NULL);
		hButton1 = CreateWindow(_T("button"), _T("원"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 200, 40, 100, 25, hWnd, (HMENU)IDC_CHILD_BTN2, hInst, NULL);
		hButton2 = CreateWindow(_T("button"), _T("사각형"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 200, 70, 100, 25, hWnd, (HMENU)IDC_CHILD_BTN3, hInst, NULL);
		hButton3 = CreateWindow(_T("button"), _T("별"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 200, 100, 100, 25, hWnd, (HMENU)IDC_CHILD_BTN4, hInst, NULL);
		break;


	case WM_COMMAND:
		switch (iMsg)
		{
		case IDC_CHILD_BTN2:
		{	/*
			HDC hdc = GetDC(hWnd);

			ReleaseDC(hWnd, hdc);
			return 0;
			*/
		}

		break;

		case IDC_CHILD_BTN3:
			break;

		case IDC_CHILD_BTN4:
			break;

		default:
			break;
		}

		break;


	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}