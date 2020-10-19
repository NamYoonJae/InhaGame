#pragma once
class cMainGame
{
private:
	HDC m_MemDC;
	HBITMAP m_hOldBitmap, m_hBitmap;

	vector<cVector3> m_vecVertex;	//������ ������ ������ �뵵
	vector<DWORD> m_vecIndex;	//������ ���ڸ� �ű� ��

	cVector3 m_directionVector;
	cMatrix m_matMove;
	cMatrix m_matRotateY;
	cMatrix m_matWorld;
	cMatrix m_matView;
	cMatrix m_matProj;
	cMatrix m_matViewport;
	cMatrix m_matScale;

	cVector3 m_vEye;
	cVector3 m_vLookAt;
	cVector3 m_vUp;

	vector<cVector3> m_vecLineVertex;	//�� ���� ���� ����
	cVector3 m_vPosition;
	POINT m_ptPrevMouse;	//���� ��ġ
	bool m_isLButtonDown;	//���콺�� ���� ����
	float m_fCameraDistance;	//ī�޶��� �Ÿ�

	cVector3 m_vCamRotAngle;	//ī�޶� ȸ�� ����
	cVector3 m_vAxis_X_TextPosition;	//x�� �� ���� �ڽ� ��ġ
	cVector3 m_vAxis_Z_TextPosition;

	float m_fBoxRotY;	//�ڽ� ȸ����
	cVector3 m_vBoxDirection;	//�ڽ� ����


	float vEye_x;
	float vEye_y;
	float size;


public:
	cMainGame();
	~cMainGame();

	void SetUp();
	void Update();
	void Render(HDC hdc);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


	void SetGrid();
	void DrawGrid();

	void Update_Scale();
	void Update_Move();
	void Update_Rotation();
};

