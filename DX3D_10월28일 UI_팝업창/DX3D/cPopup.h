#pragma once
class cButton;

class cPopup
{

protected:
	enum
	{
		enum_ButtonOff = 0,
		enum_ButtonOn = 1,
		enum_ButtonHold = 2,
	};
	
	LPD3DXSPRITE m_pSprite;
	D3DXIMAGE_INFO m_stImageInfo;
	LPDIRECT3DTEXTURE9 m_pTextureUI;

	LPD3DXFONT m_pFont;

	cButton* m_pButton;
	cButton* m_pButton_Yes;	//yes버튼이면서 노멀상태
	cButton* m_pButton_No;	//no버튼이면서 노멀상태

	cButton* m_pButton_On;	//마우스 올린 이미지
	cButton* m_pButton_Hold;	//버튼이 클릭된 상태 이미지

	bool m_isLButtonDown;
	POINT m_ptPrevMouse;


public:
	cPopup();
	~cPopup();

	virtual void Setup(char* szFolder, char* szFileName);
	virtual void Update();
	virtual void Render();


	void FontCreate();
	void Text_Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

