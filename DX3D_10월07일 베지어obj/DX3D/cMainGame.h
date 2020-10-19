#pragma once
class cCubePC;
class cCamera;
class cGrid;
class cCubeMan;
class cLight;
class bezier;
class cObjLoad;

class cMainGame
{
private:
	//vector<ST_PC_VERTEX> m_vecLineVertex;
	//vector<ST_PC_VERTEX > m_vecTriangleVertex;

	cCubePC*	m_pCubePC;
	cCamera*	m_pCamera;
	cGrid*		m_pGrid;
	cCubeMan* m_pCubeMan;
	cCubeMan* m_pCubeManGreen;

	cLight* m_pLight;

	bezier* m_pBezier;
	cObjLoad* m_pObjLoad;

	int lineNum;

	// >> :
	/*
	LPDIRECT3DTEXTURE9 m_pTexture;	//�ؽ��ĸ� ������ �ؽ��� ��ü
	vector<ST_PT_VERTEX> m_vecVertex;
	*/
	// << :
	
	
public:
	cMainGame();
	~cMainGame();

	void Setup();
	void Update();
	void Render();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam);


	//void Draw_Texture();

};
	