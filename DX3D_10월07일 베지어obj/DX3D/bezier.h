#pragma once
#include "cCubeMan.h"
class cCubeMan;

class bezier
{
protected:
	vector <ST_PC_VERTEX> m_vecVertexGreen;
	vector <ST_PC_VERTEX> m_vecVertexRed;
	D3DXVECTOR3 center;
	D3DXMATRIXA16				m_matWorld;

	cCubeMan* m_pCubeMan;

public:
	bezier();
	~bezier();

	void Setup();
	void Update();
	void Render();

	vector<ST_PC_VERTEX> GetVertexGreen();

};

