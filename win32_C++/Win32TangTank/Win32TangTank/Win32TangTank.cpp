// Win32TangTank.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Win32TangTank.h"
#include "TangTank.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#pragma comment(lib, "msimg32.lib")

#define MAX_LOADSTRING 100

enum
{
	enum_in_block = 0,
	enum_out_block = 1,

	enum_Main = 1000,
	enum_InGame = 1001,
	enum_GameOver = 1002
};

using namespace std;

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.


HBITMAP hTankImage;
BITMAP bitTank;

HBITMAP hExplosion;
BITMAP bitExplosion;

HBITMAP hMain;
BITMAP bitMain;

HBITMAP hGameOver;
BITMAP bitGameOver;



const int Sprite_Size_X = 0;
const int Sprite_Size_Y = 0;
int Move_Frame_Max = 0;
int Move_Frame_Min = 0;
int cur_Frame = Move_Frame_Min;

cBlock* MapArray[MAPSIZE][MAPSIZE];
vector<cTankBody*> vTankBody;
vector<cTankHead*> vTankHead;
vector<cBullet*> vBullet;

void CreateBitMap();
void MainMenu(HDC hdc);
void CreateMaze();
void CreateTank();
int makeCenterX();
int makeCenterY();
void DrawMap(HDC hdc, HWND hWnd);
int Random();
bool OpenSearch(int x, int y);
bool DeleteMap();
void DeleteBitmap();
bool MakeBullet();
int gameFlag;



void DrawMain(HDC hdc);
void DrawGameOver(HDC hdc);

VOID CALLBACK KeyStateProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

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
    LoadStringW(hInstance, IDC_WIN32TANGTANK, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32TANGTANK));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32TANGTANK));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32TANGTANK);
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
      CW_USEDEFAULT, 0, 1000, 1000, nullptr, nullptr, hInstance, nullptr);
   
   /*
   HWND hWnd = CreateWindowExW(WS_EX_APPWINDOW, szWindowClass, szTitle, WS_POPUP,
	   0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), nullptr, nullptr, hInstance, nullptr);
   */

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
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	RECT rt_gamePlay2 = { 576, 609, 615, 650 };

	switch (message)
	{
	case WM_CREATE:
		{
			AllocConsole();
			freopen("CONOUT$", "wt", stdout);

			SetTimer(hWnd, 1, 70, NULL);
			SetTimer(hWnd, 2, 70, KeyStateProc);
			srand((unsigned int)time(NULL));
		
			for (int i = 0; i < MAPSIZE; i++) 
			{
				for (int j = 0; j < MAPSIZE; j++) 
				{
					MapArray[i][j] = NULL;
				}
			}
			gameFlag = enum_Main;
			CreateBitMap();
			MainMenu(hdc);
			
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
            
			int i = 0;

			if (gameFlag == enum_Main)
			{
				DrawMain(hdc);
			}


			else if (gameFlag == enum_InGame)
			{		
				DrawMap(hdc, hWnd);

				if (vTankBody.size() > 0 && vTankHead.size() > 0)
				{

					for (i = 0; i < vTankBody.size(); i++)
					{


						if (vTankBody[i] != NULL && vTankHead[i] != NULL)
						{
							vTankBody[i]->DrawTankBody(hdc);
							vTankHead[i]->DrawTankHead(hdc);
						}

					}
				}

				if (vBullet.size() > 0)
				{
					for (i = 0; i < vBullet.size(); i++)
					{
						vBullet[i]->DrawBullet(hdc);
					}
				}

				if (vBullet.size() > 0)
				{
					int i = 0;
					int j = 0;
					for (i = 0; i < vBullet.size(); i++)
					{


						vBullet[i]->MoveBullet();


						int bAngle = vBullet[i]->GetBulletAngle();
						float bCenterX = vBullet[i]->GetBulletCenterX();
						float bCenterY = vBullet[i]->GetBulletCenterY();
						float bMoveMaX = vBullet[i]->GetBulletMoveMaxX();
						float bMoveMaY = vBullet[i]->GetBulletMoveMaxY();
						int bR = vBullet[i]->GetBulletR();

						//�Ѿ��̶� ��ũ�� �浹 ��
						if (vTankBody.size() > 0)
						{
							for (j = 0; j < vTankBody.size(); j++)
							{
								if (vTankBody[j] != NULL)
								{
									int result = vTankBody[j]->CollisionCheck(hdc, bCenterX, bCenterY, bR);
									if (result == 1)
									{
										//float tb_x = vTankBody[j]->GetCenterX();
										//float tb_y = vTankBody[j]->GetCenterY();
										int xStart = 0;
										int yStart = 0;
										for (int k = 0; k < 34; k++)
										{
											
											for (int z = 0; z < 1000; z++) 
											{
												vTankBody[j]->DrawExplosion(hdc, xStart, yStart);
											}
											
											
											xStart = xStart + 125;
											if (xStart == 1050)
											{
												xStart = 0;
												yStart = yStart + 125;
											}


										}

										delete(vTankHead[j]);
										vTankHead[j] = NULL;

										delete(vTankBody[j]);
										vTankHead[j] = NULL;

										gameFlag = enum_GameOver;


									}
								}

							}
						}





						//�Ѿ��̶� ���̶� �浹 ��
						if (0 < bAngle && bAngle < 180)
						{

							if (bCenterY <= bMoveMaY)
							{
								vBullet[i]->SetBulletCollision();
								vBullet[i]->ChagneAngle();
								if (vBullet[i]->GetCollision() > 9)
								{
									//����
									delete(vBullet[i]);
									vBullet.erase(vBullet.begin() + i);
									if (vTankHead[0] != NULL)
									{
										vTankHead[0]->DecreaseBulletCount();
									}
								}

							}
						}
						else if (180 < bAngle && bAngle < 360)
						{
							if (bCenterY >= bMoveMaY)
							{
								vBullet[i]->SetBulletCollision();
								vBullet[i]->ChagneAngle();
								if (vBullet[i]->GetCollision() > 9)
								{
									//����
									delete(vBullet[i]);
									vBullet.erase(vBullet.begin() + i);
									if (vTankHead[0] != NULL)
									{
										vTankHead[0]->DecreaseBulletCount();
									}

								}


							}
						}
						else if (bAngle == 0 || bAngle == 360)
						{
							if (bCenterX <= bMoveMaX)
							{

								vBullet[i]->SetBulletCollision();
								vBullet[i]->ChagneAngle();
								if (vBullet[i]->GetCollision() > 9)
								{
									//����
									delete(vBullet[i]);
									vBullet.erase(vBullet.begin() + i);
									if (vTankHead[0] != NULL)
									{
										vTankHead[0]->DecreaseBulletCount();
									}

								}

							}
						}
						else if (bAngle == 180)
						{
							if (bCenterX >= bMoveMaX)
							{
								vBullet[i]->SetBulletCollision();
								vBullet[i]->ChagneAngle();

								if (vBullet[i]->GetCollision() > 9)
								{
									//����
									delete(vBullet[i]);
									vBullet.erase(vBullet.begin() + i);
									if (vTankHead[0] != NULL)
									{
										vTankHead[0]->DecreaseBulletCount();
									}

								}

							}
						}


					}
				}
			}
			else if (gameFlag == enum_GameOver)
			{
			DrawGameOver(hdc);
			}
			
            EndPaint(hWnd, &ps);

        }
        break;
	case WM_TIMER:
		
		InvalidateRect(hWnd, NULL, FALSE);
		
		
	
	case WM_LBUTTONDOWN:
	{
		POINT inPoint;

		inPoint.x = LOWORD(lParam);
		inPoint.y = HIWORD(lParam);

		if (gameFlag == enum_Main)
		{	
			if (PtInRect(&rt_gamePlay2, inPoint)) 
			{
				CreateMaze();
				CreateTank();
				gameFlag = enum_InGame;
			}
			
		}
		
	}
	break;

    case WM_DESTROY:
		DeleteBitmap();
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

void CreateBitMap()
{
	hTankImage = (HBITMAP)LoadImage(NULL, TEXT("����ũ.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hTankImage, sizeof(BITMAP), &bitTank);

	hExplosion = (HBITMAP)LoadImage(NULL, TEXT("explosionSprite.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hExplosion, sizeof(BITMAP), &bitExplosion);

	hMain = (HBITMAP)LoadImage(NULL, TEXT("main.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hMain, sizeof(BITMAP), &bitMain);

	hGameOver = (HBITMAP)LoadImage(NULL, TEXT("���ӿ���.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hGameOver, sizeof(BITMAP), &bitGameOver);



}

void MainMenu(HDC hdc)
{
	


}

void CreateMaze()
{
	int i = 0;
	int j = 0;
	int x = 90;
	int y = 70;
	int count = 0;

	for (i =0; i < MAPSIZE; i++)
	{
		for (j = 0; j < MAPSIZE; j++) 
		{
			//�ܺ� �� ����
			if (i ==0 || j ==0) 
			{
				cBlock* newBlock = new cBlock(x, y, 10, enum_out_block);
				MapArray[i][j] = newBlock;
			}
			else if (i == MAPSIZE-1 || j == MAPSIZE-1) 
			{
				cBlock* newBlock = new cBlock(x, y, 10, enum_out_block);
				MapArray[i][j] = newBlock;
			}


			
			//���� �� ����
			if (i % 4 == 0 && j % 4 == 0)
			{
				if (i != 0 && j != 0 && i != 20 && j != 20) 
				{
					cBlock* newBlock = new cBlock(x, y, 10, enum_in_block);
					MapArray[i][j] = newBlock;
				}
			}
			if (i % 4 ==0 || j % 4 ==0) 
			{
				if (i != 0 && j != 0)
				{
					if (Random() % 2 == 0)
					{
						if (i != 0 && j != 0 && i != 20 && j != 20)
						{
							cBlock* newBlock = new cBlock(x, y, 10, enum_in_block);
							MapArray[i][j] = newBlock;
						}

					}

				}
			}
			x = x + (block_R * 2);
		}
		x = 90;
		y = y + (block_R * 2);
	}

	bool deleteResult = false;
	bool flag = false;
	for (i = 0; i < 17; i = i + 4)
	{
		for (j = 0; j < 17; j = j + 4)
		{
			if (OpenSearch(i, j) == false)
			{
				cout << "��ũ�� ���� �� ���� ���� �����մϴ�" << endl;
				//���� �� ���� �� �ٽ� ����
				deleteResult= DeleteMap();
				if (deleteResult == true)
				{
					cout << "���� �Ϸ�" << endl;
					cout << "���ο� ���� ���� �մϴ�" << endl;
					CreateMaze();
					flag = true;
					break;
				}
				else
				{
					cout << "�� ���� ���� �����ڿ��� ���� �ٶ�" << endl;
					flag = true;
					break;
				}

			}
			count++;
			cout << "openSearch Result: " << OpenSearch(i, j) << endl;
			cout << count << endl;

		}
		if (flag == true) 
		{
			break;
		}
	}

}

void CreateTank()
{
	int i = 0;
	int j = 0;
	//cTankBody* newTankBody = new cTankBody();
	//vTankBody.push_back(newTankBody);
	//cTankHead* newTankHead = new cTankHead();
	//vTankHead.push_back(newTankHead);
	
	//���� ���� % 10 -> �������� ���� i ���� ����
	//���� ���� % 10 -> �������� ���� j ���� ����

	i = makeCenterX();
	j = makeCenterY();

	cTankBody* newTankBody = new cTankBody(i, j);
	vTankBody.push_back(newTankBody);
	cTankHead* newTankHead = new cTankHead(i, j);
	vTankHead.push_back(newTankHead);




}

int makeCenterX()
{
	int i = 0;
	int ran = Random() % 10;

	if (ran == 0 || ran == 5)
	{
		i = 2;
	}
	else if (ran == 1 || ran == 6)
	{
		i = 6;
	}
	else if (ran == 2 || ran == 7)
	{
		i = 10;
	}
	else if (ran == 3 || ran == 8)
	{
		i = 14;
	}
	else if (ran == 4 || ran == 9)
	{
		i = 18;
	}

	return i;
}

int makeCenterY()
{
	int j = 0;
	int ran = Random() % 10;

	if (ran == 0 || ran == 5)
	{
		j = 2;
	}
	else if (ran == 1 || ran == 6)
	{
		j = 6;
	}
	else if (ran == 2 || ran == 7)
	{
		j = 10;
	}
	else if (ran == 3 || ran == 8)
	{
		j = 14;
	}
	else if (ran == 4 || ran == 9)
	{
		j = 18;
	}
	return j;
}

void DrawMap(HDC hdc, HWND hWnd)
{
	
	HBRUSH Brush, oBrush;
	HDC memDC, memDC2;
	HBITMAP oldBitmap, bitmap, bitmap2;
	
	RECT rt;
	GetClientRect(hWnd,&rt);

	memDC = CreateCompatibleDC(hdc);
	bitmap = CreateCompatibleBitmap(hdc, rt.right, rt.bottom);
	oldBitmap = (HBITMAP)SelectObject(memDC, bitmap);



	PatBlt(memDC, rt.left, rt.top, rt.right, rt.bottom, WHITENESS);

	int i = 0;
	int j = 0;

	int MapSize = (sizeof(MapArray)) / (sizeof(MapArray[0]));

	if (MapSize > 0)
	{
		for (i = 0; i < MAPSIZE; i++)
		{
			for (j = 0; j < MAPSIZE; j++)
			{
				if (MapArray[i][j] != NULL)
				{
					//�ܺ� ��
					if (MapArray[i][j]->GetState() == enum_out_block)
					{
						Brush = CreateSolidBrush(RGB(102, 0, 0));
						oBrush = (HBRUSH)SelectObject(memDC, Brush);
						MapArray[i][j]->DrawBlock(memDC);
						SelectObject(memDC, oBrush);
						DeleteObject(Brush);
					}
					//���� ��
					else
					{
						//collisionNum�� ���� ���� �ο�
						if (MapArray[i][j]->GetcollosionNum() == 10)
						{
							Brush = CreateSolidBrush(RGB(102, 0, 0));
							oBrush = (HBRUSH)SelectObject(memDC, Brush);
							MapArray[i][j]->DrawBlock(memDC);
							SelectObject(memDC, oBrush);
							DeleteObject(Brush);
						}
						else if (MapArray[i][j]->GetcollosionNum() == 9)
						{
							Brush = CreateSolidBrush(RGB(117.3, 25.5, 25.5));
							oBrush = (HBRUSH)SelectObject(memDC, Brush);
							MapArray[i][j]->DrawBlock(memDC);
							SelectObject(memDC, oBrush);
							DeleteObject(Brush);
						}
						else if (MapArray[i][j]->GetcollosionNum() == 8)
						{
							Brush = CreateSolidBrush(RGB(132.6, 50, 50));
							oBrush = (HBRUSH)SelectObject(memDC, Brush);
							MapArray[i][j]->DrawBlock(memDC);
							SelectObject(memDC, oBrush);
							DeleteObject(Brush);
						}
						else if (MapArray[i][j]->GetcollosionNum() == 7)
						{
							Brush = CreateSolidBrush(RGB(147.9, 75.5, 75.5));
							oBrush = (HBRUSH)SelectObject(memDC, Brush);
							MapArray[i][j]->DrawBlock(memDC);
							SelectObject(memDC, oBrush);
							DeleteObject(Brush);
						}
						else if (MapArray[i][j]->GetcollosionNum() == 6)
						{
							Brush = CreateSolidBrush(RGB(163.2, 100, 100));
							oBrush = (HBRUSH)SelectObject(memDC, Brush);
							MapArray[i][j]->DrawBlock(memDC);
							SelectObject(memDC, oBrush);
							DeleteObject(Brush);
						}
						else if (MapArray[i][j]->GetcollosionNum() == 5)
						{
							Brush = CreateSolidBrush(RGB(178.5, 125.5, 125.5));
							oBrush = (HBRUSH)SelectObject(memDC, Brush);
							MapArray[i][j]->DrawBlock(memDC);
							SelectObject(memDC, oBrush);
							DeleteObject(Brush);
						}
						else if (MapArray[i][j]->GetcollosionNum() == 4)
						{
							Brush = CreateSolidBrush(RGB(198.8, 150, 150));
							oBrush = (HBRUSH)SelectObject(memDC, Brush);
							MapArray[i][j]->DrawBlock(memDC);
							SelectObject(memDC, oBrush);
							DeleteObject(Brush);
						}
						else if (MapArray[i][j]->GetcollosionNum() == 3)
						{
							Brush = CreateSolidBrush(RGB(209.1, 175.5, 175.5));
							oBrush = (HBRUSH)SelectObject(memDC, Brush);
							MapArray[i][j]->DrawBlock(memDC);
							SelectObject(memDC, oBrush);
							DeleteObject(Brush);
						}
						else if (MapArray[i][j]->GetcollosionNum() == 2)
						{
							Brush = CreateSolidBrush(RGB(224.4, 200, 200));
							oBrush = (HBRUSH)SelectObject(memDC, Brush);
							MapArray[i][j]->DrawBlock(memDC);
							SelectObject(memDC, oBrush);
							DeleteObject(Brush);
						}
						else if (MapArray[i][j]->GetcollosionNum() == 1)
						{
							Brush = CreateSolidBrush(RGB(255, 225.5, 225.5));
							oBrush = (HBRUSH)SelectObject(memDC, Brush);
							MapArray[i][j]->DrawBlock(memDC);
							SelectObject(memDC, oBrush);
							DeleteObject(Brush);
						}
						else if (MapArray[i][j]->GetcollosionNum() < 1)
						{
							
							delete(MapArray[i][j]);
							MapArray[i][j] = NULL;
							

						}
					}
					


				}

			}
		}
	}
	
	BitBlt(hdc, 0, 0, rt.right, rt.bottom, memDC, 0, 0, SRCCOPY);
	SelectObject(memDC, oldBitmap);

	DeleteObject(bitmap);
	DeleteObject(oldBitmap);
	DeleteDC(memDC);

	
}

int Random()
{
	int randomNum = 0;
	randomNum = rand();
	return randomNum;
}

bool OpenSearch(int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = x; i < x + 5; i = i + 4)
	{
		for (j = y + 1; j < y + 4; j++)
		{
			if (MapArray[i][j] == NULL) 
			{
				return true;
			}
		}
	}
	for (i = y; i < y + 5; i = i + 4)
	{
		for (j = x + 1; j < x + 4; j++)
		{
			if (MapArray[j][i] == NULL)
			{
				return true;
			}
		}
	}
	return false;
}

bool DeleteMap()
{
	int i = 0;
	int j = 0;

	for (i = 0; i < MAPSIZE; i++) 
	{
		for (j = 0; j < MAPSIZE; j++) 
		{
			if (MapArray[i][j] != NULL) 
			{
				delete(MapArray[i][j]);
				MapArray[i][j] = NULL;
			}
		}
	}

	for (i = 0; i < MAPSIZE; i++)
	{
		for (j = 0; j < MAPSIZE; j++)
		{
			if (MapArray[i][j] != NULL)
			{
				return false;
			}
		}
	}

	return true;
}

void DeleteBitmap()
{
	DeleteObject(hTankImage);
	DeleteObject(hExplosion);
	DeleteObject(hMain);
	DeleteObject(hGameOver);
}

bool MakeBullet()
{

	if (vTankHead[0]->GetBulletCount() < vTankHead[0]->GetBulletLimit())
	{
		int x = vTankHead[0]->GetTankHeadCenterX();
		int y = vTankHead[0]->GetTankHeadCenterY();
		int angle = vTankHead[0]->GetTankHeadAngle();
		cBullet* newBullet = new cBullet(x, y, angle);
		vBullet.push_back(newBullet);
		return true;
	}
	

	return false;

}


void DrawMain(HDC hdc)
{
	HDC hMemDC;
	HBITMAP hOldBitmap;
	int bx, by;

	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hMain);

		bx = bitMain.bmWidth;
		by = bitMain.bmHeight;

		
		TransparentBlt(hdc, 50, 150, bx*1.3, by*1.3, hMemDC, 0, 0, bx, by, RGB(255, 0, 255));
		SelectObject(hMemDC, hOldBitmap); 
		DeleteDC(hMemDC);
	}


}

void DrawGameOver(HDC hdc)
{
	HDC hMemDC;
	HBITMAP hOldBitmap;
	int bx, by;

	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hGameOver);

		bx = bitGameOver.bmWidth;
		by = bitGameOver.bmHeight;


		TransparentBlt(hdc, 250, 250, bx, by, hMemDC, 0, 0, bx, by, RGB(255, 0, 255));
		SelectObject(hMemDC, hOldBitmap);
		DeleteDC(hMemDC);
	}

}

VOID CALLBACK KeyStateProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	string key;

	if (gameFlag == enum_InGame)
	{


		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			//wsprintf(sKeyState, TEXT("%s"), _T("W-Key"));
			key = "W";

			if (vTankBody[0] != NULL && vTankBody[0] != NULL)
			{
				vTankBody[0]->BlockTankCollisionCheck();
				vTankBody[0]->MoveTankBody(key);
				vTankHead[0]->MoveTankHead(key);


			}

		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			//wsprintf(sKeyState, TEXT("%s"), _T("S-Key"));
			key = "S";
			if (vTankBody[0] != NULL && vTankBody[0] != NULL)
			{

				vTankBody[0]->MoveTankBody(key);
				vTankHead[0]->MoveTankHead(key);

			}
		}



		if (GetAsyncKeyState(VK_UP) & 0x8000 && GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			//wsprintf(sKeyState, TEXT("%s"), _T("A-Key"));
			key = "WD";
			if (vTankBody[0] != NULL && vTankBody[0] != NULL)
			{

				vTankBody[0]->MoveTankBody(key);
				vTankHead[0]->MoveTankHead(key);

			}
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000 && GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			//wsprintf(sKeyState, TEXT("%s"), _T("D-Key"));
			key = "WA";
			if (vTankBody[0] != NULL && vTankBody[0] != NULL)
			{

				vTankBody[0]->MoveTankBody(key);
				vTankHead[0]->MoveTankHead(key);

			}
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000 && GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			//wsprintf(sKeyState, TEXT("%s"), _T("A-Key"));
			key = "SD";
			if (vTankBody[0] != NULL && vTankBody[0] != NULL)
			{

				vTankBody[0]->MoveTankBody(key);
				vTankHead[0]->MoveTankHead(key);

			}
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000 && GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			//wsprintf(sKeyState, TEXT("%s"), _T("D-Key"));
			key = "SA";
			if (vTankBody[0] != NULL && vTankBody[0] != NULL)
			{

				vTankBody[0]->MoveTankBody(key);
				vTankHead[0]->MoveTankHead(key);

			}

		}

		if (GetKeyState(VK_SPACE) & 0x8000)
		{
			if (vTankBody[0] != NULL && vTankBody[0] != NULL)
			{
				if (MakeBullet() == true)
				{
					vTankHead[0]->SetBulletCount();
				};
			}
		}
	}
	return VOID();
}