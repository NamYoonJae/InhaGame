#pragma once
class cCamera
{
private:
	D3DXVECTOR3 m_vEye;
	D3DXVECTOR3 m_vLookAt;
	D3DXVECTOR3 m_vUp;
	D3DXVECTOR3 *m_pvTarget;

	POINT m_ptPrevMouse;
	bool m_isLButtonDown;
	float m_fCameraDistance;
	D3DXVECTOR3 m_vCamRotAngle;


public:
	cCamera();
	~cCamera();

	void Setup(D3DXVECTOR3* pvTarget);
	void Update();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
	D3DXVECTOR3 GetEye();
	D3DXVECTOR3 GetLookAt();
	D3DXVECTOR3 GetUp();
};

