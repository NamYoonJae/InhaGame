#pragma once
class cSkinnedMesh;

class cOBB
{

private:
	D3DXVECTOR3 m_vOriCenterPos;	//초기 센터 값
	D3DXVECTOR3 m_vOriAxisDir[3];

	D3DXVECTOR3 m_vCenterPos;	//변동된 센터 값
	D3DXVECTOR3 m_vAxisDir[3];
	float m_fAxisLen[3];
	
	float m_fAxisHalfLen[3];

	D3DXMATRIXA16 m_matWorldTM;


public:
	cOBB();
	~cOBB();
	
	void Setup(cSkinnedMesh* pSkinnedMesh);
	void Update(D3DXMATRIXA16 * pmatWorld);
	static bool IsCollision(cOBB* pOBB1, cOBB* pOBB2);

	void OBBBOX_Render(D3DCOLOR c);

};

