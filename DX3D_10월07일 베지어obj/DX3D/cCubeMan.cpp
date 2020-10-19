#include "stdafx.h"

#include "cBody.h"
#include "cHead.h"
#include "cLeftArm.h"
#include "cRightArm.h"
#include "cLeftLeg.h"
#include "cRightLeg.h"

#include "cCubeMan.h"
#include "bezier.h"


cCubeMan::cCubeMan()
	:m_pRoot(NULL)
{
	lineNum = 0;
}

cCubeMan::~cCubeMan()
{
	if (m_pRoot)
		m_pRoot->Destroy();
}

void cCubeMan::Setup()
{
	cCharacter::Setup();

	ZeroMemory(&m_stMtl, sizeof(D3DMATERIAL9));
	m_stMtl.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);	//주변 반영
	m_stMtl.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);	//분산 반영
	m_stMtl.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);	//반사 반영
	//m_stMtl.Emissive = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);	//방출
	//m_stMtl.Power 에서 설정한 값은 반사효과가 얼마나 예리한지 제어한다

	cBody* pBody = new cBody;
	pBody->Setup();
	pBody->SetParentWorldTM(&m_matWorld);
	m_pRoot = pBody;

	cHead* pHead = new cHead;
	pHead->Setup();
	m_pRoot->Addchild(pHead);

	cLeftArm* pLArm = new cLeftArm;
	pLArm->Setup();
	pLArm->SetRotDeltaX(0.1f);
	m_pRoot->Addchild(pLArm);

	cRightArm* pRArm = new cRightArm;
	pRArm->Setup();
	pRArm->SetRotDeltaX(-0.1f);
	m_pRoot->Addchild(pRArm);

	cLeftLeg* pLLeg = new cLeftLeg;
	pLLeg->Setup();
	pLLeg->SetRotDeltaX(-0.1f);
	m_pRoot->Addchild(pLLeg);

	cRightLeg* pRLeg = new cRightLeg;
	pRLeg->Setup();
	pRLeg->SetRotDeltaX(0.1f);
	m_pRoot->Addchild(pRLeg);
}

void cCubeMan::bezierSetup(vector<ST_PC_VERTEX> colorLine)
{
	cCharacter::Setup();

	greenLine = colorLine;

	m_vDirection = greenLine[0].p - m_vPosition;

	ZeroMemory(&m_stMtl, sizeof(D3DMATERIAL9));
	m_stMtl.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);	//주변 반영
	m_stMtl.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);	//분산 반영
	m_stMtl.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);	//반사 반영
															//m_stMtl.Emissive = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);	//방출
															//m_stMtl.Power 에서 설정한 값은 반사효과가 얼마나 예리한지 제어한다

	cBody* pBody = new cBody;
	pBody->Setup();
	pBody->SetParentWorldTM(&m_matWorld);
	m_pRoot = pBody;

	cHead* pHead = new cHead;
	pHead->Setup();
	m_pRoot->Addchild(pHead);

	cLeftArm* pLArm = new cLeftArm;
	pLArm->Setup();
	pLArm->SetRotDeltaX(0.1f);
	m_pRoot->Addchild(pLArm);

	cRightArm* pRArm = new cRightArm;
	pRArm->Setup();
	pRArm->SetRotDeltaX(-0.1f);
	m_pRoot->Addchild(pRArm);

	cLeftLeg* pLLeg = new cLeftLeg;
	pLLeg->Setup();
	pLLeg->SetRotDeltaX(-0.1f);
	m_pRoot->Addchild(pLLeg);

	cRightLeg* pRLeg = new cRightLeg;
	pRLeg->Setup();
	pRLeg->SetRotDeltaX(0.1f);
	m_pRoot->Addchild(pRLeg);
}

void cCubeMan::Update()
{
	cCharacter::Update();
	if (m_pRoot)
		m_pRoot->Update();
}

void cCubeMan::Update2()
{

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matR, matT;

	
	

	if (greenLine[lineNum].p.x - 0.01f <= m_vPosition.x && m_vPosition.x <= greenLine[lineNum].p.x + 0.01f &&
		greenLine[lineNum].p.z - 0.01f <= m_vPosition.z && m_vPosition.z <= greenLine[lineNum].p.z + 0.01f)
	{
		lineNum++;
		D3DXVECTOR3 dir(0.0f, 0.0f, 0.0f);
		D3DXVECTOR3 nextdir(0.0f, 0.0f, 0.0f);

		//nextdir = greenLine[lineNum].p - greenLine[lineNum - 1].p;
		dir = greenLine[lineNum].p - m_vPosition;//목표지점을 향한 방향벡터
		//D3DXVec3Normalize(&dir, &dir);
		//D3DXVec3Normalize(&nextdir, &nextdir);
		m_vDirection = dir;

		float angle = abs(acosf(D3DXVec3Dot(&dir, &nextdir)));
		m_fRotY += angle;

		/*
		D3DXVECTOR3 vUp(0, 1, 0);
		D3DXVECTOR3 vAt(1, 0, 5);
		D3DXMatrixIdentity(&matR);
		D3DXMATRIXA16 temp;
		D3DXMatrixIdentity(&temp);
		D3DXMatrixLookAtLH(&temp, &vAt, &(greenLine[lineNum].p - m_vPosition), &vUp);
		D3DXMatrixLookAtLH(&temp, &m_vPosition, &vAt, &vUp);
		D3DXMatrixTranspose(&temp, &temp);
		D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &temp);
		*/

	}
	m_vPosition += (m_vDirection * 0.005f);
	D3DXMatrixRotationY(&matR,m_fRotY);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_matWorld = matR * matT;


	if (m_pRoot)
		m_pRoot->Update();
}

void cCubeMan::Render()
{

	if (g_pD3DDevice) 
	{
		g_pD3DDevice->SetTexture(0, m_pTexture);
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		g_pD3DDevice->SetMaterial(&m_stMtl);

		cCharacter::Render();

		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		if (m_pRoot)
			m_pRoot->Render();
		g_pD3DDevice->SetTexture(0, NULL);
	}
}