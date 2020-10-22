#pragma once
class cXFile
{
private:
	ID3DXMesh* m_Mesh = 0;
	vector<D3DMATERIAL9> m_vecMtrls;
	vector<IDirect3DTexture9*> m_Textures;

	ID3DXBuffer* m_pAdjBuffer = 0;
	ID3DXBuffer* m_pMtrlBuffer = 0;
	DWORD numMtrls = 0;

public:


	cXFile();
	~cXFile();

	void Setup();
	void Render();
};

