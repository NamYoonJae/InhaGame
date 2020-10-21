#include "stdafx.h"
#include "cPicking.h"
#include "cMtlTex.h"
#include "cSphere.h"



cPicking::cPicking()
	:pSphere(NULL)
	, m_cameraEye(0.0f, 0.0f, 0.0f)
	, m_cameraLookAt(0.0f, 0.0f, 0.0f)
	, m_up(0.0f, 0.0f, 0.0f)
	,m_Direction(0.0f, 0.0f, 0.0f)
	,m_Origin(0.0f, 0.0f, 0.0f)
{

}


cPicking::~cPicking()
{

}

void cPicking::Setup()
{

	for (int i = -14;  i < 16; i +=2) 
	{
		pSphere = new cSphere;
		pSphere->Setup(i);
		vecSphereList.push_back(pSphere);
	}
	
}

void cPicking::Update(D3DXVECTOR3 cameraEye, D3DXVECTOR3 cameraLookAt, D3DXVECTOR3 up)
{
	//m_cameraEye = cameraEye;
	//m_cameraLookAt = cameraLookAt;
	//m_up = up;
	for (int i = 0; i < vecSphereList.size(); i++)
	{
		vecSphereList[i]->Update();
	}


}

void cPicking::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	g_pD3DDevice->SetTexture(0, NULL);
	for (int i = 0; i < vecSphereList.size(); i++) 
	{
		vecSphereList[i]->Render();
	}
}

void cPicking::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		cPicking r = RayAtWorldSpace(LOWORD(lParam), HIWORD(lParam));
		for (size_t i = 0; i < vecSphereList.size(); i++)
		{
			
			if (r.IsPicked(vecSphereList[i]) == true)
			{
				vecSphereList[i]->picked = !vecSphereList[i]->picked;
			}
			
			//vecSphereList[i]->picked = r.IsPicked(vecSphereList[i]);
		}
	}
		break;

	case WM_RBUTTONDOWN:
	{
	
	}
		break;


	}
}

cPicking cPicking::RayAtWorldSpace(int nScreenX, int nScreenY)
{
	cPicking r = RayAtViewSpace(nScreenX, nScreenY);	//뷰포트 투영행렬을 이용해 변환한 방향 벡터를 얻어온다.

	D3DXMATRIXA16 matView, matInvView;
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);	//matView에 현재 View를 담는다
	D3DXMatrixInverse(&matInvView, 0, &matView);	//matInvView에 matView의 역행렬을 담는다.

	D3DXVec3TransformCoord(&r.m_Origin, &r.m_Origin, &matInvView);	//뷰의 역행렬을 이용해 광선의 출발점을 변환한다.->뷰의 역행렬을 곱해서 월드 좌표를 구함 ->카메라 위치
	D3DXVec3TransformNormal(&r.m_Direction, &r.m_Direction, &matInvView);	//뷰의 역행렬을 이용해 방향 벡터를 변환한다.
	D3DXVec3Normalize(&r.m_Direction, &r.m_Direction);	//방향 벡터 정규화(행렬 안의 모든 값이 1보다 작도록 한다)
	
	return r;
}

cPicking cPicking::RayAtViewSpace(int nScreenX, int nScreenY)
{

	D3DVIEWPORT9 ViewPort;
	g_pD3DDevice->GetViewport(&ViewPort);	//뷰포트 행렬 저장

	D3DXMATRIXA16 MatProjection;
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &MatProjection);	//투영 행렬 저장

	//뷰포트와 투영행렬을 이용하여 방향벡터 설정 후 리턴
	//찍은 스크린의 좌표에서 뷰포트 역행렬을 곱하고 프로젝션 역행렬 곱하고 역행렬 뷰의 역행렬 곱하고
	cPicking r;
	r.m_Direction.x = ((2.0f * nScreenX) / ViewPort.Width - 1.0f) / MatProjection._11;
	r.m_Direction.y = ((-2.0f * nScreenY) / ViewPort.Height + 1.0f) / MatProjection._22;
	r.m_Direction.z = 1.0f;

	r.m_Origin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);


	return r;
}

bool cPicking::IsPicked(cSphere * pSphere)
{
	
	cPicking ray = (*this);

	D3DXMATRIXA16 matInvWorld;	//월드의 역행렬
	D3DXMatrixIdentity(&matInvWorld);
	matInvWorld._41 = -pSphere->center.x;
	matInvWorld._42 = -pSphere->center.y;
	matInvWorld._43 = -pSphere->center.z;

	D3DXVec3TransformCoord(&ray.m_Origin, &ray.m_Origin, &matInvWorld);	//월드의 역행렬을 이용해 카메라의 좌표를 변환
	D3DXVec3TransformNormal(&ray.m_Direction, &ray.m_Direction, &matInvWorld);	//월드의 역행렬을 이용해 방향 벡터를 변환
	float vv = D3DXVec3Dot(&ray.m_Direction, &ray.m_Direction);	//방향벡터와 방향벡터 내적
	float qv = D3DXVec3Dot(&ray.m_Origin, &ray.m_Direction);	//위치좌표와 방향 벡터 내적
	float qq = D3DXVec3Dot(&ray.m_Origin, &ray.m_Origin);	//위치좌표와 위치좌표 내적
	float rr = pSphere->radius * pSphere->radius;	//구의 반지름 * 반지름


	return qv * qv - vv * (qq - rr) >= 0;	//0이라면 1개의 점이 교차 / 0보다 크다면 2개의 점이 교차 / 0보다 작다면 교차하지 않는다

}
