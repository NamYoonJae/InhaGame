#pragma once


class cSpace 
{
protected:
	int m_centerX, m_centerY;
	double m_r;
	double m_moveX;
	double m_moveY;

public:
	cSpace();
	~cSpace();


};


class cBlock : public cSpace// »ç°¢Çü
{

protected:

	POINT blockPoint[4];

public:
	cBlock();
	cBlock(int x, int y);
	~cBlock();

	void Draw(HDC hdc);
	void Move(HDC hdc, double y);
	int GetCenterX();
	int GetCenterY();
	double GetR();
	BOOL Collision();

};


class cCannon : public cSpace
{
protected:
	POINT cannon[4];
	double c_width;
	double c_height;
	double c_angle;
	int c_angleCount;

public:
	cCannon();
	~cCannon();


	void Draw(HDC hdc);
	void move(HDC hdc, int Direction);

};


class cBullet : public cSpace
{
protected:
	double b_angle;

	double b_r;

public:
	cBullet();
	~cBullet();

	void Draw(HDC hdc);
	int move(HDC hdc, int right);
	BOOL collision();

};
