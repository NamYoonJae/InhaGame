#pragma once
#include "cObject.h"
#include "cMtlTex.h"
class cFrame :
	public cObject
{
private:
	Synthesize_Pass_by_Ref(vector<ST_PNT_VERTEX>, m_vecVertex, Vertex);
	
	Synthesize_Pass_by_Ref(vector<ST_ABC_INDEX>, m_vecIndex, Index);
	Synthesize_Pass_by_Ref(vector<D3DXVECTOR3>, m_vevV, VecV);

	Synthesize_Pass_by_Ref(D3DXMATRIXA16, m_matLocalTM, LocalTM);
	Synthesize_Pass_by_Ref(D3DXMATRIXA16, m_matWorldTM, WorldTM);

	Synthesize_Add_Ref(cMtlTex*, m_pMtlTex, MtlTex);
	vector<cFrame*> m_vecChild;

	Synthesize_Pass_by_Ref(vector<ST_POS_SAMPLE>, m_vecPosTrack, PosTrack);
	Synthesize_Pass_by_Ref(vector<ST_ROT_SAMPLE>, m_vecRotTrack, RotTrack);

public:
	cFrame();
	~cFrame();
	void Update(int nKeyFrame, D3DXMATRIXA16* pmatParent);
	void Render();
	void AddChild(cFrame* pChild);
	void Destroy();
	void CalcOriginLocalTM(D3DXMATRIXA16* pmatParent);

	void CalcLocalT(IN int nKeyFrame, OUT D3DXMATRIXA16& matT);
	void CalcLocalR(IN int nKeyFrame, OUT D3DXMATRIXA16& matR);


	DWORD m_dwFirstFrame;
	DWORD m_dwLastFrame;
	DWORD m_dwFrameSpeed;
	DWORD m_dwTicksPerFrame;

	int GetKeyFrame();

private:
	int m_nNumTri;
	LPDIRECT3DVERTEXBUFFER9 m_pVB;
	LPDIRECT3DINDEXBUFFER9 m_pIB;

public:
	void BuildVB(vector<ST_PNT_VERTEX>&vecVertex);
	void BuildIB(vector<ST_ABC_INDEX>&vecABCIndex, vector<D3DXVECTOR3>&vecV);
};

