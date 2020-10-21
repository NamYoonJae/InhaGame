#pragma once
class cTerrain
{
private:
	vector<ST_PNT_VERTEX> m_vecTriangleVertex;
	vector<ST_PNT_VERTEX> m_vecVertex;
	
	LPDIRECT3DTEXTURE9 m_pTexture;

	vector<ST_PNT_VERTEX> m_vecHeight;

public:
	cTerrain();
	~cTerrain();

	void Setup_Terrian();
	void Render_Terrian();

	void SetMap();

};

