#pragma once
class cCubePC
{
private:
	std::vector<ST_PC_VERTEX>	m_vecVertex;
	D3DXVECTOR3					m_Direction;
	D3DXMATRIXA16				m_matWorld;

	float scaleX;
	float scaleY;
	float scaleZ;

public:
	cCubePC();
	~cCubePC();

	void Setup(float x, float y, float z, float positionX, float positionY, float positionZ, float sX, float sY, float sZ);
	void Update(D3DXVECTOR3 position, D3DXVECTOR3 direction, float rotationY);
	void Render();

};

