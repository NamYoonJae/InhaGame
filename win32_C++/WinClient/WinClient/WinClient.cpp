// WinClient.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WinClient.h"
#include <winsock.h>
#include <stdio.h>
#include <TCHAR.h>
#include <vector>
#include <string>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

#define WM_ASYNC WM_USER + 2
#define MAX_LOADSTRING 100

vector <wstring> chattingHistory;

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int WinClient();

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
	LoadStringW(hInstance, IDC_WINCLIENT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINCLIENT));

	//return WinClient();


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

	return (int)msg.wParam;

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

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINCLIENT));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINCLIENT);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
	HDC hdc;
	PAINTSTRUCT ps;
	static WSADATA wsadata;
	static SOCKET s;
	static SOCKADDR_IN addr = { 0 };
	static TCHAR msg[200];
	static TCHAR str[100];
	static char buffer[100];
	static int count;
	int msgLen;
	static int yPos = 30;


	switch (message)
	{
	case WM_CREATE:
		WSAStartup(MAKEWORD(2, 2), &wsadata);
		s = socket(AF_INET, SOCK_STREAM, 0);
		if (s == INVALID_SOCKET)
		{
			MessageBox(NULL, _T("listen failed"), _T("Error"), MB_OK);
			return 0;
		}
		else
		{
			MessageBox(NULL, _T("listen success"), _T("Success"), MB_OK);
		}

		addr.sin_family = AF_INET;
		addr.sin_port = 20;
		addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

		if (connect(s, (LPSOCKADDR)&addr, sizeof(addr)) == SOCKET_ERROR)
			return 0;
		WSAAsyncSelect(s, hWnd, WM_ASYNC, FD_READ);
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

		if (_tcscmp(msg, _T("")))
				TextOut(hdc, 0, 0, msg, (int)_tcslen(msg));
			TextOut(hdc, 0, 0, str, _tcslen(str));

		for (int i = 1; i < chattingHistory.size(); i++)
		{

			TextOut(hdc, 0, i * 20, chattingHistory[i].c_str(), chattingHistory[i].size());

		}
		EndPaint(hWnd, &ps);
	}
	break;

	case WM_ASYNC:

		switch (lParam)
		{

		case FD_READ:
		{
			msgLen = recv(s, buffer, 100, 0);
			buffer[msgLen] = NULL;


#ifdef _UNICODE
			msgLen = MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), NULL, NULL);
			MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), msg, msgLen);
			msg[msgLen] = NULL;
			//yPos += 20;
#else
			strcpy_s(msg, buffer);
#endif
			wstring temp;

			temp += str;
			chattingHistory.push_back(temp);
			InvalidateRgn(hWnd, NULL, TRUE);
		}
		break;

		default:
			break;
		}
		break;

	case WM_CHAR:
		if (wParam == VK_RETURN)
			if (s == INVALID_SOCKET)

				return 0;
			else
			{
#ifdef _UNICODE
				msgLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
				WideCharToMultiByte(CP_ACP, 0, str, -1, buffer, msgLen, NULL, NULL);
#else
				strcpy_s(buffer, str);
				msgLen = strlen(buffer);
#endif
				send(s, (LPSTR)buffer, msgLen + 1, 0);

				chattingHistory.push_back(str);
				count = 0;
				InvalidateRgn(hWnd, NULL, TRUE);
				return 0;

			}
		if (wParam == VK_BACK && count > 0) count--;
		else str[count++] = wParam;
		//chattingHistory.push_back(str);
		str[count] = NULL;

		InvalidateRgn(hWnd, NULL, TRUE);
		return 0;

	case WM_DESTROY:
		closesocket(s);
		WSACleanup();
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

int WinClient()
{
	WSADATA wsadata;
	SOCKET s;
	SOCKADDR_IN addr = { 0 };

	WSAStartup(MAKEWORD(2, 2), &wsadata);
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET)
	{
		MessageBox(NULL, _T("listen failed"), _T("Error"), MB_OK);
		return 0;
	}
	else
	{
		MessageBox(NULL, _T("listen success"), _T("Success"), MB_OK);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = 20;
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	if (connect(s, (LPSOCKADDR)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		MessageBox(NULL, _T("listen failed"), _T("Error"), MB_OK);
		return 0;
	}
	else
	{
		MessageBox(NULL, _T("listen success"), _T("Success"), MB_OK);
		send(s, "�ȳ��ϼ��� Server!", 19, 0);
	}

	closesocket(s);
	WSACleanup();
	return 1;
}
