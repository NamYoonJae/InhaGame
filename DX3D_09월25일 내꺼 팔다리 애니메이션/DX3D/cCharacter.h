#pragma once
class cCubePC;

class cCharacter
{
private:
	std::vector<ST_PC_VERTEX> m_vecVertex;
	float m_fRotY;
	D3DXVECTOR3 m_Direction;
	D3DXVECTOR3 m_vPosition;
	D3DXMATRIXA16 m_matWorld;
	D3DXMATRIXA16 matS, matR, matT;

	cCubePC* m_pHead;
	cCubePC* m_pBody;
	cCubePC* m_ArmRight;
	cCubePC* m_ArmLeft;
	cCubePC* m_LegRight;
	cCubePC* m_LegLeft;

	vector<cCubePC*> vecCube;

public:
	cCharacter();
	~cCharacter();

	void Setup();
	void Update();
	void Render();

	D3DXVECTOR3& GetPosition();

};

