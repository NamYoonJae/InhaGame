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
	cPicking r = RayAtViewSpace(nScreenX, nScreenY);	//����Ʈ ��������� �̿��� ��ȯ�� ���� ���͸� ���´�.

	D3DXMATRIXA16 matView, matInvView;
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);	//matView�� ���� View�� ��´�
	D3DXMatrixInverse(&matInvView, 0, &matView);	//matInvView�� matView�� ������� ��´�.

	D3DXVec3TransformCoord(&r.m_Origin, &r.m_Origin, &matInvView);	//���� ������� �̿��� ������ ������� ��ȯ�Ѵ�.->���� ������� ���ؼ� ���� ��ǥ�� ���� ->ī�޶� ��ġ
	D3DXVec3TransformNormal(&r.m_Direction, &r.m_Direction, &matInvView);	//���� ������� �̿��� ���� ���͸� ��ȯ�Ѵ�.
	D3DXVec3Normalize(&r.m_Direction, &r.m_Direction);	//���� ���� ����ȭ(��� ���� ��� ���� 1���� �۵��� �Ѵ�)
	
	return r;
}

cPicking cPicking::RayAtViewSpace(int nScreenX, int nScreenY)
{

	D3DVIEWPORT9 ViewPort;
	g_pD3DDevice->GetViewport(&ViewPort);	//����Ʈ ��� ����

	D3DXMATRIXA16 MatProjection;
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &MatProjection);	//���� ��� ����

	//����Ʈ�� ��������� �̿��Ͽ� ���⺤�� ���� �� ����
	//���� ��ũ���� ��ǥ���� ����Ʈ ������� ���ϰ� �������� ����� ���ϰ� ����� ���� ����� ���ϰ�
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

	D3DXMATRIXA16 matInvWorld;	//������ �����
	D3DXMatrixIdentity(&matInvWorld);
	matInvWorld._41 = -pSphere->center.x;
	matInvWorld._42 = -pSphere->center.y;
	matInvWorld._43 = -pSphere->center.z;

	D3DXVec3TransformCoord(&ray.m_Origin, &ray.m_Origin, &matInvWorld);	//������ ������� �̿��� ī�޶��� ��ǥ�� ��ȯ
	D3DXVec3TransformNormal(&ray.m_Direction, &ray.m_Direction, &matInvWorld);	//������ ������� �̿��� ���� ���͸� ��ȯ
	float vv = D3DXVec3Dot(&ray.m_Direction, &ray.m_Direction);	//���⺤�Ϳ� ���⺤�� ����
	float qv = D3DXVec3Dot(&ray.m_Origin, &ray.m_Direction);	//��ġ��ǥ�� ���� ���� ����
	float qq = D3DXVec3Dot(&ray.m_Origin, &ray.m_Origin);	//��ġ��ǥ�� ��ġ��ǥ ����
	float rr = pSphere->radius * pSphere->radius;	//���� ������ * ������


	return qv * qv - vv * (qq - rr) >= 0;	//0�̶�� 1���� ���� ���� / 0���� ũ�ٸ� 2���� ���� ���� / 0���� �۴ٸ� �������� �ʴ´�

}
