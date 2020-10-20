#include "stdafx.h"
#include "cSphere.h"

cSphere::cSphere()
	:m_pMeshSphere(NULL)
	,center(0, 0, 0)
{
	picked = false;
}


cSphere::~cSphere()
{
	SafeRelease(m_pMeshSphere);
}

void cSphere::Setup(float centerZ)
{
	radius = 0.5;
	D3DXCreateSphere(g_pD3DDevice, radius, 10, 10, &m_pMeshSphere, NULL);

	ZeroMemory(&m_stMtlSphere, sizeof(D3DMATERIAL9));
	m_stMtlSphere.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlSphere.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlSphere.Specular = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);

	center.z = centerZ;
}

void cSphere::Update()
{
	if (picked == false)
	{
		ZeroMemory(&m_stMtlSphere, sizeof(D3DMATERIAL9));
		m_stMtlSphere.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
		m_stMtlSphere.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
		m_stMtlSphere.Specular = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	}
	else if (picked == true)
	{
		ZeroMemory(&m_stMtlSphere, sizeof(D3DMATERIAL9));
		m_stMtlSphere.Ambient = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		m_stMtlSphere.Diffuse = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		m_stMtlSphere.Specular = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	}
}

void cSphere::Render()
{
	_D3DXMATRIXA16 matWorld, matS, matR;
	
		D3DXMatrixIdentity(&matS);
		D3DXMatrixIdentity(&matR);
		matWorld = matS * matR;
		D3DXMatrixTranslation(&matWorld, 0, 0, center.z);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		g_pD3DDevice->SetMaterial(&m_stMtlSphere);
		m_pMeshSphere->DrawSubset(0);

}
