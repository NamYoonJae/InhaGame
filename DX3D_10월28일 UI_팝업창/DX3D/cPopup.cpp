#include "stdafx.h"
#include "cPopup.h"
#include "cButton.h"

cPopup::cPopup()
	:m_pFont(NULL)
	,m_pButton(NULL)
	,m_pButton_Yes(NULL)
	,m_pButton_No(NULL)
	,m_pButton_On(NULL)
	,m_pButton_Hold(NULL)
{
	m_isLButtonDown = false;
}


cPopup::~cPopup()
{
	SafeRelease(m_pFont);

	SafeDelete(m_pButton);
	SafeDelete(m_pButton_Yes);
	SafeDelete(m_pButton_No);
	SafeDelete(m_pButton_On);
	SafeDelete(m_pButton_Hold);

}

void cPopup::Setup(char* szFolder, char* szFileName)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	string sFullPath(szFolder);
	sFullPath = sFullPath + string("/") + string(szFileName);

	D3DXCreateTextureFromFileExA(g_pD3DDevice,
		sFullPath.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_DEFAULT,
		0,
		&m_stImageInfo,
		NULL,
		&m_pTextureUI);

	FontCreate();
	m_pButton = new cButton;
	m_pButton->Setup("UI", "btn-main-menu.png");



	m_pButton_Yes = new cButton;
	m_pButton_Yes->Setup("UI", "btn-med-up.png");



	m_pButton_No = new cButton;
	m_pButton_No->Setup("UI", "btn-med-up.png");



	m_pButton_On = new cButton;
	m_pButton_On->Setup("UI", "btn-med-over.png");

	m_pButton_Hold = new cButton;
	m_pButton_Hold->Setup("UI", "btn-med-down.png");


}

void cPopup::Update()
{
}

void cPopup::Render()
{

	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	RECT rc;
	SetRect(&rc, 0, 0, m_stImageInfo.Width, m_stImageInfo.Height);
	D3DXMATRIXA16 matT, matS, matWorld;
	D3DXMatrixIdentity(&matT);
	D3DXMatrixIdentity(&matS);
	D3DXMatrixIdentity(&matWorld);

	D3DXMatrixTranslation(&matT, 20, 20, 0);
	m_pSprite->Draw(m_pTextureUI, &rc, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 0), D3DCOLOR_ARGB(255, 255, 255, 255));

	matWorld = matS * matT;
	
	m_pSprite->End();

	
	if (m_pButton)
		m_pButton->Render(390, 80);



	if (m_pButton_Yes) 
	{
		if (m_pButton_Yes->GetButtonState() == enum_ButtonOff)
		{
			m_pButton_Yes->Render(140, 300);
		}
		else if (m_pButton_Yes->GetButtonState() == enum_ButtonOn)
		{
			m_pButton_On->Render(140, 300);
		}
		else if (m_pButton_Yes->GetButtonState() == enum_ButtonHold)
		{
			m_pButton_Hold->Render(140, 300);
		}
	}


	if (m_pButton_No)
	{
		if (m_pButton_No->GetButtonState() == enum_ButtonOff)
		{
			m_pButton_No->Render(140, 370);
		}
		else if (m_pButton_No->GetButtonState() == enum_ButtonOn)
		{
			m_pButton_On->Render(140, 370);
		}
		else if (m_pButton_No->GetButtonState() == enum_ButtonHold)
		{
			m_pButton_Hold->Render(140, 370);
		}
	}
		


	Text_Render();
}



void cPopup::FontCreate()
{
	D3DXFONT_DESC fd;
	ZeroMemory(&fd, sizeof(D3DXFONT_DESC));
	fd.Height = 50;
	fd.Width = 25;
	fd.Weight = FW_MEDIUM;
	fd.Italic = false;
	fd.CharSet = DEFAULT_CHARSET;
	fd.OutputPrecision = OUT_DEFAULT_PRECIS;
	fd.PitchAndFamily = FF_DONTCARE;

	//lstrcpy(fd.FaceName, L"굴림체");
	wcscpy_s(fd.FaceName, L"굴림체");

	D3DXCreateFontIndirect(g_pD3DDevice, &fd, &m_pFont);
}

void cPopup::Text_Render()
{
	string sText("인하대 후문에 COVID19 \n 환자 발생.. 도망쳐~~");
	RECT rc;
	SetRect(&rc, 120, 180, 301, 200);

	LPD3DXFONT pFont = g_pFontManager->GetFont(cFontManager::E_DEFAULT);	//E_QUEST일 때와 E_DEFAULT일 때
	pFont->DrawTextA(NULL,
		sText.c_str(),
		sText.length(),
		&rc,
		DT_LEFT | DT_TOP | DT_NOCLIP,
		D3DCOLOR_XRGB(255, 255, 0));
}

void cPopup::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int x = 0;
	int y = 0;
	switch (message)
	{
		case WM_MOUSEMOVE:
		{
			POINT ptCurMouse;
			ptCurMouse.x = LOWORD(lParam);
			ptCurMouse.y = HIWORD(lParam);

			if (153 <= ptCurMouse.x && ptCurMouse.x <= 385)
			{
				if (312 <= ptCurMouse.y && ptCurMouse.y <= 348)
				{
					m_pButton_Yes->ButtonStateChange(enum_ButtonOn);
				}
				else
				{
					m_pButton_Yes->ButtonStateChange(enum_ButtonOff);
				}
			}
			else
			{

				m_pButton_Yes->ButtonStateChange(enum_ButtonOff);

			}

			if (153 <= ptCurMouse.x && ptCurMouse.x <= 385)
			{
				if (384 <= ptCurMouse.y && ptCurMouse.y <= 422)
				{
					m_pButton_No->ButtonStateChange(enum_ButtonOn);
				}
				else 
				{
					m_pButton_No->ButtonStateChange(enum_ButtonOff);
				}
			}
			else
			{
				{
					m_pButton_No->ButtonStateChange(enum_ButtonOff);
				}

			}

			
			//
			float moveX = ptCurMouse.x - m_ptPrevMouse.x;
			float moveY = ptCurMouse.y - m_ptPrevMouse.y;

			m_ptPrevMouse.x += moveX;
			m_ptPrevMouse.y += moveY;



			break;
		}

		case WM_LBUTTONDOWN:
			m_ptPrevMouse.x = LOWORD(lParam);
			m_ptPrevMouse.y = HIWORD(lParam);
			m_isLButtonDown = true;

			cout << "x : " << m_ptPrevMouse.x << endl;
			cout << "y : " << m_ptPrevMouse.y << endl;

			

			if (153 <= m_ptPrevMouse.x && m_ptPrevMouse.x <= 385)
			{
				if (312 <= m_ptPrevMouse.y && m_ptPrevMouse.y <= 348)
				{
					m_pButton_Yes->ButtonStateChange(enum_ButtonHold);
				}
			}

			if (153 <= m_ptPrevMouse.x && m_ptPrevMouse.x <= 385)
			{
				if (384 <= m_ptPrevMouse.y && m_ptPrevMouse.y <= 422)
				{
					m_pButton_No->ButtonStateChange(enum_ButtonHold);
				}
			}

			break;


		case WM_LBUTTONUP:
			x = LOWORD(lParam);
			y = HIWORD(lParam);

			m_isLButtonDown = false;

			if (153 <= x && x <= 385)
			{
				if (312 <= y && y <= 348)
				{
					m_pButton_Yes->ButtonStateChange(enum_ButtonOn);

				}
			}

			if (153 <= x && x <= 385)
			{
				if (384 <= y && y <= 422)
				{
					m_pButton_No->ButtonStateChange(enum_ButtonOn);
				}
			}
			break;
		}
}
