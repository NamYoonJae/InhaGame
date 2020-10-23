#pragma once
class cSkinnedMesh
{
protected:
	LPD3DXFRAME m_pRoot;
	LPD3DXANIMATIONCONTROLLER m_pAnimController;
	int nowAnimation;

	//블랜딩용 변수
	float m_fBlendTime;
	float m_fPassedBlendTime;
	bool m_isAnimBlend;


	float m_animationTimeLimit;
	float m_animationTime;

public:
	cSkinnedMesh();
	~cSkinnedMesh();

	void Setup(char* szFolder, char* szFile);
	void Update();
	void Update(LPD3DXFRAME pFrame, LPD3DXFRAME pParent);
	void Render(LPD3DXFRAME pFrame);
	void SetupBoneMatrixPtrs(LPD3DXFRAME pFrame);
	void UpdateSkinnedMesh(LPD3DXFRAME pFrame);

	void SetAnimationIndex(int index);
	void SetAnimationIndexBlend(int nIndex);

};

