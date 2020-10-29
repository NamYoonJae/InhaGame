#pragma once
class cCubePC;
class cCamera;
class cGrid;
class cCubeMan;
class cLight;
class cGroup;
class cFrame;
class cMtlTex;
class cSkinnedMesh;
class cFrustum;
class cZealot;
class cPopup;


class cMainGame
{
private:
	//vector<ST_PC_VERTEX> m_vecLineVertex;
	//vector<ST_PC_VERTEX > m_vecTriangleVertex;

	cCubePC*	m_pCubePC;
	cCamera*	m_pCamera;
	cGrid*		m_pGrid;

	cCubeMan* m_pCubeMan;

	cLight* m_pLight;

	// >> :
	/*
	LPDIRECT3DTEXTURE9 m_pTexture;	//�ؽ��ĸ� ������ �ؽ��� ��ü
	vector<ST_PT_VERTEX> m_vecVertex;
	*/
	// << :
	
	vector<cGroup*> m_vecGroup;
	iMap* m_pMap;

	cFrame* m_pRootFrame;

	LPD3DXMESH m_pMeshTeapot;
	LPD3DXMESH m_pMeshSphere;
	D3DMATERIAL9 m_stMtlTeapot;
	D3DMATERIAL9 m_stMtlSphere;

	LPD3DXMESH m_pObjMesh;
	vector<cMtlTex*> m_vecObjMtlTex;

	vector<ST_SPHERE> m_vecSphere;
	D3DMATERIAL9 m_stMtlNone;
	D3DMATERIAL9 m_stMtlPicked;
	D3DMATERIAL9 m_stMtlPlane;
	vector<ST_PN_VERTEX> m_vecPlaneVertex;
	D3DXVECTOR3 m_vPickedPosition;

	cSkinnedMesh* m_pSkinnedMesh;

	LPD3DXMESH m_pSphere;
	D3DMATERIAL9 m_stCullingMtl;
	vector<ST_SPHERE*> m_vecCullingSphere;
	cFrustum* m_pFrustum;

	cZealot* m_pHoldZealot;
	cZealot* m_pMoveZealot;

	LPD3DXFONT m_pFont;
	ID3DXMesh* m_p3DText;

	//UI
	LPD3DXSPRITE m_pSprite;
	D3DXIMAGE_INFO m_stImageInfo;
	LPDIRECT3DTEXTURE9 m_pTextureUI;

	enum
	{
		enum_PopupOff = 0,
		enum_PopupOn = 1,
	};

	int m_PopupState;
	cPopup* m_pPopup;


public:
	cMainGame();
	~cMainGame();

	void Setup();
	void Update();
	void Render();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam);

	//void Draw_Texture();
	void Setup_Obj();
	void Obj_Render();

	void Load_Surface();

	void Setup_MeshObject();
	void Mesh_Render();

	void Setup_PickingObj();
	void PickingObj_Render();

	void SkinnedMesh_Render();


	void Setup_HeightMap();


	void Setup_Frustum();
	void Frustum_Render();

	void Setup_OBB();
	void OBB_Render();

	void Create_Font();
	void Text_Render();


	void Setup_UI();
	void UI_Render();
};

	