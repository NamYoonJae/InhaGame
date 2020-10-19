#pragma once
#include "cCharacter.h"
#include "bezier.h"

class cCubeNode;

class cCubeMan :
    public cCharacter
{
protected:
    cCubeNode* m_pRoot;
    D3DMATERIAL9 m_stMtl;

	vector<ST_PC_VERTEX> greenLine;
	int lineNum;

public:
    cCubeMan();
    virtual ~cCubeMan();

    virtual void Setup() override;
	void bezierSetup(vector<ST_PC_VERTEX> colorLine);
    virtual void Update() override;
    void Update2();
    virtual void Render() override;




};

