#include "stdafx.h"
#include "cCharacter.h"
#include "cCubePC.h"

cCharacter::cCharacter()
	:m_Direction(0, 0, 1)
	,m_vPosition(0, 0, 0)
	,m_fRotY(0.0f)
	,m_pHead(NULL)
	,m_pBody(NULL)
	,m_ArmRight(NULL)
	,m_ArmLeft(NULL)
	,m_LegRight(NULL)
	,m_LegLeft(NULL)
{
	D3DXMatrixIdentity(&m_matWorld);
	
}


cCharacter::~cCharacter()
{
	SafeDelete(m_pHead);
	SafeDelete(m_pBody);
	SafeDelete(m_ArmRight);
	SafeDelete(m_ArmLeft);
	SafeDelete(m_LegRight);
	SafeDelete(m_LegLeft);
}

void cCharacter::Setup()
{
	
	m_pHead = new cCubePC();
	vecCube.push_back(m_pHead);
	m_pHead->Setup(1.0f, 1.0f, 1.0f, 0, 9, 0 , 0.5, 0.5, 0.5);

	
	m_pBody = new cCubePC;
	vecCube.push_back(m_pBody);
	m_pBody->Setup(1.0f, 1.0f, 1.0f, 0, 3, 0, 1, 1, 0.5);
	
	
	m_ArmRight = new cCubePC;
	vecCube.push_back(m_ArmRight);
	m_ArmRight->Setup(1.0f, 1.0f, 1.0f, 3, 3, 0, 0.5, 1.0, 0.5);
	
	
	m_ArmLeft = new cCubePC;
	vecCube.push_back(m_ArmLeft);
	m_ArmLeft->Setup(1.0f, 1.0f, 1.0f, -3, 3, 0, 0.5, 1.0, 0.5);
	

	
	m_LegRight = new cCubePC;
	vecCube.push_back(m_LegRight);
	m_LegRight->Setup(1.0f, 1.0f, 1.0f, 1, 1, 0, 0.5, 1.0, 0.5);
	
	
	m_LegLeft = new cCubePC;
	vecCube.push_back(m_LegLeft);
	m_LegLeft->Setup(1.0f, 1.0f, 1.0f, -1, 1, 0, 0.5, 1.0, 0.5);
	


}

void cCharacter::Update()
{
	if (GetKeyState('A') & 0x8000)
	{
		m_fRotY -= 0.1f;
	}
	if (GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.1f;
	}
	if (GetKeyState('W') & 0x8000)
	{
		m_vPosition += (m_Direction * 0.1f);
	}
	if (GetKeyState('S') & 0x8000)
	{
		m_vPosition -= (m_Direction * 0.1f);
	}

	D3DXMatrixRotationY(&matR, m_fRotY);
	D3DXVec3TransformNormal(&m_Direction, &m_Direction, &matR);

	for (int i = 0; i < vecCube.size(); i++)
	{
		vecCube[i]->Update(m_vPosition, m_Direction, m_fRotY);
	}

}

void cCharacter::Render()
{

	for (int i = 0; i < vecCube.size(); i++)
	{
		vecCube[i]->Render();
	}

}


D3DXVECTOR3& cCharacter::GetPosition()
{
	return m_vPosition;
}
