#include "stdafx.h"
#include "cPicking.h"
#include "cMtlTex.h"
#include "cSphere.h"



cPicking::cPicking()
	:pSphere(NULL)
	, m_cameraEye(0.0f, 0.0f, 0.0f)
	, m_cameraLookAt(0.0f, 0.0f, 0.0f)
	, m_up(0.0f, 0.0f, 0.0f)
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
	m_cameraEye = cameraEye;
	m_cameraLookAt = cameraLookAt;
	m_up = up;



}

void cPicking::Render()
{
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
		//카메라 방향에서 레이쏘기
		ST_RAY r = RayAtWorldSpace(LOWORD(lParam), HIWORD(lParam));
		for (size_t i = 0; i < vecSphereList.size(); i++)
		{
			
		}
	}
		break;

	case WM_RBUTTONDOWN:
	{
	
	}
		break;


	}
}

cPicking::ST_RAY cPicking::RayAtWorldSpace(int nScreenX, int nScreenY)
{
	ST_RAY r = RayAtViewSpace(nScreenX, nScreenY);	//뷰포트 투영행렬을 이용해 변환한 방향 벡터를 얻어온다.

	D3DXMATRIXA16 matView, matInvView;
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);	//matView에 현재 View를 담는다
	D3DXMatrixInverse(&matInvView, 0, &matView);	//matInvView에 matView의 역핵렬을 담는다.

	D3DXVec3TransformCoord(&r.r_Origin, &r.r_Origin, &matInvView);	//뷰의 역행렬을 이용해 광선의 출발점을 변환한다.
	D3DXVec3TransformNormal(&r.r_Direction, &r.r_Direction, &matInvView);	//뷰의 역행렬을 이용해 방향 벡터를 변환한다.
	D3DXVec3Normalize(&r.r_Direction, &r.r_Direction);	//방향 벡터 정규화(행렬 안의 모든 값이 1보다 작도록 한다)
	
	return r;
}

cPicking::ST_RAY cPicking::RayAtViewSpace(int nScreenX, int nScreenY)
{

	D3DVIEWPORT9 ViewPort;
	g_pD3DDevice->GetViewport(&ViewPort);	//뷰포트 행렬 저장

	D3DXMATRIXA16 MatProjection;
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &MatProjection);	//투영 행렬 저장

	//뷰포트와 투영행렬을 이용하여 방향벡터 설정 후 리턴
	ST_RAY r;
	r.r_Direction.x = ((2.0f * nScreenX) / ViewPort.Width - 1.0f) / MatProjection._11;
	r.r_Direction.y = ((-2.0f * nScreenY) / ViewPort.Height + 1.0f) / MatProjection._22;
	r.r_Direction.z = 1.0f;

	r.r_Origin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);


	return r;
}

bool cPicking::IsPicked(cSphere * pSphere, ST_RAY r)
{
	
	ST_RAY ray = r;

	D3DXMATRIXA16 matInvWorld;	//월드의 역행렬
	D3DXMatrixIdentity(&matInvWorld);
	matInvWorld._41 = -pSphere->center.x;
	matInvWorld._42 = -pSphere->center.y;
	matInvWorld._43 = -pSphere->center.z;

	D3DXVec3TransformCoord(&ray.r_Origin, &ray.r_Origin, &matInvWorld);	//월드의 역행렬을 이용해 카메라의 좌표를 변환
	D3DXVec3TransformNormal(&ray.r_Direction, &ray.r_Direction, &matInvWorld);	//월드의 역행렬을 이용해 방향 벡터를 변환
	float vv = D3DXVec3Dot(&r.r_Direction, &r.r_Direction);	//방향벡터와 방향벡터 내적
	float qv = D3DXVec3Dot(&r.r_Origin, &r.r_Direction);	//위치좌표와 방향 벡터 내적
	float qq = D3DXVec3Dot(&r.r_Origin, &r.r_Origin);	//위치좌표와 위치좌표 내적
	float rr = pSphere->radius * pSphere->radius;	//구의 반지름 * 반지름


	return qv * qv - vv * (qq - rr) >= 0;	//0이라면 1개의 점이 교차 / 0보다 크다면 2개의 점이 교차 / 0보다 작다면 교차하지 않는다
}

