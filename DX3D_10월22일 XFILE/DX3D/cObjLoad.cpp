#include "stdafx.h"
#include "cObjLoad.h"
#include "cMtlTex.h"
#include "cGroup.h"


cObjLoad::cObjLoad()
{
}


cObjLoad::~cObjLoad()
{
}

void cObjLoad::Load(OUT std::vector<cGroup*>& vecGroup, IN char * szFolder, IN char * szFile)
{
	vector<D3DXVECTOR3> vecV;
	vector<D3DXVECTOR2> vecVT;
	vector<D3DXVECTOR3> vecVN;
	vector<ST_PNT_VERTEX> vecVertex;

	string sFullPath(szFolder);
	sFullPath += (string("/") + string(szFile));

	FILE* fp;
	fopen_s(&fp, sFullPath.c_str(), "r");

	string sMtlName;
	while (true) 
	{
		if (feof(fp)) break;

		char szTemp[1024];
		fgets(szTemp, 1024, fp);

		if (szTemp[0] == '#')
		{
			continue;
		}
		else if (szTemp[0] == 'm')
		{
			char szMtlFile[1024];
			sscanf_s(szTemp, "%*s %s", szMtlFile, 1024);//%*s 애는 버리고 %s만 가져오겠다
			LoadMtlLib(szFolder, szMtlFile);
		}
		else if (szTemp[0] == 'g')
		{
			if (!vecVertex.empty())
			{
				cGroup* pGroup = new cGroup;
				pGroup->SetVertex(vecVertex);
				pGroup->SetMtlTex(m_mapMtlTex[sMtlName]);
				vecGroup.push_back(pGroup);
				vecVertex.clear();
			}
		}
		else if (szTemp[0] == 'v') 
		{
			if (szTemp[1] == ' ')
			{
				float x, y, z;
				sscanf_s(szTemp, "%*s %f %f %f", &x, &y, &z);
				vecV.push_back(D3DXVECTOR3(x, y, z));
			}
			else if (szTemp[1] == 't') 
			{
				float u, v;
				sscanf_s(szTemp, "%*s %f %f", &u, &v);
				vecVT.push_back(D3DXVECTOR2(u,v));
			}
			else if (szTemp[1] == 'n')
			{
				float x, y, z;
				sscanf_s(szTemp, "%*s %f %f %f", &x, &y, &z);
				vecVN.push_back(D3DXVECTOR3(x, y, z));
			}
		}
		else if (szTemp[0] == 'u') 
		{
			char szMtlName[1024];
			sscanf_s(szTemp, "%*s %s", szMtlName, 1024);
			sMtlName = string(szMtlName);
		}
		else if (szTemp[0] == 'f')
		{
			int nIndex[3][3];
			sscanf_s(szTemp, "%*s %d/%d/%d %d/%d/%d %d/%d/%d",
				&nIndex[0][0], &nIndex[0][1], &nIndex[0][2],
				&nIndex[1][0], &nIndex[1][1], &nIndex[1][2],
				&nIndex[2][0], &nIndex[2][1], &nIndex[2][2]
			);

			for (int i = 0; i < 3; ++i) 
			{
				ST_PNT_VERTEX v;
				v.p = vecV[nIndex[i][0] - 1];
				v.t = vecVT[nIndex[i][1] - 1];
				v.n = vecVN[nIndex[i][2] - 1];
				vecVertex.push_back(v);
			}
		}
	}
	fclose(fp);

	for each(auto it in m_mapMtlTex)
	{
		SafeRelease(it.second);
	}
	m_mapMtlTex.clear();

}

void cObjLoad::LoadMtlLib(char * szFolder, char * szFile)
{
	string sFullPath(szFolder);
	sFullPath += (string("/") + string(szFile));

	FILE *fp;
	fopen_s(&fp, sFullPath.c_str(), "r");

	string sMtlName;
	int nCnt = 0;
	while (true)
	{
		if (feof(fp)) break;

		char szTemp[1024];
		fgets(szTemp, 1024, fp);
		if (szTemp[0] == '#')
		{
			continue;
		}
		else if ((szTemp[0] == 'n'))
		{
			char szMtlName[1024];
			sscanf_s(szTemp, "%*s %s", szMtlName, 1024);
			sMtlName = string(szMtlName);
			if (m_mapMtlTex.find(sMtlName) == m_mapMtlTex.end())
			{
				m_mapMtlTex[sMtlName] = new cMtlTex;
				m_mapMtlTex[sMtlName]->SetAttrID(nCnt++);	//nCnt대신 맵사이즈로 해도 된다
			}
		}
		else if (szTemp[0] == 'K')
		{
			if (szTemp[1] == 'a')
			{
				float r, g, b;
				sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);
				m_mapMtlTex[sMtlName]->GetMaterial().Ambient.r = r;
				m_mapMtlTex[sMtlName]->GetMaterial().Ambient.g = g;
				m_mapMtlTex[sMtlName]->GetMaterial().Ambient.b = b;

				m_mapMtlTex[sMtlName]->GetMaterial().Ambient.a = 1.0f;
			}
			else if (szTemp[1] == 'd')
			{
				float r, g, b;
				sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);
				m_mapMtlTex[sMtlName]->GetMaterial().Diffuse.r = r;
				m_mapMtlTex[sMtlName]->GetMaterial().Diffuse.g = g;
				m_mapMtlTex[sMtlName]->GetMaterial().Diffuse.b = b;

				m_mapMtlTex[sMtlName]->GetMaterial().Diffuse.a = 1.0f;
			}
			else if (szTemp[1] == 's')
			{
				float r, g, b;
				sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);
				m_mapMtlTex[sMtlName]->GetMaterial().Specular.r = r;
				m_mapMtlTex[sMtlName]->GetMaterial().Specular.g = g;
				m_mapMtlTex[sMtlName]->GetMaterial().Specular.b = b;

				m_mapMtlTex[sMtlName]->GetMaterial().Specular.a = 1.0f;
			}

		}
		else if (szTemp[1] == 'd')
		{
			float d;
			sscanf_s(szTemp, "%*s %f", &d);
			m_mapMtlTex[sMtlName]->GetMaterial().Power = d;
		}


		else if (szTemp[0] == 'm')
		{
			char szTexFile[1024];
			sscanf_s(szTemp, "%*s %s", &szTexFile, 1024);
			sFullPath = string(szFolder);
			sFullPath += (string("/") + string(szTexFile));

			LPDIRECT3DTEXTURE9 pTexture = g_pTextureManager->GetTexture(sFullPath);
			m_mapMtlTex[sMtlName]->SetTexture(pTexture);
		}
		
	}
	fclose(fp);
}

void cObjLoad::LoadSurface(OUT vector<D3DXVECTOR3>& vecSurface, IN char * szFolder, IN char * szFile, IN D3DXMATRIXA16 * pmat)
{
	vector<D3DXVECTOR3> vecV;
	string sFullPath(szFolder);
	sFullPath += (string("/") + string(szFile));


	FILE* fp;
	fopen_s(&fp, sFullPath.c_str(), "r");

	string sMtlName;
	while (true)
	{
		if (feof(fp)) break;

		char szTemp[1024];
		fgets(szTemp, 1024, fp);

		if (szTemp[0] == '#')
		{
			continue;
		}
		else if (szTemp[0] == 'm')
		{

		}
		else if (szTemp[0] == 'g')
		{

		}
		else if (szTemp[0] == 'v')
		{
			if (szTemp[1] == ' ')
			{
				float x, y, z;
				sscanf_s(szTemp, "%*s %f %f %f", &x, &y, &z);
				vecV.push_back(D3DXVECTOR3(x, y, z));
			}
			else if (szTemp[1] == 't')
			{

			}
			else if (szTemp[1] == 'n')
			{

			}
		}
		else if (szTemp[0] == 'u')
		{

		}
		else if (szTemp[0] == 'f')
		{
			int nIndex[3];
			sscanf_s(szTemp, "%*s %d/%*d/%*d %d/%*d/%*d %d/%*d/%*d",
				&nIndex[0], &nIndex[1], &nIndex[2]);

			for (int i = 0; i < 3; ++i)
			{
				vecSurface.push_back(vecV[nIndex[i] - 1]);
			}
		}
	}
	fclose(fp);


	if (pmat)
	{
		for (size_t i = 0; i < vecSurface.size(); i++)
		{
			D3DXVec3TransformCoord(&vecSurface[i], &vecSurface[i], pmat);
		}
	}

}

LPD3DXMESH cObjLoad::LoadMesh(OUT vector<cMtlTex*>& vecMtlTex, IN char * szFolder, IN char * szFile)
{
	vector<DWORD> vecAttrBuf;
	vector<D3DXVECTOR3> vecV;
	vector<D3DXVECTOR2> vecVT;
	vector<D3DXVECTOR3> vecVN;
	vector<ST_PNT_VERTEX> vecVertex;

	string sFullPath(szFolder);
	sFullPath += (string("/") + string(szFile));

	FILE* fp;
	fopen_s(&fp, sFullPath.c_str(), "r");

	string sMtlName;
	while (true)
	{
		if (feof(fp)) break;

		char szTemp[1024];
		fgets(szTemp, 1024, fp);

		if (szTemp[0] == '#')
		{
			continue;
		}
		else if (szTemp[0] == 'm')
		{
			char szMtlFile[1024];
			sscanf_s(szTemp, "%*s %s", szMtlFile, 1024);//%*s 애는 버리고 %s만 가져오겠다
			LoadMtlLib(szFolder, szMtlFile);
		}
		else if (szTemp[0] == 'g')
		{
			/*
			if (!vecVertex.empty())
			{
				cGroup* pGroup = new cGroup;
				pGroup->SetVertex(vecVertex);
				pGroup->SetMtlTex(m_mapMtlTex[sMtlName]);
				vecGroup.push_back(pGroup);
				vecVertex.clear();
			}
			*/
		}
		else if (szTemp[0] == 'v')
		{
			if (szTemp[1] == ' ')
			{
				float x, y, z;
				sscanf_s(szTemp, "%*s %f %f %f", &x, &y, &z);
				vecV.push_back(D3DXVECTOR3(x, y, z));
			}
			else if (szTemp[1] == 't')
			{
				float u, v;
				sscanf_s(szTemp, "%*s %f %f", &u, &v);
				vecVT.push_back(D3DXVECTOR2(u, v));
			}
			else if (szTemp[1] == 'n')
			{
				float x, y, z;
				sscanf_s(szTemp, "%*s %f %f %f", &x, &y, &z);
				vecVN.push_back(D3DXVECTOR3(x, y, z));
			}
		}
		else if (szTemp[0] == 'u')
		{
			char szMtlName[1024];
			sscanf_s(szTemp, "%*s %s", szMtlName, 1024);
			sMtlName = string(szMtlName);
		}
		else if (szTemp[0] == 'f')
		{
			int nIndex[3][3];
			sscanf_s(szTemp, "%*s %d/%d/%d %d/%d/%d %d/%d/%d",
				&nIndex[0][0], &nIndex[0][1], &nIndex[0][2],
				&nIndex[1][0], &nIndex[1][1], &nIndex[1][2],
				&nIndex[2][0], &nIndex[2][1], &nIndex[2][2]
			);

			for (int i = 0; i < 3; ++i)
			{
				ST_PNT_VERTEX v;
				v.p = vecV[nIndex[i][0] - 1];
				v.t = vecVT[nIndex[i][1] - 1];
				v.n = vecVN[nIndex[i][2] - 1];
				vecVertex.push_back(v);
			}

			vecAttrBuf.push_back(m_mapMtlTex[sMtlName]->GetAttrID());	//속성값을 얻어와서 어트리뷰트에 넣어준다

		}
	}
	fclose(fp);

	//==================================================

	vecMtlTex.resize(m_mapMtlTex.size());

	for each(auto it in m_mapMtlTex)
	{
		vecMtlTex[it.second->GetAttrID()] = it.second;
	}
	
	LPD3DXMESH pMesh = NULL;
	D3DXCreateMeshFVF(vecAttrBuf.size(), vecVertex.size(), D3DXMESH_MANAGED, ST_PNT_VERTEX::FVF, g_pD3DDevice, &pMesh);

	ST_PNT_VERTEX * pV = NULL;
	pMesh->LockVertexBuffer(0, (LPVOID*)&pV);
	memcpy(pV, &vecVertex[0], vecVertex.size() * sizeof(ST_PNT_VERTEX));
	pMesh->UnlockVertexBuffer();

	WORD* pI = NULL;
	pMesh->LockIndexBuffer(0, (LPVOID*)&pI);
	for (int i = 0; i < vecVertex.size(); ++i)
		pI[i] = i;
	pMesh->UnlockIndexBuffer();

	DWORD* pA = NULL;
	pMesh->LockAttributeBuffer(0, &pA);
	memcpy(pA, &vecAttrBuf[0], vecAttrBuf.size() * sizeof(DWORD));
	pMesh->UnlockVertexBuffer();

	vector<DWORD> vecAdj(vecVertex.size());
	pMesh->GenerateAdjacency(0.0f, &vecAdj[0]);

	pMesh->OptimizeInplace(D3DXMESHOPT_ATTRSORT | D3DXMESHOPT_COMPACT | D3DXMESHOPT_VERTEXCACHE, &vecAdj[0], 0, 0, 0);

	m_mapMtlTex.clear();

	return pMesh;
}
