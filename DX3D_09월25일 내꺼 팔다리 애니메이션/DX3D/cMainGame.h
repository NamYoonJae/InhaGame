#pragma once
class cCubePC;
class cCamera;
class cGrid;
class cCharacter;

class cMainGame
{
private:
	vector<ST_PC_VERTEX> m_vecLineVertex;
	vector<ST_PC_VERTEX > m_vecTriangleVertex;

	cCharacter* m_pCharacter;
	cCubePC*	m_pCubePC;
	cCamera*	m_pCamera;
	cGrid*		m_pGrid;
	/*
	vector<ST_PC_VERTEX > m_vecIndex;
	vector<ST_PC_VERTEX > m_vecVertex;

	D3DXMATRIXA16 matRotateY;
	D3DXMATRIXA16 matMove;

	D3DXVECTOR3  m_Box;
	D3DXVECTOR3 m_vBoxDirection;
	*/


	float angle;

public:
	cMainGame();
	~cMainGame();

	void Setup();
	void Update();
	void Render();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam);



	/*
	void Setup_Line();
	void Draw_Line();

	void Setup_Triangle();
	void Draw_Triangle();
	*/

	/*
	void Setup_Grid();
	void Draw_Grid();
	
	void Setup_Cube();
	void Draw_Cube();

	void Onkey();
	float Length();
	*/
};

