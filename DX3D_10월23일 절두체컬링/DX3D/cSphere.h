#pragma once
class cSphere
{
protected:
	LPD3DXMESH m_pMeshSphere;
	D3DMATERIAL9 m_stMtlSphere;
	D3DXVECTOR3 center;
	float radius;
	bool picked;

public:

	cSphere();
	~cSphere();

	void Setup(float centerX, float centerY, float centerZ);
	void Update();
	void Render();
};

