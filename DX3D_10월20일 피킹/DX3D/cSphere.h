#pragma once
class cSphere
{
protected:
	LPD3DXMESH m_pMeshSphere;
	D3DMATERIAL9 m_stMtlSphere;


public:
	D3DXVECTOR3 center;
	float radius;
	bool picked;

	cSphere();
	~cSphere();

	void Setup(float centerZ);
	void Update();
	void Render();
};

