#pragma once

class Charactor
{

protected:
	int c_CenterX, c_CenterY;
	double c_R;
	int c_Direction;
	int c_move;
	int c_StartX;
	int c_StartY;
	COLORREF c_Color;

public:
	Charactor();
	Charactor(int x, int y);
	~Charactor();

	void Draw(HDC hdc);
	void Move(HDC hdc, int direction, HWND hWnd);
	int GetCenterX();
	int GetCenterY();

};

class Enemy
{

protected:
	int x, y;

public:


};


