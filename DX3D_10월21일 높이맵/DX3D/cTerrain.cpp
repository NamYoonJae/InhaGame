#include "stdafx.h"
#include "cTerrain.h"


cTerrain::cTerrain()
	:m_pTexture(NULL)
{
}


cTerrain::~cTerrain()
{
	SafeRelease(m_pTexture);
}

void cTerrain::Setup_Terrian()
{
	//높이값 셋팅
	SetMap();



	//m_vecVertex
	//그리드 그리기
	/*
	ST_PNT_VERTEX v;
	for (float j = 0; j < 256; j++)
	{
		for (float i = 0; i < 256; i++)
		{
			v.p = D3DXVECTOR3(j + 1, 0, i);
			v.t = D3DXVECTOR2((j+1) / 256, i / 256);
			v.n = D3DXVECTOR3(0, 1, 0);
			m_vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j, 0, i);
			v.t = D3DXVECTOR2(j / 256, i / 256);
			v.n = D3DXVECTOR3(0, 1, 0);
			m_vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j, 0, i + 1);
			v.t = D3DXVECTOR2(j / 256, (i + 1) / 256);
			v.n = D3DXVECTOR3(0, 1, 0);
			m_vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j + 1, 0, i);
			v.t = D3DXVECTOR2((j + 1) / 256, i / 256);
			v.n = D3DXVECTOR3(0, 1, 0);
			m_vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j, 0, i + 1);
			v.t = D3DXVECTOR2(j / 256, (i +1) / 256);
			v.n = D3DXVECTOR3(0, 1, 0);
			m_vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j + 1, 0, i + 1);
			v.t = D3DXVECTOR2((j + 1) / 256, (i + 1) / 256);
			v.n = D3DXVECTOR3(0, 1, 0);
			m_vecVertex.push_back(v);
		}
	}
	*/

	ST_PNT_VERTEX v;
	for (float j = 0; j < 256; j++)
	{
		for (float i = 0; i < 256; i++)
		{
			v.p = D3DXVECTOR3(j + 1, 0, i);
			v.n = D3DXVECTOR3(0, 1, 0);
			m_vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j, 0, i);
			v.n = D3DXVECTOR3(0, 1, 0);
			m_vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j, 0, i + 1);
			v.n = D3DXVECTOR3(0, 1, 0);
			m_vecVertex.push_back(v);



			v.p = D3DXVECTOR3(j + 1, 0, i);
			v.n = D3DXVECTOR3(0, 1, 0);
			m_vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j, 0, i + 1);
			v.n = D3DXVECTOR3(0, 1, 0);
			m_vecVertex.push_back(v);

			v.p = D3DXVECTOR3(j + 1, 0, i + 1);
			v.n = D3DXVECTOR3(0, 1, 0);
			m_vecVertex.push_back(v);
		}
	}




}

void cTerrain::Render_Terrian()
{
	g_pD3DDevice->SetTexture(0, m_pTexture);
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	D3DXMATRIXA16 matI;
	D3DXMatrixIdentity(&matI);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matI);
	g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecTriangleVertex.size() / 3, &m_vecTriangleVertex[0], sizeof(ST_PNT_VERTEX));
}

void cTerrain::SetMap()
{
	FILE* fp;
	fopen_s(&fp, "HeightMapData/HeightMap.raw", "r");
	D3DXCreateTextureFromFile(g_pD3DDevice, _T("HeightMapData/terrain.jpg"), &m_pTexture);
	while (true) 
	{
		if (feof(fp)) break;
		ST_PNT_VERTEX hV;
		for (float i = 0; i < 256; i++) 
		{
			for (float j = 0; j < 256; j++) 
			{
				hV.p.x = j / 256;
				hV.p.y = fgetc(fp);
				hV.p.z = i / 256;
				hV.t = D3DXVECTOR2(hV.p.x, hV.p.z);
				hV.n = D3DXVECTOR3(0, 1, 0);
				m_vecVertex.push_back(hV);
			}
		}

	}
	

}
