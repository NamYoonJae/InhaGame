#pragma once

#define g_pFontManager cFontManager::GetInstance()

class cFontManager
{


public:
	enum eFontType
	{
		E_DEFAULT,
		E_QUEST,
	};

	LPD3DXFONT GetFont(eFontType e);
	void Destroy();

private:
	Singletone(cFontManager);
	map<eFontType, LPD3DXFONT> m_mapFont;
};

