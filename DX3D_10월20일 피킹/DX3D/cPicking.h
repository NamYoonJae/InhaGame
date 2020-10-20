#pragma once
class cMtlTex;
class cSphere;

class cPicking
{
private:
	vector<cSphere*> vecSphereList;
	cSphere* pSphere;

	D3DXVECTOR3 m_cameraEye;
	D3DXVECTOR3 m_cameraLookAt;
	D3DXVECTOR3 m_up;

	D3DXVECTOR3 m_Direction;
	D3DXVECTOR3 m_Origin;

public:
	cPicking();
	~cPicking();

	void Setup();
	void Update(D3DXVECTOR3 cameraEye, D3DXVECTOR3 cameraLookAt, D3DXVECTOR3 up);
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


	cPicking RayAtWorldSpace(int nScreenX, int nScreenY);
	cPicking RayAtViewSpace(int nScreenX, int nScreenY);
	bool IsPicked(cSphere* pSphere);
	
};

