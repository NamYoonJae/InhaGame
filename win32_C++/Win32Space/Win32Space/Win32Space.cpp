// Win32Space.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32Space.h"
#include "space.h"
#include <vector>

#define MAX_LOADSTRING 100
using namespace std;

enum
{
	enum_Login = 0,
	enum_InGame = 1,
	enum_EndGame = 2,

};

vector <cBullet*> cBulletList;
vector <cBlock*> cBlockList;
double bulletCenterX = 213;
double bulletCenterY = 700 - 80 - 4;
double fireAngle = 90;
int intLife = 10;
int gameFlag = 0;
int score = 0;

static int nameCount;
static TCHAR userName[30];

void Restart();

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


	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WIN32SPACE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32SPACE));

	MSG msg;

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



BOOL PtInRect(RECT PtInRect)
{

	return 0;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32SPACE));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WIN32SPACE);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 450, 800, nullptr, nullptr, hInstance, nullptr);

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
	static cCannon * newCannon = new cCannon;
	static HDC hdc;
	RECT rt;
	RECT rtRestart = {150, 400, 220, 430};
	RECT rtEnd = {250, 400, 320, 430};

	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 40, NULL);
		SetTimer(hWnd, 2, 1000, NULL);
		break;

	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
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

	case WM_CHAR:
		hdc = GetDC(hWnd);
		if (gameFlag ==0) 
		{
			if (wParam !=VK_BACK)
			{
				userName[nameCount++] = wParam;
				userName[nameCount] = NULL;
			}
		}
		ReleaseDC(hWnd, hdc);
		break;

	case WM_PAINT:
	{

		PAINTSTRUCT ps;
		hdc = BeginPaint(hWnd, &ps);
		POINT pos;
		pos = { 213, 700 };
		int r = 50;
		int result;
		int i = 0;
		RECT rimitXY;

		if (gameFlag == 1)
		{
			//인게임
			for (i = 0; i < cBlockList.size(); i++)
			{
				cBlockList[i]->Draw(hdc);
				cBlockList[i]->Move(hdc, 3);
			}


			GetClientRect(hWnd, &rimitXY);

			Pie(hdc, pos.x - r, pos.y - r, pos.x + r, pos.y + r,
				pos.x + r, pos.y, pos.x - r, pos.y);

			newCannon->Draw(hdc);
			for (int i = 0; i < cBulletList.size(); i++)
			{
				cBulletList[i]->Draw(hdc);
				result = cBulletList[i]->move(hdc, rimitXY.right);
				if (result == 1)
				{
					delete(cBulletList[i]);
					cBulletList.erase(cBulletList.begin() + i);

				}
			}

			MoveToEx(hdc, 0, 700, NULL);
			LineTo(hdc, 450, 700);

			RECT lifeXY;


			TCHAR ScoreString[10] = _T("SCORE : ");
			TCHAR charScore[1024] = { 0 };

			lifeXY.left = 10;
			lifeXY.top = 710;
			lifeXY.right = 100;
			lifeXY.bottom = 810;
			_itot_s(score, charScore, 10);
			DrawText(hdc, ScoreString, _tcslen(ScoreString), &lifeXY, DT_LEFT | DT_TOP);

			lifeXY.left = 80;
			lifeXY.top = 710;
			lifeXY.right = 200;
			lifeXY.bottom = 810;
			DrawText(hdc, charScore, _tcslen(charScore), &lifeXY, DT_LEFT | DT_TOP);

			lifeXY.left = 350;
			lifeXY.top = 710;
			lifeXY.right = 400;
			lifeXY.bottom = 810;

			TCHAR lifeString[10] = _T("LIFE : ");
			TCHAR charLife[10] = { 0 };
			_itot_s(intLife, charLife, 10);
			DrawText(hdc, lifeString, _tcslen(lifeString), &lifeXY, DT_LEFT | DT_TOP);

			lifeXY.left = 400;
			lifeXY.top = 710;
			lifeXY.right = 450;
			lifeXY.bottom = 810;
			DrawText(hdc, charLife, _tcslen(charLife), &lifeXY, DT_LEFT | DT_TOP);

			for (i = 0; i < cBulletList.size(); i++)
			{
				if (cBulletList[i]->collision() == TRUE)
				{
					delete(cBulletList[i]);
					cBulletList.erase(cBulletList.begin() + i);
				}

			}

			for (i = 0; i < cBlockList.size(); i++)
			{
				if (cBlockList[i]->Collision() == TRUE)
				{
					delete(cBlockList[i]);
					cBlockList.erase(cBlockList.begin() + i);
					intLife--;
				}
			}

			if (intLife <= 0)
			{
				gameFlag = 2;
			}
		}
		else if (gameFlag == 2)
		{
			//게임 오버
			rt.left = 200;
			rt.top = 300;
			rt.right = 450;
			rt.bottom = 750;
			TCHAR gameOver[30] = _T("게임 오버");
			DrawText(hdc, gameOver, _tcslen(gameOver), &rt, DT_LEFT | DT_TOP);

			TCHAR restart[16] = _T("다시 하기");
			DrawText(hdc, restart, _tcslen(restart), &rtRestart, DT_LEFT | DT_TOP);

			TCHAR end[16] = _T(" 종료하기");
			DrawText(hdc, end, _tcslen(end), &rtEnd, DT_LEFT | DT_TOP);
			
			
		}
		else
		{
			//로그인
			rt.left = 150;
			rt.top = 200;
			rt.right = 450;
			rt.bottom = 750;

			TCHAR gameName[50] = _T("스페이스 인베이더");
			DrawText(hdc, gameName, _tcslen(gameName), &rt, DT_LEFT | DT_TOP);

			TCHAR userID[20] = _T("USER ID : ");
			rt.left = 120;
			rt.top = 350;
			rt.right = 450;
			rt.bottom = 750;
			
			DrawText(hdc, userID, _tcslen(userID), &rt, DT_LEFT | DT_TOP);

			
			TextOut(hdc, 200, 350, userName, _tcslen(userName));

		}

		EndPaint(hWnd, &ps);
	}
	break;

	case WM_TIMER:
	{
		int i = 0;
		if (gameFlag == 1)
		{
			if (2 == wParam)
			{
				double x, y;

				x = 30;
				y = 30;

				for (i = 0; i < 8; i++)
				{
					cBlock *newBlock = new cBlock(x, y);
					cBlockList.push_back(newBlock);
					x += 53;
				}
			}
		}

	}


	InvalidateRect(hWnd, NULL, TRUE);
	break;

	case WM_LBUTTONDOWN:
		POINT inPoint;

		inPoint.x = LOWORD(lParam);
		inPoint.y = HIWORD(lParam);

		if (gameFlag == enum_EndGame) 
		{
			if (PtInRect(&rtRestart, inPoint))
				Restart();

			if (PtInRect(&rtEnd, inPoint))
				DestroyWindow(hWnd);
		}
		break;

	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_RIGHT:
			if (gameFlag == 1) 
			{
				newCannon->move(hdc, 1);
			}
			break;

		case VK_LEFT:
			if (gameFlag == 1)
			{
				newCannon->move(hdc, 2);
			}
			break;

		case VK_SPACE:
		{
			if (gameFlag == 1)
			{
				cBullet * newBullet = new cBullet();
				cBulletList.push_back(newBullet);
			}
		}
		break;

		case VK_RETURN: 
		{
			gameFlag = 1;
		}

		case VK_BACK:
			if(nameCount>0)
			{
				nameCount--;
				userName[nameCount] = ' ';

			}
			break;

		default:
			break;
		}

		//InvalidateRect(hWnd, NULL, TRUE);

		break;

	case WM_DESTROY:
		ReleaseDC(hWnd, hdc);
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

void Restart() 
{
	int i = 0;
	
	for (i = 0; i < cBlockList.size(); i++)
	{
		delete(cBlockList[i]);
	}
	cBlockList.clear();

	for (i = 0; i<cBulletList.size(); i++) 
	{
		delete(cBulletList[i]);
	}
	cBulletList.clear();

	intLife = 10;
	score = 0;

	gameFlag = 1;
}