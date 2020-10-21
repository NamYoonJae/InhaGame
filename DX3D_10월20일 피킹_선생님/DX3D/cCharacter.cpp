#include "stdafx.h"
#include "cCharacter.h"

cCharacter::cCharacter()
    :m_fRotY(0.0f)
    ,m_vDirection(0,0,1)
    ,m_vPosition(0,0,0)
	,m_pTexture(NULL)
{
    D3DXMatrixIdentity(&m_matWorld);
}

cCharacter::~cCharacter()
{
	SafeRelease(m_pTexture);
}

void cCharacter::Setup()
{
	D3DXCreateTextureFromFile(g_pD3DDevice, L"../image/charater01.png", &m_pTexture);
}

void cCharacter::Update(iMap* pMap)
{
	m_pMap = pMap;

	if (GetKeyState('A') & 0x8000)
	{
		m_fRotY -= 0.1f;
	}
	if (GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.1f;
	}

	D3DXVECTOR3 vPosition = m_vPosition;

	if (GetKeyState('W') & 0x8000)
	{
		vPosition = vPosition -(m_vDirection * 0.5f);

	}
	if (GetKeyState('S') & 0x8000)
	{
		vPosition = m_vPosition + (m_vDirection * 0.5f);
	}




	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);

	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	float tempY = vPosition.y;
	if (pMap)
	{
		if (pMap->GetHeight(vPosition.x, vPosition.y, vPosition.z))
		{
			//tempY ���� ��ǥ
			//vPosition.y ���ο� ������
			
			if (vPosition.y - tempY < 5 ) 
			{
				m_vPosition = vPosition;
			}
			
			
		}
	}



	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y + 0.9f, m_vPosition.z);

	m_matWorld = matR * matT;
}

void cCharacter::Render()
{

}

D3DXVECTOR3& cCharacter::GetPosition()
{

	return m_vPosition;

}
