#pragma once
class cMainGame
{
private:
	HDC m_MemDC;
	HBITMAP m_hOldBitmap, m_hBitmap;

	vector<cVector3> m_vecVertex;	//각각의 정점을 저장할 용도
	vector<DWORD> m_vecIndex;	//정점에 숫자를 매길 것

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

	vector<cVector3> m_vecLineVertex;	//각 선에 대한 정점
	cVector3 m_vPosition;
	POINT m_ptPrevMouse;	//이전 위치
	bool m_isLButtonDown;	//마우스가 눌린 여부
	float m_fCameraDistance;	//카메라의 거리

	cVector3 m_vCamRotAngle;	//카메라 회전 각도
	cVector3 m_vAxis_X_TextPosition;	//x축 에 대한 박스 위치
	cVector3 m_vAxis_Z_TextPosition;

	float m_fBoxRotY;	//박스 회전량
	cVector3 m_vBoxDirection;	//박스 방향


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

