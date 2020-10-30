#pragma once
#include "cPopup.h"
class cButton :
	public cPopup
{
	int m_state;

public:
	cButton();
	~cButton();

	void Setup(char* szFolder, char* szFileName);
	void Update();
	void Render();

	void Render(float positionX, float positionY);

	int GetButtonState();
	void ButtonStateChange(int state);
	
};

