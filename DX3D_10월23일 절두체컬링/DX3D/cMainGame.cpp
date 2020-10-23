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
#include "cSphere.h"


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
{

}


cMainGame::~cMainGame()
{
	SafeDelete(m_pCubePC);
	SafeDelete(m_pCamera);
	SafeDelete(m_pGrid);
	SafeDelete(m_pCubeMan);
	SafeDelete(m_pMap);
	SafeDelete(m_pSkinnedMesh);

	//SafeRelease(m_pTexture);
	SafeRelease(m_pMeshTeapot);
	SafeRelease(m_pMeshSphere);
	SafeRelease(m_pObjMesh);

	for each(auto p in m_vecObjMtlTex)
	{
	SafeRelease(p);
	}
	m_vecObjMtlTex.clear();

	for each(auto p in m_vecGroup)
	{
		SafeRelease(p);
	}

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

	for (float y = 15; y > -15; y--) 
	{
		for (float z = 15; z > -15; z--) 
		{
			for (float x = -15; x < 15; x++) 
			{
				m_pSphere = new cSphere;
				m_pSphere->Setup(x, y, z);
				m_vecSphereList.push_back(m_pSphere);
			}
		}
	}



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
	
	for (int i = 0 ; i < m_vecSphereList.size(); i++) 
	{
		m_vecSphereList[i]->Render();
	}

	g_pD3DDevice->EndScene();
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);

}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);

	switch (message) 
	{
	case WM_LBUTTONDOWN:
		{
		cRay r = cRay::RayAtWorldSpace(LOWORD(lParam), HIWORD(lParam));
		for (int i = 0; i < m_vecSphere.size(); i++)
		{
			m_vecSphere[i].isPicked = r.IsPicked(&m_vecSphere[i]);
		}

		}
		break;

	case WM_RBUTTONDOWN:
		{
			static int n = 0;
			//m_pSkinnedMesh->SetAnimationIndex(++n);
			m_pSkinnedMesh->SetAnimationIndexBlend(++n);

			//m_pSkinnedMesh->SetAnimationIndexBlend(4);


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
			FrusturnCulling();
			



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
	if (m_pSkinnedMesh)
		m_pSkinnedMesh->Render(NULL);
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	g_pD3DDevice->SetTexture(0, NULL);
}

void cMainGame::Setup_HeightMap()
{
	cHeightMap* pMap = new cHeightMap;
	pMap->Setup("HeightMapData/", "HeightMap.raw", "terrain.jpg");
	m_pMap = pMap;
}

void cMainGame::FrusturnCulling()
{
	D3DVIEWPORT9 vp;
	g_pD3DDevice->GetViewport(&vp);
	//가까운 점
	D3DXVECTOR3 leftUp(0, 0, 0);
	D3DXVECTOR3 rightUp(vp.Width, 0, 0);
	D3DXVECTOR3 leftDown(0, vp.Height, 0);
	D3DXVECTOR3 rightDown(vp.Width, vp.Height, 0);

	//먼 점
	D3DXVECTOR3 leftUp(0, 0, 1);
	D3DXVECTOR3 rightUp(vp.Width, 0, 1);
	D3DXVECTOR3 leftDown(0, vp.Height, 1);
	D3DXVECTOR3 rightDown(vp.Width, vp.Height, 1);




	//프로젝션 역행렬 곱하기
		/*
		D3DXMATRIXA16 matPrijection, matInvProjection;
		g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matPrijection); // 프로젝션 행렬 가져오는 방법
		D3DXMatrixInverse(matPrijection, 0, &matInvProjection);
		*/

	//뷰의 역행렬 곱하기
		/*
		D3DXMATRIXA16 matView, matInvView;
		g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
		D3DXMatrixInverse(&matInvView, 0, &matView);
		*/
	//=> 월드 상의 좌표 8개의 좌표가 나온다



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