#pragma once
#include <vector>

using namespace std;

class cShape
{
	
protected:
	int m_centerX, m_centerY;
	long m_rSize;
	int m_moveX;
	int m_moveY;


	int m_spin;
	int m_moveDirection;
	int m_Shapes;

public:
	cShape();
	~cShape();

	virtual void Draw(HDC hdc) = 0;
	virtual void Move() = 0;
	virtual void Spin() = 0;

	virtual int Collision(vector <cShape*> &shapeList, int n, RECT rt, int mode) = 0;
	virtual int GetPointCenterX() = 0;
	virtual int GetPointCenterY() = 0;
	virtual long GetPointR() = 0;
	virtual int GetMoveDirection() = 0;
	virtual void SetMoveDirection(int enum_num) = 0;
	virtual int GetMoveX() = 0;
	virtual int GetMoveY() = 0;
	virtual void SetMove(int enum_numX, int enum_numY) = 0;
	virtual int GetShapes() = 0;
	virtual void SetR() = 0;
};

class cCircle : public cShape
{

private:

	int c_x1, c_y1, c_x2, c_y2;


public:
	cCircle();
	cCircle(int x, int y, int r);
	cCircle(int x, int y, int r, int z);
	~cCircle();

	void Draw(HDC hdc);
	void Move();
	void Spin();

	int Collision(vector<cShape*> &shapeList, int n, RECT rt, int mode);
	int GetPointCenterX();
	int GetPointCenterY();
	long GetPointR();
	int GetMoveDirection();
	void SetMoveDirection(int enum_num);
	int GetMoveX();
	int GetMoveY();
	void SetMove(int enum_numX, int enum_numY);
	int GetShapes();
	void SetR();
};

class cRect : public cShape
{

protected:
	POINT rectPoint[4];
public:
	cRect();
	cRect(int x, int y, int r);
	cRect(int x, int y, int r, int z);
	~cRect();

	void Draw(HDC hdc);
	void Move();
	void Spin();

	int Collision(vector<cShape*> &shapeList, int n, RECT rt, int mode);
	int GetPointCenterX();
	int GetPointCenterY();
	long GetPointR();
	int GetMoveDirection();
	void SetMoveDirection(int enum_num);
	int GetMoveX();
	int GetMoveY();
	void SetMove(int enum_numX, int enum_numY);
	int GetShapes();
	void SetR();
};

class cStar : public cShape
{

protected:
	POINT point[10];
	long a, b, c, d, e, f, k;
	long s_r2;
	long s_x, s_y;

public:
	cStar();
	cStar(int x, int y, int r);
	cStar(int x, int y, int r, int z);
	~cStar();

	void Draw(HDC hdc);
	void Move();
	void star();
	void Spin();

	int Collision(vector<cShape*> &shapeList, int n, RECT rt, int mode);
	int GetPointCenterX();
	int GetPointCenterY();
	long GetPointR();
	int GetMoveDirection();
	void SetMoveDirection(int enum_num);
	int GetMoveX();
	int GetMoveY();
	void SetMove(int enum_numX, int enum_numY);
	int GetShapes();
	void SetR();
};