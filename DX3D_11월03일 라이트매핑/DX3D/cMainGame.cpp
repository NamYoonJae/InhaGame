#include "stdafx.h"
#include "cMainGame.h"
#include "cDeviceManage.h"
#include "cCamera.h"
#include "cCubePC.h"
#include "cGrid.h"
#include "cCubeMan.h"
#include "cLight.h"

#include "cObjLoad.h"
#include "cGroup.h"
#include "cObjMap.h"
#include "cAseLoader.h"
#include "cFrame.h"
#include "cRay.h"
#include "cHeightMap.h"
#include "cSkinnedMesh.h"
#include "cFrustum.h"
#include "cZealot.h"
#include "cOBB.h"
#include "cPopup.h"

DWORD FtoDw(float f)
{
	return *((DWORD*)&f);
}

bool cMainGame::LoadAssets()
{
	// 텍스처 로딩

	// 쉐이더 로딩
	m_pShader = LoadShader("Shader/SpecularMapping.fx");
	m_pTexture = LoadTexture("Zealot/Zealot_Diffuse.bmp");
	m_pSpecularTexture = LoadTexture("Earth.jpg");
	if (!m_pShader) return false;


	return true;
}

LPD3DXEFFECT cMainGame::LoadShader(const char * filename)
{
	LPD3DXEFFECT ret = NULL;

	LPD3DXBUFFER pError = NULL;
	DWORD dwShaderFlags = 0;

#if _DEBUG
	dwShaderFlags |= D3DXSHADER_DEBUG;
#endif

	D3DXCreateEffectFromFileA(g_pD3DDevice, filename,
		NULL, NULL, dwShaderFlags, NULL, &ret, &pError);

	// 쉐이더 로딩에 실패한 경우 output창에 쉐이더
	// 컴파일 에러를 출력한다.
	/*
	if (!ret && pError)
	{
		int size = pError->GetBufferSize();
		void *ack = pError->GetBufferPointer();

		if (ack)
		{
			char* str = new char[size];
			sprintf(str, (const char*)ack, size);
			OutputDebugStringA(str);
			delete[] str;
		}
	}
	*/
	return ret;
}

LPDIRECT3DTEXTURE9 cMainGame::LoadTexture(const char * filename)
{
	LPDIRECT3DTEXTURE9 ret = NULL;
	if (FAILED(D3DXCreateTextureFromFileA(g_pD3DDevice, filename, &ret)))
	{
		cout << "텍스쳐로딩 실패" << endl;
		OutputDebugStringA("텍스처 로딩 실패: ");
		OutputDebugStringA(filename);
		OutputDebugStringA("\n");
	}

	return ret;
}


cMainGame::cMainGame()
	:m_pCubePC(NULL)
	,m_pCamera(NULL)
	,m_pGrid(NULL)
	,m_pCubeMan(NULL)
	//,m_pTexture(NULL)
	,m_pMap(NULL)
	,m_pRootFrame(NULL)
	,m_pMeshTeapot(NULL)
	,m_pMeshSphere(NULL)
	,m_pObjMesh(NULL)
	,m_pSkinnedMesh(NULL)
	,m_pFrustum(NULL)
	,m_pHoldZealot(NULL)
	,m_pMoveZealot(NULL)
	,m_pFont(NULL)
	,m_p3DText(NULL)
	,m_pSprite(NULL)
	,m_pTextureUI(NULL)
	,m_pPopup(NULL)
	,m_pTex0(NULL)
	,m_pTex1(NULL)
	,m_pTex2(NULL)
	,m_pTex3(NULL)
	, m_nType(-1)
	, m_pShader(NULL)
{
	m_PopupState = 0;
}


cMainGame::~cMainGame()
{
	SafeDelete(m_pCubePC);
	SafeDelete(m_pCamera);
	SafeDelete(m_pGrid);
	SafeDelete(m_pCubeMan);
	SafeDelete(m_pMap);
	SafeDelete(m_pSkinnedMesh);
	SafeDelete(m_pFrustum);
	SafeDelete(m_pHoldZealot);
	SafeDelete(m_pMoveZealot);
	SafeDelete(m_pPopup);

	//SafeRelease(m_pTexture);
	SafeRelease(m_pMeshTeapot);
	SafeRelease(m_pMeshSphere);
	SafeRelease(m_pObjMesh);
	SafeRelease(m_pFont);
	SafeRelease(m_p3DText);
	SafeRelease(m_pSprite);
	SafeRelease(m_pTextureUI);
	SafeRelease(m_pTex0);
	SafeRelease(m_pTex1);
	SafeRelease(m_pTex2);
	SafeRelease(m_pTex3);
	SafeRelease(m_pShader);
	

	for each(auto p in m_vecObjMtlTex)
		SafeRelease(p);

	for each(auto p in m_vecGroup)
	{
		SafeRelease(p);
	}
	g_pFontManager->Destroy();

	m_vecGroup.clear();
	m_pRootFrame->Destroy();
	g_pDeviceManager->Destroy();
}

void cMainGame::Setup()
{

	m_pCubePC = new cCubePC;
	m_pCubePC->Setup();

	m_pCubeMan = new cCubeMan;
	m_pCubeMan->Setup();

	m_pCamera = new cCamera;
	m_pCamera->Setup(&m_pCubeMan->GetPosition());

	m_pGrid = new cGrid;
	m_pGrid->Setup();


	

	m_pLight = new cLight;
	m_pLight->Setup();
	//m_pLight->DirectionalLight();
	//m_pLight->SpotLight();
	//m_pLight->PointLight();


	
	/*
	m_pLight->DirectionalLight();
	m_pLight->SpotLight();
	m_pLight->pointLight();
	*/

	// >> : texture
	/*
	{
		D3DXCreateTextureFromFile(g_pD3DDevice, L"../image/수지.png", &m_pTexture);
		ST_PT_VERTEX v;
		v.p = D3DXVECTOR3(0, 0, 0);	//월드의 좌표
		v.t = D3DXVECTOR2(0, 1);	//수지 이미지상의 좌표
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(0, 2, 0);
		v.t = D3DXVECTOR2(0, 0);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(2, 2, 0);
		v.t = D3DXVECTOR2(1, 0);
		m_vecVertex.push_back(v);
	}
	*/
	// << :

	//Setup_Obj();

	
	{
		cAseLoader l;
		m_pRootFrame = l.Load("woman/woman_01_all.ASE");
	}
	/*
	Setup_MeshObject();

	Setup_PickingObj();
	*/

	//Setup_HeightMap();
	m_pSkinnedMesh = new cSkinnedMesh;
	m_pSkinnedMesh->Setup("Zealot", "zealot.X");


	Setup_Frustum();

	Setup_OBB();

	
	//Create_Font();

	//Setup_UI();	//UI는 맨 마지막에 넣는게 좋다

	m_pPopup = new cPopup;
	m_pPopup->Setup("UI","panel-info.png");

	//Seup_Particle();

	Setup_MultiTexture();

	LoadAssets();

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);


}

void cMainGame::Update()
{
	/*
	if (m_pCubePC)
		m_pCubePC->Update();
	*/
	/*
	if (m_pCubeMan)
		m_pCubeMan->Update(m_pMap);
	*/
	if (m_pCamera)
		m_pCamera->Update();
	/*
	if (m_pLight)
		m_pLight->Update();
	*/
	if (m_pRootFrame)
		m_pRootFrame->Update(m_pRootFrame->GetKeyFrame(), NULL);

	g_pTimeManager->Update();
	if (m_pSkinnedMesh)
		m_pSkinnedMesh->Update();

	//if (m_pFrustum)
	//	m_pFrustum->Update();

	/*
	g_pTimeManager->Update();
	if (m_pHoldZealot)
		m_pHoldZealot->Update(m_pMap);

	if (m_pMoveZealot)
		m_pMoveZealot->Update(m_pMap);
	*/

	//Update_Particle();

	Update_MultiTexture();
}

void cMainGame::Render()
{
	
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(47, 121, 112), 1.0F, 0);

	g_pD3DDevice->BeginScene();
	
	if (m_pGrid)
		m_pGrid->Render();
	
	/*
	if (m_pCubePC)
		m_pCubePC->Render();
	*/

	/*
	if (m_pCubeMan)
		m_pCubeMan->Render();
	*/

	if (m_pMap)
		m_pMap->Render();

	//Draw_Texture();
	//Obj_Render();

	//Mesh_Render();

	/*
	{
		if (m_pRootFrame)
			m_pRootFrame->Render();
	}
	*/
	
	//PickingObj_Render();
	
	SkinnedMesh_Render();
	
	//Frustum_Render();
	OBB_Render();

	//Text_Render();
	//UI_Render();

	//Particle_Render();

	//MultiTexture_Render();


	if (m_PopupState == enum_PopupOn)
	{
		if (m_pPopup)
			m_pPopup->Render();
	}

	g_pD3DDevice->EndScene();
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);

}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);

	if (m_PopupState == enum_PopupOn) 
	{
		if (m_pPopup)
			m_pPopup->WndProc(hWnd, message, wParam, lParam);
	}

	switch (message) 
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_TAB:
			m_PopupState = !m_PopupState;
			break;

		default:
			break;
		}
	case WM_LBUTTONDOWN:
		{
		
		cRay r = cRay::RayAtWorldSpace(LOWORD(lParam), HIWORD(lParam));
		for (int i = 0; i < m_vecSphere.size(); i++)
		{
			m_vecSphere[i].isPicked = r.IsPicked(&m_vecSphere[i]);
		}

		}
		
		break;
	case WM_LBUTTONUP:
		{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
			if (m_pPopup->GetptPrevMouse().x + 398 <= x && x <= m_pPopup->GetptPrevMouse().x + 445)
			{
				if (m_pPopup->GetptPrevMouse().y + 86 <= y && y <= m_pPopup->GetptPrevMouse().y +137)
				{
					m_PopupState = enum_PopupOff;
				}
			}
		}
		break;

	case WM_RBUTTONDOWN:
		/*
		{
			static int n = 0;
			//m_pSkinnedMesh->SetAnimationIndex(++n);
			m_pSkinnedMesh->SetAnimationIndexBlend(++n);
			
			//m_pSkinnedMesh->SetAnimationIndexBlend(4);
		}
		*/

		/*
		{
		cRay r = cRay::RayAtWorldSpace(LOWORD(lParam), HIWORD(lParam));
			for (int i = 0; i < m_vecPlaneVertex.size(); i+=3)
			{
				D3DXVECTOR3 v(0, 0, 0);
				if (r.IntersectTri(m_vecPlaneVertex[i + 0].p, m_vecPlaneVertex[i + 1].p, m_vecPlaneVertex[i + 2].p, v))
				{
					m_vPickedPosition = v;
				}
			}

		}
		*/

		{
			for each(ST_SPHERE* sphere in m_vecCullingSphere)
			{
				if (m_pFrustum->IsIn(sphere))
				{
					sphere->isPicked = true;
				}
				else
				{
					sphere->isPicked = false;
				}
			}
		}


		break;

	}
}

void cMainGame::Setup_Obj()
{
	cObjLoad l;
	l.Load(m_vecGroup, "obj", "Map.obj");

	Load_Surface();
}

void cMainGame::Obj_Render()
{
	D3DXMATRIXA16 matWorld, matS, matR;
	D3DXMatrixScaling(&matS, 0.03f, 0.03f, 0.03f);
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0f);

	matWorld = matS * matR;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	for each(auto p in m_vecGroup)
	{
		p->Render();
	}

	//D3DXIntersectTri(v1, v2, v3, rayPos, rayDir, u, v, f);
	//바닥 정점 정보 v1, v2, v3;모든 폴리곤을 검사
}

void cMainGame::Load_Surface()
{
	D3DXMATRIXA16 matWorld, matS, matR;
	D3DXMatrixScaling(&matS, 0.03f, 0.03f, 0.03f);
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0f);
	matWorld = matS * matR;
	//m_pMap = new cObjMap("obj", "map_surface.obj", &matWorld);

}

void cMainGame::Setup_MeshObject()
{
	D3DXCreateTeapot(g_pD3DDevice, &m_pMeshTeapot, NULL);
	D3DXCreateSphere(g_pD3DDevice, 0.5, 10, 10, &m_pMeshSphere, NULL);

	ZeroMemory(&m_stMtlTeapot, sizeof(D3DMATERIAL9));
	m_stMtlTeapot.Ambient = D3DXCOLOR(0.0f, 0.7f, 0.7f, 1.0f);
	m_stMtlTeapot.Diffuse = D3DXCOLOR(0.0f, 0.7f, 0.7f, 1.0f);
	m_stMtlTeapot.Specular = D3DXCOLOR(0.0f, 0.7f, 0.7f, 1.0f);

	ZeroMemory(&m_stMtlSphere, sizeof(D3DMATERIAL9));
	m_stMtlSphere.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlSphere.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlSphere.Specular = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);

	cObjLoad l;
	m_pObjMesh = l.LoadMesh(m_vecObjMtlTex, "obj", "map.obj");


}

void cMainGame::Mesh_Render()
{
	//g_pD3DDevice->SetTexture(0, NULL);
	//g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	_D3DXMATRIXA16 matWorld, matS, matR;
	{
		D3DXMatrixIdentity(&matS);
		D3DXMatrixIdentity(&matR);
		matWorld = matS * matR;
		D3DXMatrixTranslation(&matWorld, 0, 0, 10);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		g_pD3DDevice->SetMaterial(&m_stMtlTeapot);
		m_pMeshTeapot->DrawSubset(0);	//지금은 하나그리는 거라서 0 여러개 그릴 때 값 수정

	}
	{
		D3DXMatrixIdentity(&matS);
		D3DXMatrixIdentity(&matR);
		matWorld = matS * matR;
		//D3DXMatrixTranslation(&matWorld, 0, 0, 10);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		g_pD3DDevice->SetMaterial(&m_stMtlSphere);
		m_pMeshSphere->DrawSubset(0);	//지금은 하나그리는 거라서 0 여러개 그릴 때 값 수정

	}

	{

		D3DXMatrixIdentity(&matWorld);
		D3DXMatrixIdentity(&matS);
		D3DXMatrixIdentity(&matR);

		D3DXMatrixScaling(&matS, 0.01f, 0.01f, 0.01f);
		D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0f);
		matWorld = matS * matR;

		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

		for (size_t i = 0; i < m_vecObjMtlTex.size(); ++i) 
		{
			g_pD3DDevice->SetMaterial(&m_vecObjMtlTex[i]->GetMaterial());
			g_pD3DDevice->SetTexture(0, m_vecObjMtlTex[i]->GetTexture());
			m_pObjMesh->DrawSubset(i);
		}


	}

}

void cMainGame::Setup_PickingObj()
{
	for (int i = 0; i <= 10; i++) 
	{
		ST_SPHERE s;
		s.fRadius = 0.5f;
		s.vCenter = D3DXVECTOR3(0, 0, -10 + 2 * i);
		m_vecSphere.push_back(s);
	}

	ZeroMemory(&m_stMtlNone, sizeof(D3DMATERIAL9));
	m_stMtlNone.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlNone.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlNone.Specular = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);

	ZeroMemory(&m_stMtlPicked, sizeof(D3DMATERIAL9));
	m_stMtlPicked.Ambient = D3DXCOLOR(0.7f, 0.0f, 0.0f, 1.0f);
	m_stMtlPicked.Diffuse = D3DXCOLOR(0.7f, 0.0f, 0.0f, 1.0f);
	m_stMtlPicked.Specular = D3DXCOLOR(0.7f, 0.0f, 0.0f, 1.0f);

	ZeroMemory(&m_stMtlPlane, sizeof(D3DMATERIAL9));
	m_stMtlPlane.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtlPlane.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtlPlane.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

	ST_PN_VERTEX v;
	v.n = D3DXVECTOR3(0, 1, 0);
	v.p = D3DXVECTOR3(-10, 0, -10); m_vecPlaneVertex.push_back(v);
	v.p = D3DXVECTOR3(-10, 0,  10); m_vecPlaneVertex.push_back(v);
	v.p = D3DXVECTOR3( 10, 0,  10); m_vecPlaneVertex.push_back(v);

	v.p = D3DXVECTOR3(-10, 0, -10); m_vecPlaneVertex.push_back(v);
	v.p = D3DXVECTOR3( 10, 0,  10); m_vecPlaneVertex.push_back(v);
	v.p = D3DXVECTOR3( 10, 0, -10); m_vecPlaneVertex.push_back(v);

}

void cMainGame::PickingObj_Render()
{
	D3DXMATRIXA16 matWorld;

	g_pD3DDevice->SetFVF(ST_PN_VERTEX::FVF);
	g_pD3DDevice->SetMaterial(&m_stMtlPlane);
	D3DXMatrixIdentity(&matWorld);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetTexture(0, 0);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, &m_vecPlaneVertex[0], sizeof(ST_PN_VERTEX));

	for (int i = 0; i < m_vecSphere.size(); i++)
	{
		D3DXMatrixIdentity(&matWorld);
		matWorld._41 = m_vecSphere[i].vCenter.x;
		matWorld._42 = m_vecSphere[i].vCenter.y;
		matWorld._43 = m_vecSphere[i].vCenter.z;
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		g_pD3DDevice->SetMaterial(m_vecSphere[i].isPicked ? &m_stMtlPicked : &m_stMtlNone);
		m_pMeshSphere->DrawSubset(0);

	}

	g_pD3DDevice->SetMaterial(&m_stMtlNone);
	D3DXMatrixTranslation(&matWorld, m_vPickedPosition.x, m_vPickedPosition.y, m_vPickedPosition.z);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_pMeshSphere->DrawSubset(0);

}

void cMainGame::SkinnedMesh_Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	if (m_pShader) 
	{
		D3DXMATRIXA16 matView, matProjection;
		g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
		g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProjection);
		m_pShader->SetMatrix("gWorldMatrix", &matWorld);
		m_pShader->SetMatrix("gViewMatrix", &matView);
		m_pShader->SetMatrix("gProjectionMatrix", &matProjection);

		m_pShader->SetVector("gLightColor", &D3DXVECTOR4(1, 0, 0, 1));
		m_pShader->SetTexture("DiffuseMap_Tex", m_pTexture);
		m_pShader->SetTexture("SpecularMap_Tex", m_pSpecularTexture);



		//gpColorShader->SetValue("gColor", &D3DXVECTOR4(1.0F, 0.5F, 0.0F, 1.0F), sizeof(D3DXCOLOR));
		D3DXCOLOR color(1, 1, 0, 1);
		m_pShader->SetValue("gColor", &color, sizeof(D3DXCOLOR));


		UINT numPasses = 0;
		m_pShader->Begin(&numPasses, NULL);
		{
			for (UINT i = 0; i < numPasses; i++)
			{
				m_pShader->BeginPass(i);
				{
					if (m_pSkinnedMesh)
						m_pSkinnedMesh->Render(NULL);
				}
				m_pShader->EndPass();
			}
		}
		m_pShader->End();
	}
	else
	{
		if (m_pSkinnedMesh)
			m_pSkinnedMesh->Render(NULL);
	}
	g_pD3DDevice->SetTexture(0, NULL);
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
}

void cMainGame::Setup_HeightMap()
{
	cHeightMap* pMap = new cHeightMap;
	pMap->Setup("HeightMapData/", "HeightMap.raw", "terrain.jpg");
	m_pMap = pMap;
}

void cMainGame::Setup_Frustum()
{
	D3DXCreateSphere(g_pD3DDevice, 0.5f, 10, 10, &m_pSphere, NULL);

	for (int i = -20; i <= 20; i++)
	{
		for (int j = -20; j <=20; j++) 
		{
			for (int k = -20; k <= 20; k++)
			{
				ST_SPHERE* s = new ST_SPHERE;
				s->fRadius = 0.5f;
				s->vCenter = D3DXVECTOR3((float)i, (float)j, (float)k);
				s->isPicked = true;
				m_vecCullingSphere.push_back(s);
			}
		}
	}

	ZeroMemory(&m_stCullingMtl, sizeof(D3DMATERIAL9));
	m_stCullingMtl.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stCullingMtl.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stCullingMtl.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

	m_pFrustum = new cFrustum;
	m_pFrustum->Setup();

}

void cMainGame::Frustum_Render()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	//g_pD3DDevice->SetTexture(0, NULL);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	for each(ST_SPHERE* sphere in m_vecCullingSphere)
	{
		if (sphere->isPicked)
		{
			D3DXMatrixIdentity(&matWorld);
			matWorld._41 = sphere->vCenter.x;
			matWorld._42 = sphere->vCenter.y;
			matWorld._43 = sphere->vCenter.z;
			g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
			g_pD3DDevice->SetMaterial(&m_stCullingMtl);
			m_pSphere->DrawSubset(0);
		}
	}

}

void cMainGame::Setup_OBB()
{
	m_pHoldZealot = new cZealot;
	m_pHoldZealot->Setup();

	m_pMoveZealot = new cZealot;
	m_pMoveZealot->Setup();

	cCharacter* pCharacter = new cCharacter;
	m_pMoveZealot->SetCharacterController(pCharacter);
	SafeRelease(pCharacter);

}

void cMainGame::OBB_Render()
{
	D3DCOLOR c = cOBB::IsCollision(m_pHoldZealot->GetOBB(), m_pMoveZealot->GetOBB()) ? D3DCOLOR_XRGB(255, 0, 0) : D3DCOLOR_XRGB(255, 255, 255);
	/*
	if (m_pHoldZealot)
		m_pHoldZealot->Render(c);
	if (m_pMoveZealot)
		m_pMoveZealot->Render(c);
	*/
}

void cMainGame::Create_Font()
{
	D3DXFONT_DESC fd;
	ZeroMemory(&fd, sizeof(D3DXFONT_DESC));
	fd.Height = 50;
	fd.Width = 25;
	fd.Weight = FW_MEDIUM;
	fd.Italic = false;
	fd.CharSet = DEFAULT_CHARSET;
	fd.OutputPrecision = OUT_DEFAULT_PRECIS;
	fd.PitchAndFamily = FF_DONTCARE;

	//lstrcpy(fd.FaceName, L"굴림체");
	//wcscpy_s(fd.FaceName, L"굴림체");

	//폰트 등록
	AddFontResource(L"font/umberto.ttf");
	wcscpy_s(fd.FaceName, L"umberto");
	
	D3DXCreateFontIndirect(g_pD3DDevice, &fd, &m_pFont);


	//3D 글자
	HDC hdc = CreateCompatibleDC(0);
	LOGFONT lf;
	ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 25;
	lf.lfWidth = 12;
	lf.lfWeight = 500;
	lf.lfItalic = false;
	lf.lfUnderline = false;
	lf.lfStrikeOut = false;
	lf.lfCharSet = DEFAULT_CHARSET;
	wcscpy_s(lf.lfFaceName, L"굴림체");

	HFONT hFont;
	HFONT hFontOld;

	hFont = CreateFontIndirect(&lf);
	hFontOld = (HFONT)SelectObject(hdc, hFont);
	D3DXCreateText(g_pD3DDevice, hdc,
		L"Direct3D 가나다",
		0.001f,
		0.01f,
		&m_p3DText,
		0, 0);

	SelectObject(hdc, hFontOld);
	DeleteObject(hFont);
	DeleteDC(hdc);

}

void cMainGame::Text_Render()
{
	string sText("ABC 123 !@#$ 가나다라");
	RECT rc;
	SetRect(&rc, 100, 100, 301, 200);

	LPD3DXFONT pFont = g_pFontManager->GetFont(cFontManager::E_QUEST);	//E_QUEST일 때와 E_DEFAULT일 때
	pFont->DrawTextA(NULL,
		sText.c_str(),
		sText.length(),
		&rc,
		DT_LEFT | DT_TOP | DT_NOCLIP,
		D3DCOLOR_XRGB(255, 255, 0));

	/*
	m_pFont->DrawTextA(NULL,
		sText.c_str(),
		sText.length(),
		&rc,
		DT_LEFT | DT_TOP | DT_NOCLIP,
		D3DCOLOR_XRGB(255, 255, 0));
	*/

	//3D글자가 매쉬로 이루어져 있다
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	g_pD3DDevice->SetTexture(0, NULL);
	D3DXMATRIXA16 matWorld, matS, matR, matT;
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixIdentity(&matS);
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);
	D3DXMatrixScaling(&matS, 1.0f, 1.0f, 100.0f);
	D3DXMatrixRotationX(&matR, -D3DX_PI / 4.0f);
	D3DXMatrixTranslation(&matT, -2.0f, 1.0f, 0.0f);
	matWorld = matS * matR * matT;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_p3DText->DrawSubset(0);
}

void cMainGame::Setup_UI()
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	//m_pTextureUI = g_pTextureManager->GetTexture("UI/김태희.jpg"); ->이렇게 로드하면 안됨

	
	D3DXCreateTextureFromFileEx(g_pD3DDevice, 
		L"UI/김태희.jpg",
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

void cMainGame::UI_Render()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	RECT rc;
	//SetRect(&rc, 0, 0, 579, 381);
	SetRect(&rc, 0, 0, m_stImageInfo.Width, m_stImageInfo.Height);
	//SetRect(&rc, m_stImageInfo.Width/2, m_stImageInfo.Height/2, m_stImageInfo.Width, m_stImageInfo.Height);	//일부분만 출력

	// >>	UI 이동과 회전도 가능하다
	D3DXMATRIXA16 matT, matS, matR, mat;
	D3DXMatrixTranslation(&matT, 20, 20, 0);

	static float fAngle = 0.0f;
	//fAngle += 0.1f;
	D3DXMatrixRotationZ(&matR, fAngle);
	mat = matR * matT;

	m_pSprite->SetTransform(&mat);
	// <<


	m_pSprite->Draw(m_pTextureUI, &rc, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 0), D3DCOLOR_XRGB(255, 255, 255, 255));
	//m_pSprite->Draw(m_pTextureUI, &rc, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 0), D3DCOLOR_XRGB(100, 255, 255, 255)); -> RGB에서 알파값을 고치면 투명해진다


	m_pSprite->End();
}

void cMainGame::Seup_Particle()
{
	m_vecVertexParticle.resize(1000);
	for (int i = 0; i < m_vecVertexParticle.size(); ++i)
	{
		float fRadius = rand() % 100 / 10.0f;
		//fRadius = 50.0f;
		m_vecVertexParticle[i].p = D3DXVECTOR3(0, 0, fRadius);
		D3DXVECTOR3 vAngle = D3DXVECTOR3(
			D3DXToRadian(rand() % 360 / 10.0f),
			D3DXToRadian(rand() % 360 / 10.0f),
			D3DXToRadian(rand() % 360 / 10.0f)
		);

		D3DXMATRIX matRx, matRy, matRz, matWorld;
		D3DXMatrixRotationX(&matRx, vAngle.x);
		D3DXMatrixRotationY(&matRy, vAngle.y);;
		D3DXMatrixRotationZ(&matRz, vAngle.z);
		matWorld = matRx * matRy * matRz;

		D3DXVec3TransformCoord(
			&m_vecVertexParticle[i].p,
			&m_vecVertexParticle[i].p,
			&matWorld);

		m_vecVertexParticle[i].c = D3DCOLOR_ARGB(255, 180, 70, 20);
	}

}

void cMainGame::Update_Particle()
{
	static int nAlpha = 0;
	static int nDelta = 4;
	nAlpha += nDelta;

	if (nAlpha > 255) 
	{
		nAlpha = 255;
		nDelta *= -1;
	}

	if (nAlpha < 0)
	{
		nAlpha = 0;
		nDelta *= -1;
	}

	for (int i = 0; i < m_vecVertexParticle.size(); i++) 
	{
		if (i % 2) continue;
		m_vecVertexParticle[i].c = D3DCOLOR_ARGB(nAlpha,
			180, 70, 20);
	}
}

void cMainGame::Particle_Render()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, false);

	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALEENABLE, true);
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE, FtoDw(10.0f));

	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALE_A, FtoDw(0.0f));
	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALE_B, FtoDw(0.0f));
	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALE_C, FtoDw(10.0f));


	g_pD3DDevice->SetRenderState(D3DRS_POINTSPRITEENABLE, true);
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE_MIN, FtoDw(0.0f));
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE_MAX, FtoDw(50.0f));

	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);

	//색깔값을 더한다
	g_pD3DDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->SetTexture(0, g_pTextureManager->GetTexture("../image/alpha_tex.tga"));
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_POINTLIST,
		m_vecVertexParticle.size(),
		&m_vecVertexParticle[0],
		sizeof(ST_PC_VERTEX));

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	g_pD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, true);


	//질럿 텍스쳐 복구
	g_pD3DDevice->SetTexture(0, NULL);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG0, D3DTA_DIFFUSE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);

}

void cMainGame::Setup_MultiTexture()
{
	D3DXCreateTextureFromFile(g_pD3DDevice, L"Texture/stones.png", &m_pTex0);
	D3DXCreateTextureFromFile(g_pD3DDevice, L"Texture/env0.png", &m_pTex1);
	D3DXCreateTextureFromFile(g_pD3DDevice, L"Texture/env1.png", &m_pTex2);
	D3DXCreateTextureFromFile(g_pD3DDevice, L"Texture/Albedo00.jpg", &m_pTex3);

	ST_PT_VERTEX v;
	v.p = D3DXVECTOR3(0, 0, 0); v.t = D3DXVECTOR2(0, 1); m_vecVertex_Multi.push_back(v);
	v.p = D3DXVECTOR3(0, 2, 0); v.t = D3DXVECTOR2(0, 0); m_vecVertex_Multi.push_back(v);
	v.p = D3DXVECTOR3(2, 0, 0); v.t = D3DXVECTOR2(1, 1); m_vecVertex_Multi.push_back(v);

	v.p = D3DXVECTOR3(2, 2, 0); v.t = D3DXVECTOR2(1, 0); m_vecVertex_Multi.push_back(v);
	v.p = D3DXVECTOR3(2, 0, 0); v.t = D3DXVECTOR2(1, 1); m_vecVertex_Multi.push_back(v);
	v.p = D3DXVECTOR3(0, 2, 0); v.t = D3DXVECTOR2(0, 0); m_vecVertex_Multi.push_back(v);

}

void cMainGame::Update_MultiTexture()
{
	if (::GetAsyncKeyState('1') & 0x8000) m_nType = 1;
	if (::GetAsyncKeyState('2') & 0x8000) m_nType = 2;
	if (::GetAsyncKeyState('3') & 0x8000) m_nType = 3;
	if (::GetAsyncKeyState('4') & 0x8000) m_nType = 4;
	if (::GetAsyncKeyState('5') & 0x8000) m_nType = 5;
	if (::GetAsyncKeyState('6') & 0x8000) m_nType = 6;
	if (::GetAsyncKeyState('7') & 0x8000) m_nType = 7;
	if (::GetAsyncKeyState('8') & 0x8000) m_nType = 8;
	if (::GetAsyncKeyState('9') & 0x8000) m_nType = 9;
	if (::GetAsyncKeyState('0') & 0x8000) m_nType = 0;
	if (::GetAsyncKeyState('R') & 0x8000) m_nType = -1;

}

void cMainGame::MultiTexture_Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	for (int i = 0; i <4; i++) 
	{
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_ADDRESSW, D3DTADDRESS_WRAP);

		g_pD3DDevice->SetSamplerState(i, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
	}

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_TEXCOORDINDEX, 0);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_TEXCOORDINDEX, 0);
	g_pD3DDevice->SetTextureStageState(3, D3DTSS_TEXCOORDINDEX, 0);

	switch(m_nType)
	{
	case 1:	MultiTexture_Render1(); break;
	case 2:	MultiTexture_Render2(); break;
	case 3:	MultiTexture_Render3(); break;
	case 4:	MultiTexture_Render4(); break;
	case 5:	MultiTexture_Render5(); break;
	case 6:	MultiTexture_Render6(); break;
	case 7:	MultiTexture_Render7(); break;
	case 8:	MultiTexture_Render8(); break;
	case 9:	MultiTexture_Render9(); break;
	case 0:	MultiTexture_Render0(); break;
	default: MultiTexture_Render_default(); break;
	}

	SetBillboard();

	g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex_Multi.size() / 3,
		&m_vecVertex_Multi[0],
		sizeof(ST_PT_VERTEX));

	g_pD3DDevice->SetTexture(0, NULL);
	g_pD3DDevice->SetTexture(1, NULL);
	g_pD3DDevice->SetTexture(2, NULL);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_RESULTARG, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_RESULTARG, D3DTA_CURRENT);

	for (int i = 0; i < 4; ++i)
	{
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_MAGFILTER, D3DTEXF_NONE);
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_MINFILTER, D3DTEXF_NONE);
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
	}

}

void cMainGame::MultiTexture_Render1()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex1);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);


}

void cMainGame::MultiTexture_Render2()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex1);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_MODULATE2X);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTexture_Render3()
{

	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex1);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_MODULATE4X);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTexture_Render4()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex1);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_ADD);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTexture_Render5()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex1);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_SUBTRACT);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTexture_Render6()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex3);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_ADDSIGNED);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTexture_Render7()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex3);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_ADDSIGNED2X);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTexture_Render8()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex3);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_ADDSMOOTH);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTexture_Render9()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex2);
	g_pD3DDevice->SetTexture(2, m_pTex3);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_RESULTARG, D3DTA_TEMP);

	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLORARG0, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLORARG1, D3DTA_TEMP);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLORARG2, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_MULTIPLYADD);

	g_pD3DDevice->SetTextureStageState(3, D3DTSS_COLOROP, D3DTOP_DISABLE);
	
}

void cMainGame::MultiTexture_Render0()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex2);
	g_pD3DDevice->SetTexture(2, m_pTex3);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_RESULTARG, D3DTA_TEMP);

	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLORARG0, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLORARG1, D3DTA_TEMP);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLORARG2, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_LERP);

	g_pD3DDevice->SetTextureStageState(3, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTexture_Render_default()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::SetBillboard()
{
	D3DXMATRIXA16 matBillboard, matView;
	D3DXMatrixIdentity(&matBillboard);
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);

	matBillboard._11 = matView._11;
	matBillboard._13 = matView._13;
	matBillboard._31 = matView._31;
	matBillboard._33 = matView._33;

	D3DXMATRIXA16 matT;
	D3DXMatrixIdentity(&matT);
	D3DXMatrixTranslation(&matT, 1, 0, 0);
	matBillboard *= matT;

	D3DXMatrixInverse(&matBillboard, NULL, &matBillboard);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matBillboard);

}

/*
void cMainGame::Draw_Texture()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetTexture(0, m_pTexture);
	g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PT_VERTEX));
	g_pD3DDevice->SetTexture(0, NULL);

}
*/