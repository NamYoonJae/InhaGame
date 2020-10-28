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
	cButton* m_pButton_Yes;	//yes��ư�̸鼭 ��ֻ���
	cButton* m_pButton_No;	//no��ư�̸鼭 ��ֻ���

	cButton* m_pButton_On;	//���콺 �ø� �̹���
	cButton* m_pButton_Hold;	//��ư�� Ŭ���� ���� �̹���

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

