#include "stdafx.h"
#include "cButton.h"


cButton::cButton()
{
	m_state = enum_ButtonOff;
}


cButton::~cButton()
{
}

void cButton::Setup(char * szFolder, char * szFileName)
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
}

void cButton::Update()
{

}

void cButton::Render()
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
}

void cButton::Render(float positionX, float positionY)
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	RECT rc;
	SetRect(&rc, 0, 0, m_stImageInfo.Width, m_stImageInfo.Height);
	D3DXMATRIXA16 matT, matS, matWorld;
	D3DXMatrixIdentity(&matT);
	D3DXMatrixIdentity(&matS);
	D3DXMatrixIdentity(&matWorld);

	D3DXMatrixTranslation(&matT, 20, 20, 0);
	m_pSprite->Draw(m_pTextureUI, &rc, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(positionX, positionY, 0), D3DCOLOR_ARGB(255, 255, 255, 255));

	matWorld = matS * matT;

	m_pSprite->End();
}

int cButton::GetButtonState()
{
	return m_state;
}

void cButton::ButtonStateChange(int state)
{
	m_state = state;
}
