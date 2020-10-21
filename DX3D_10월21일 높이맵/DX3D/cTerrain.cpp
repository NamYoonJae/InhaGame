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
	v.n = D3DXVECTOR3(0, 1, 0);
	
	for (float j = 0; j < 256; j++)
	{
		for (float i = 0; i < 256; i++)
		{
			int k = 257 * j + i;

			v = m_vecVertex[k];
			m_vecTriangleVertex.push_back(v);

			v= m_vecVertex[k + 1];
			m_vecTriangleVertex.push_back(v);

			v= m_vecVertex[k + 257];
			m_vecTriangleVertex.push_back(v);





			v = m_vecVertex[k + 1];
			m_vecTriangleVertex.push_back(v);

			v = m_vecVertex[k + 258];
			m_vecTriangleVertex.push_back(v);

			v = m_vecVertex[k + 257];
			m_vecTriangleVertex.push_back(v);
		}
	}




}

void cTerrain::Render_Terrian()
{
	g_pD3DDevice->SetTexture(0, m_pTexture);
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, false);
	D3DXMATRIXA16 matI;
	D3DXMatrixIdentity(&matI);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matI);
	g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecTriangleVertex.size() / 3, &m_vecTriangleVertex[0], sizeof(ST_PNT_VERTEX));
}

void cTerrain::SetMap()
{
	FILE* fp;
	fopen_s(&fp, "HeightMapData/HeightMap.raw", "rb");
	D3DXCreateTextureFromFile(g_pD3DDevice, _T("HeightMapData/terrain.jpg"), &m_pTexture);

	while (true) 
	{
		if (feof(fp)) break;
		ST_PNT_VERTEX hV;
		for (float i = 257; i > 0; i--) 
		{
			for (float j = 0; j < 257; j++) 
			{
				hV.p.x = j;
				hV.p.y = fgetc(fp) / 10 - 10;
				hV.p.z = i;
				hV.t = D3DXVECTOR2(j / 257, i / 257);
				hV.n = D3DXVECTOR3(0, 1, 0);
				m_vecVertex.push_back(hV);
			}
		}

	}
	

}
