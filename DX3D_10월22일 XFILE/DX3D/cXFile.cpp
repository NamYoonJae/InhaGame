#include "stdafx.h"
#include "cXFile.h"


cXFile::cXFile()
{
	
}


cXFile::~cXFile()
{
	SafeRelease(m_Mesh);
	SafeRelease(m_pAdjBuffer);
	SafeRelease(m_pMtrlBuffer);
}

void cXFile::Setup()
{
	HRESULT hr = 0;

	//hr = D3DXLoadMeshFromX(_T("bigship1.x"), D3DXMESH_MANAGED, g_pD3DDevice, &adjBuffer, &mtrlBuffer, 0, &numMtrls, &Mesh);
	hr = D3DXLoadMeshFromX(_T("Zealot/zealot.x"), D3DXMESH_MANAGED, g_pD3DDevice, &m_pAdjBuffer, &m_pMtrlBuffer, 0, &numMtrls, &m_Mesh);
	if (m_pMtrlBuffer != 0 && numMtrls != 0)
	{
		D3DXMATERIAL* mtrls = (D3DXMATERIAL*)m_pMtrlBuffer->GetBufferPointer();
	
		for (int i = 0; i < numMtrls; i++) 
		{
			mtrls[i].MatD3D.Ambient = mtrls[i].MatD3D.Diffuse;
			m_vecMtrls.push_back(mtrls[i].MatD3D);
			if (mtrls[i].pTextureFilename != 0) 
			{
				IDirect3DTexture9* tex = 0;
				//D3DXCreateTextureFromFileA(g_pD3DDevice, mtrls[i].pTextureFilename, &tex);
				D3DXCreateTextureFromFile(g_pD3DDevice,L"Zealot/Zealot_Diffuse.bmp", &tex);
				m_Textures.push_back(tex);
			}
			else
			{
				m_Textures.push_back(0);
			}

		}
		SafeRelease(m_pMtrlBuffer);
	}

}

void cXFile::Render()
{
	if (g_pD3DDevice)
	{
		
		static float y = 0.0f;
		D3DXMATRIX matR, matWorld;
		D3DXMatrixIdentity(&matR);
		D3DXMatrixIdentity(&matWorld);

		D3DXMatrixRotationY(&matR, y);
		y += 0.02f;

		if (y >= 6.28f)
			y = 0.0f;

		matWorld = matR;
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);


		for (int i = 0; i < m_vecMtrls.size(); i++)
		{
			g_pD3DDevice->SetMaterial(&m_vecMtrls[i]);
			g_pD3DDevice->SetTexture(0, m_Textures[i]);
			m_Mesh->DrawSubset(i);
		}
	}
}