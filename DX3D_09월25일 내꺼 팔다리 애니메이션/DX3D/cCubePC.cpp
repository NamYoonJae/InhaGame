#include "stdafx.h"
#include "cCubePC.h"


cCubePC::cCubePC()
	//:m_Direction(0, 0, 1)
{
	D3DXMatrixIdentity(&m_matWorld);

}


cCubePC::~cCubePC()
{
}

void cCubePC::Setup(float x, float y, float z, float positionX, float positionY, float positionZ, float sX, float sY, float sZ)
{
	ST_PC_VERTEX v;
	scaleX = sX;
	scaleY = sY;
	scaleZ = sZ;

	//front
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-x + positionX, y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-x + positionX, -y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);


	v.p = D3DXVECTOR3(-x + positionX, -y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, -y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);

	//back
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-x + positionX, -y + positionY, z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, y + positionY, z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-x + positionX, y + positionY, z + positionZ);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-x + positionX, -y + positionY, z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, -y + positionY, z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, y + positionY, z + positionZ);
	m_vecVertex.push_back(v);

	//left
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-x + positionX, -y + positionY, z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-x + positionX, y + positionY, z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-x + positionX, y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-x + positionX, -y + positionY, z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-x + positionX, y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-x + positionX, -y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);


	//right
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(x + positionX, -y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, y + positionY, z + positionZ);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(x + positionX, -y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, y + positionY, z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, -y + positionY, z + positionZ);
	m_vecVertex.push_back(v);

	//top
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-x + positionX, y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-x + positionX, y + positionY, z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, y + positionY, z + positionZ);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-x + positionX, y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, y + positionY, z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);

	//bottom
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-x + positionX, -y + positionY, z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-x + positionX, -y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, -y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-x + positionX, -y + positionY, z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, -y + positionY, -z + positionZ);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(x + positionX, -y + positionY, z + positionZ);
	m_vecVertex.push_back(v);


}

void cCubePC::Update(D3DXVECTOR3 position, D3DXVECTOR3 direction, float rotationY)
{

	RECT rc;
	GetClientRect(g_hWnd, &rc);
	m_Direction = direction;
	D3DXMATRIXA16 matS, matR, matT, matRotationY;
	D3DXMatrixRotationY(&matRotationY, rotationY);
	//D3DXVec3TransformNormal(&m_Direction, &m_Direction, &matRotationY);


	//D3DXMatrixRotationY(&matR, m_fRotY);
	D3DXMatrixIdentity(&matR);
	//D3DXVec3TransformNormal(&direction, &direction, &matR);

	D3DXMatrixScaling(&matS, scaleX, scaleY, scaleZ);

	D3DXMatrixTranslation(&matT, position.x, position.y, position.z);

	//이동 * 크기 * 회전 * 이동
	m_matWorld =  matS * matRotationY * matT;


}

void cCubePC::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, false);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PC_VERTEX));
}

