// Win32ProjectJMakeText.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32ProjectJMakeText.h"

#define MAX_LOADSTRING 100

void FileRead(HWND hwnd, LPTSTR filename);
void FileSave(HWND hwnd, LPTSTR filename);

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
    LoadStringW(hInstance, IDC_WIN32PROJECTJMAKETEXT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECTJMAKETEXT));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECTJMAKETEXT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32PROJECTJMAKETEXT);
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

#define IDC_EDIT8_4 100
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hEdit;
	RECT rect;

	switch (message)
	{
	case WM_CREATE:
		GetClientRect(hWnd, &rect);
		hEdit = CreateWindow(
			_T("edit"),
			NULL,
			WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE,
			0,
			100,
			rect.right,
			rect.bottom,
			hWnd,
			(HMENU)IDC_EDIT8_4,
			hInst,
			NULL
		);
	case WM_SIZE:
		GetClientRect(hWnd, &rect);
		MoveWindow(hEdit, 0, 0, rect.right, rect.bottom, TRUE);
		return 0;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_FILEOPEN:
			FileRead(hEdit, _T("test2.txt"));
			break;
		case ID_FILESAVE:
			FileSave(hEdit, _T("test2.txt"));
			break;

		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

		return DefWindowProc(hWnd, message, wParam, lParam);
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

void FileRead(HWND hwnd, LPTSTR filename) 
{
	HANDLE hFile;
	LPTSTR buffer;
	DWORD size, CharNum;
	int fileSize;
	hFile = CreateFile(
		filename,
		GENERIC_READ,
		0,
		0,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		0
	);

	if (hFile == INVALID_HANDLE_VALUE)
		return;
	fileSize = GetFileSize(hFile, &size);
	buffer = new TCHAR[(int)fileSize / sizeof(TCHAR) + 1];
	memset(buffer, 0, fileSize);
	ReadFile(hFile, buffer, fileSize, &CharNum, NULL);
	buffer[(int)fileSize / sizeof(TCHAR)] = NULL;
	SetWindowText(hwnd, buffer);
	free(buffer);
	CloseHandle(hFile);
}

void FileSave(HWND hwnd, LPTSTR filename)
{
	HANDLE hFile;
	LPTSTR buffer;
	int size;

#ifdef _UNICODE
	WORD uni = 0xFEFF;
	DWORD nSize;

#endif
	hFile = CreateFile(
		filename,
		GENERIC_WRITE,
		0,
		0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
	);

#ifdef _UNICODE
	WriteFile(hFile, &uni, 2, &nSize, NULL);
#endif
	size = GetWindowTextLength(hwnd);
	buffer = new TCHAR[size + 1];
	memset(buffer, 0, (size + 1) * sizeof(TCHAR));
	size = GetWindowText(hwnd, (LPTSTR)buffer, size + 1);
	buffer[size] = NULL;
	WriteFile(hFile, buffer, size + sizeof(TCHAR), (LPDWORD)&size, NULL);
	free(buffer);
	CloseHandle(hFile);

}