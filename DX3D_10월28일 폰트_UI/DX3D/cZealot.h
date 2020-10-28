#pragma once
#include "cCharacter.h"

class cSkinnedMesh;
class cOBB;

class cZealot
{
public:
	cZealot();
	virtual ~cZealot(void);

	void Setup();
	void Update(iMap* pMap);
	void Render(D3DCOLOR c = D3DCOLOR_XRGB(255, 255, 255));

private:
	cSkinnedMesh* m_pSkinnedMesh;
	cOBB* m_pOBB;
	Synthesize_Add_Ref(cCharacter*, m_pCharacterController, CharacterController);

	cOBB* GetOBB();
};


