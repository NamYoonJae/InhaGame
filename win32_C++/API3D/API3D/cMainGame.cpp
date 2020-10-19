#include "stdafx.h"
#include "cMainGame.h"

cMainGame::cMainGame()
	:m_hBitmap(NULL)
	, m_vEye(0, 0, -5)
	, m_vLookAt(0, 0, 0)
	, m_vUp(0, 1, 0)
	,m_vPosition(0, 0, 0)
	,m_fCameraDistance(5.0f)
	,m_isLButtonDown(false)
	,m_vCamRotAngle(0, 0, 0)
	,m_fBoxRotY(0.0f)
	,m_vBoxDirection(0,0,1)
{
	vEye_x = 0;
	vEye_y = 5.0f;

	m_ptPrevMouse.x = 0;
	m_ptPrevMouse.y = 0;
	size = 1;
}


cMainGame::~cMainGame()
{
	SelectObject(m_MemDC, m_hOldBitmap);
	DeleteObject(m_hBitmap);
	DeleteDC(m_MemDC);
}

void cMainGame::SetUp()
{
	HDC hdc = GetDC(g_hWnd);
	m_MemDC = CreateCompatibleDC(hdc);

	RECT rc;
	GetClientRect(g_hWnd, &rc);
	m_directionVector = cVector3(0, 0, 1);
	m_hBitmap = CreateCompatibleBitmap(hdc, rc.right, rc.bottom);
	m_hOldBitmap = (HBITMAP)SelectObject(m_MemDC, m_hBitmap);
	ReleaseDC(g_hWnd, hdc);

	m_vecVertex.push_back(cVector3(-1.0f, -1.0f, -1.0f));
	m_vecVertex.push_back(cVector3(-1.0f,  1.0f, -1.0f));
	m_vecVertex.push_back(cVector3( 1.0f,  1.0f, -1.0f));
	m_vecVertex.push_back(cVector3( 1.0f, -1.0f, -1.0f));

	m_vecVertex.push_back(cVector3(-1.0f, -1.0f,  1.0f));
	m_vecVertex.push_back(cVector3(-1.0f,  1.0f,  1.0f));
	m_vecVertex.push_back(cVector3( 1.0f,  1.0f,  1.0f));
	m_vecVertex.push_back(cVector3( 1.0f, -1.0f,  1.0f));

	//앞 면 삼각형 두 개
	m_vecIndex.push_back(0);
	m_vecIndex.push_back(1);
	m_vecIndex.push_back(2);

	m_vecIndex.push_back(0);
	m_vecIndex.push_back(2);
	m_vecIndex.push_back(3);

	//뒷 면 삼각형 두 개
	m_vecIndex.push_back(4);
	m_vecIndex.push_back(6);
	m_vecIndex.push_back(5);

	m_vecIndex.push_back(4);
	m_vecIndex.push_back(7);
	m_vecIndex.push_back(6);

	//왼쪽
	m_vecIndex.push_back(4);
	m_vecIndex.push_back(5);
	m_vecIndex.push_back(1);

	m_vecIndex.push_back(4);
	m_vecIndex.push_back(1);
	m_vecIndex.push_back(0);

	//오른쪽
	m_vecIndex.push_back(3);
	m_vecIndex.push_back(2);
	m_vecIndex.push_back(6);

	m_vecIndex.push_back(3);
	m_vecIndex.push_back(6);
	m_vecIndex.push_back(7);

	//위
	m_vecIndex.push_back(1);
	m_vecIndex.push_back(5);
	m_vecIndex.push_back(6);

	m_vecIndex.push_back(1);
	m_vecIndex.push_back(6);
	m_vecIndex.push_back(2);


	//아래
	m_vecIndex.push_back(4);
	m_vecIndex.push_back(0);
	m_vecIndex.push_back(3);

	m_vecIndex.push_back(4);
	m_vecIndex.push_back(3);
	m_vecIndex.push_back(7);

	m_matWorld = cMatrix::Identity(4);
	m_matView = cMatrix::Identity(4);
	m_matProj = cMatrix::Identity(4);
	m_matViewport = cMatrix::Identity(4);
	m_matMove = cMatrix::Identity(4);

	SetGrid();

}

void cMainGame::Update()
{
	Update_Scale();
	Update_Rotation();
	Update_Move();
	


	RECT rc;
	GetClientRect(g_hWnd, &rc);

	//카메라 앵글에 관한 설정
	cMatrix matRX = cMatrix::RotationX(m_vCamRotAngle.get_x());
	cMatrix matRY = cMatrix::RotationY(m_vCamRotAngle.get_y());
	cMatrix matR = matRX * matRY;

	m_vEye = cVector3(0.0f, m_fCameraDistance, -m_fCameraDistance);
	m_vEye = cVector3::Transformcoord(m_vEye, matR);
	
	//m_vLookAt = cVector3(0.0f, 0.0f, 0.0f);
	m_vLookAt = m_vPosition;
	m_vEye = m_vEye + m_vPosition;

	matR = cMatrix::RotationY(m_fBoxRotY);
	m_vBoxDirection = cVector3(0, 0, 1);
	m_vBoxDirection = cVector3::Transformcoord(m_vBoxDirection, matR);

	m_matScale = cMatrix::Scale(size);

	m_matWorld = m_matScale * matR * cMatrix::Translation(m_vPosition);
	m_matRotateY = cMatrix::RotationY(changeAngle);
	m_matView = cMatrix::View(m_vEye, m_vLookAt, m_vUp);
	m_matProj = cMatrix::Projection(M_PI/4.0f, rc.right / (float)rc.bottom, 1.0f, 1000.0f);
	m_matViewport = cMatrix::Viewport(0, 0, rc.right, rc.bottom, 0, 1);
	

}

void cMainGame::Render(HDC hdc)
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	PatBlt(m_MemDC, rc.left, rc.top, rc.right, rc.bottom, WHITENESS);

	cMatrix matWVP = m_matWorld * m_matView * m_matProj;

	for (size_t i = 0; i < m_vecIndex.size(); i += 3) 
	{
		cVector3 v1 = m_vecVertex[m_vecIndex[i + 0]];
		cVector3 v2 = m_vecVertex[m_vecIndex[i + 1]];
		cVector3 v3 = m_vecVertex[m_vecIndex[i + 2]];

		v1 = cVector3::Transformcoord(v1, m_matRotateY);
		v2 = cVector3::Transformcoord(v2, m_matRotateY);
		v3 = cVector3::Transformcoord(v3, m_matRotateY);

		v1 = cVector3::Transformcoord(v1, m_matMove);
		v2 = cVector3::Transformcoord(v2, m_matMove);
		v3 = cVector3::Transformcoord(v3, m_matMove);

		v1 = cVector3::Transformcoord(v1, matWVP);
		v2 = cVector3::Transformcoord(v2, matWVP);
		v3 = cVector3::Transformcoord(v3, matWVP);

		v1 = cVector3::Transformcoord(v1, m_matViewport);
		v2 = cVector3::Transformcoord(v2, m_matViewport);
		v3 = cVector3::Transformcoord(v3, m_matViewport);


		//BackFaceCulling
		cVector3 result;
		cVector3 crossResult;
		cVector3 dotResult;
		cVector3 result1 = (v2 - v1);
		cVector3 result2 = (v3 - v1);
		crossResult = crossResult.Cross(result1, result2);
		if (dotResult.Dot(crossResult, m_vEye) < 0 && m_vEye.get_z() <= 0.0001f || dotResult.Dot(crossResult, m_vEye) >= 0 && m_vEye.get_z() >= 0.0001f)
		{
			MoveToEx(m_MemDC, v1.get_x(), v1.get_y(), NULL);
			LineTo(m_MemDC, v2.get_x(), v2.get_y());
			LineTo(m_MemDC, v3.get_x(), v3.get_y());
			LineTo(m_MemDC, v1.get_x(), v1.get_y());
		};

	}

	/*
	vector<cVector3> GridColumn;
	vector<cVector3> GridRow;
	vector<cVector3> polygon;
	vector<cVector3> coord;


	for (cVector3 poly : polygon)
	{
		MoveToEx(m_MemDC, coord[poly.get_x()].get_x(), coord[poly.get_x()].get_y(), NULL);
		LineTo(m_MemDC, coord[poly.get_y()].get_x(), coord[poly.get_y()].get_y());
		LineTo(m_MemDC, coord[poly.get_z()].get_x(), coord[poly.get_z()].get_y());
		LineTo(m_MemDC, coord[poly.get_x()].get_x(), coord[poly.get_x()].get_y());
	}

	for (int i = -9; i < 10; i += 2)
	{
		GridColumn.emplace_back(i, 0, 9);
		GridColumn.emplace_back(i, 0, -9);
	}

	for (int i = -9; i < 10; i += 2)
	{
		GridRow.emplace_back(9, 0, i);
		GridRow.emplace_back(-9, 0, i);
	}

	for (int i = 0; i < GridColumn.size(); i++)
	{
		GridColumn[i] = cVector3::Transformcoord(GridColumn[i], matWVP);
		GridColumn[i] = cVector3::Transformcoord(GridColumn[i], m_matViewport);
	}

	for (int i = 0; i < GridRow.size(); i++)
	{
		GridRow[i] = cVector3::Transformcoord(GridRow[i], matWVP);
		GridRow[i] = cVector3::Transformcoord(GridRow[i], m_matViewport);
	}

	for (int i = 0; i < 20; i += 2)
	{
		MoveToEx(m_MemDC, GridColumn[i].get_x(), GridColumn[i].get_y(), NULL);
		LineTo(m_MemDC, GridColumn[i + 1].get_x(), GridColumn[i + 1].get_y());
	}

	for (int i = 0; i < 20; i += 2)
	{
		MoveToEx(m_MemDC, GridRow[i].get_x(), GridRow[i].get_y(), NULL);
		LineTo(m_MemDC, GridRow[i + 1].get_x(), GridRow[i + 1].get_y());
	}
	*/

	DrawGrid();

	BitBlt(hdc, 0, 0, rc.right, rc.bottom, m_MemDC, 0, 0, SRCCOPY);

}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
	case WM_LBUTTONDOWN:
		m_ptPrevMouse.x = LOWORD(lParam);
		m_ptPrevMouse.y = HIWORD(lParam);
		m_isLButtonDown = true;

		break;

	case WM_LBUTTONUP:
		m_isLButtonDown = false;
		break;

	case WM_MOUSEMOVE:
		switch (wParam)
		{
		case MK_LBUTTON:
			if (m_isLButtonDown) 
			{
				POINT ptCurMouse;
				ptCurMouse.x = LOWORD(lParam);
				ptCurMouse.y = HIWORD(lParam);
				float fDeltaX = (float)ptCurMouse.x - m_ptPrevMouse.x;
				float fDeltaY = (float)ptCurMouse.y - m_ptPrevMouse.y;
				m_vCamRotAngle.set_y(m_vCamRotAngle.get_y() + fDeltaX / 100.f);
				m_vCamRotAngle.set_x(m_vCamRotAngle.get_x() + fDeltaY / 100.f);
				
				if (m_vCamRotAngle.get_x() < -M_PI / 2.0f + 0.0001f)
					m_vCamRotAngle.set_x(-M_PI / 2.0f + 0.0001f);
				
				if (m_vCamRotAngle.get_x() > M_PI / 2.0f - 0.0001f)
					m_vCamRotAngle.set_x(M_PI / 2.0f - 0.0001f);
				
				m_ptPrevMouse = ptCurMouse;
			}
			
			break;

		default:
			break;
		}
		
		break;
	
	case WM_MOUSEWHEEL:

		m_fCameraDistance -= (GET_WHEEL_DELTA_WPARAM(wParam) / 30.0f);
		if (abs(m_fCameraDistance) < 0.0001f)
			m_fCameraDistance = 0.0001f;

		break;


		
	case WM_KEYDOWN:
	{

		switch (wParam)
		{
		case VK_LEFT:
			changeAngle = changeAngle - 5;
			m_directionVector = cVector3::Transformcoord(m_directionVector, cMatrix::RotationY(-5)).Normalize();
			break;

		case VK_RIGHT:
			changeAngle = changeAngle + 5;
			m_directionVector = cVector3::Transformcoord(m_directionVector, cMatrix::RotationY(+5)).Normalize();
			break;

		case VK_UP:
			m_matMove = m_matMove * cMatrix::Translation(m_directionVector);

			break;

		case VK_DOWN:


			break;

		default:
			break;
		}
	}
	break;
	

	default:
		break;
	}

}

void cMainGame::SetGrid()
{
	int nNumHalfTile = 5;
	float fInterval = 1.0f;
	float fMax = nNumHalfTile * fInterval;
	float fMin = -nNumHalfTile * fInterval;

	for (int i = 1; i <= nNumHalfTile; ++i) 
	{
		m_vecLineVertex.push_back(cVector3(fMin, 0, i * fInterval));
		m_vecLineVertex.push_back(cVector3(fMax, 0, i * fInterval));

		m_vecLineVertex.push_back(cVector3(fMin, 0, -i * fInterval));
		m_vecLineVertex.push_back(cVector3(fMax, 0, -i * fInterval));

		m_vecLineVertex.push_back(cVector3(i * fInterval, 0, fMin));
		m_vecLineVertex.push_back(cVector3(i * fInterval, 0, fMax));

		m_vecLineVertex.push_back(cVector3(-i * fInterval, 0, fMin));
		m_vecLineVertex.push_back(cVector3(-i * fInterval, 0, fMax));

		
	}

	m_vecLineVertex.push_back(cVector3(0, 0, fMin));
	m_vecLineVertex.push_back(cVector3(0, 0, fMax));

	m_vecLineVertex.push_back(cVector3(fMin, 0, 0));
	m_vecLineVertex.push_back(cVector3(fMax, 0, 0));

	m_vAxis_X_TextPosition = cVector3(fMax, 0, 0);
	m_vAxis_Z_TextPosition = cVector3(0, 0, fMax);

}

void cMainGame::DrawGrid()
{
	cMatrix mat = m_matView * m_matProj * m_matViewport;

	for (size_t i = 0; i < m_vecLineVertex.size(); i +=2) 
	{
		cVector3 v1 = m_vecLineVertex[i + 0];
		cVector3 v2 = m_vecLineVertex[i + 1];

		v1 = cVector3::Transformcoord(v1, mat);
		v2 = cVector3::Transformcoord(v2, mat);

		MoveToEx(m_MemDC, v1.get_x(), v1.get_y(), NULL);
		LineTo(m_MemDC, v2.get_x(), v2.get_y());
	}

	cVector3 v = m_vAxis_X_TextPosition;
	v = cVector3::Transformcoord(v, mat);
	TextOut(m_MemDC, v.get_x(), v.get_y(), (LPCWSTR)"X", 1);

	v = m_vAxis_Z_TextPosition;
	v = cVector3::Transformcoord(v, mat);
	TextOut(m_MemDC, v.get_x(), v.get_y(), (LPCWSTR)"Z", 1);

}

void cMainGame::Update_Scale()
{
	if (GetKeyState('1') & 0x8000)
	{
		if (size >= 2.5f)
		{
			size = 2.5f;
		}
		else 
		{
			size += 0.1f;
		}
	}

	if (GetKeyState('2') & 0x8000)
	{
		if (size <= 0.1f) 
		{
			size = 0.1f;
		}
		else 
		{
			size -= 0.1;
		}
	}
}

void cMainGame::Update_Move()
{
	if (GetKeyState('W') & 0x8000) 
	{
		m_vPosition = m_vPosition + (m_vBoxDirection * 0.1f);
	}

	if (GetKeyState('S') & 0x8000)
	{
		m_vPosition = m_vPosition - (m_vBoxDirection * 0.1f);
	}

}

void cMainGame::Update_Rotation()
{
	if (GetKeyState('A') & 0x8000)
	{
		m_fBoxRotY -= 0.1f;
	}

	if (GetKeyState('D') & 0x8000)
	{
		m_fBoxRotY += 0.1f;
	}
}


