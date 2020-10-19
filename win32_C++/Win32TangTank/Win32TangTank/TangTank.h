#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include <cmath>

#define block_R 20
#define MAPSIZE 21
#define SPEED 5

using namespace std;

class cBlock 
{
protected:
	POINT point[4];
	int b_centerX;
	int b_centerY;
	int collisionNum; //충돌횟수 10이며 충돌시마다 --
	int state;	//외부 내부 블럭 판별

public:

	cBlock();
	cBlock(int x, int y, int coll, int st);
	~cBlock();

	void DrawBlock(HDC memDC);
	int GetCenterX();
	int GetCenterY();
	int GetState();
	int GetcollosionNum();
	void SetCollisionNum();

};

class cTankBody
{
protected:

	
	float tb_startX;
	float tb_startY;
	float tb_centerX;
	float tb_centerY;
	

	float tb_angle;
	int tb_speed;
	int tb_backSpeed;

	int tb_r;

	int sprite_xStart;
	int sprite_yStart;
	int sprite_xEnd;
	int sprite_yEnd;

	POINT tankPoint[4];

public:
	cTankBody();
	cTankBody(int i, int j);
	~cTankBody();

	void DrawTankBody(HDC hdc);
	void MoveTankBody(string key);
	int CollisionCheck(HDC hdc, float bx, float by, int br);
	float GetCenterX();
	float GetCenterY();
	bool BlockTankCollisionCheck();
	void DrawExplosion(HDC hdc, int xStart, int yStart);
};


class cTankHead
{
protected:


	float th_startX;
	float th_startY;
	float th_centerX;
	float th_centerY;

	float th_angle;
	int th_speed;
	int th_backSpeed;

	float sprite_xStart;
	float sprite_yStart;
	float sprite_xEnd;
	float sprite_yEnd;

	int th_bulletCount;
	int th_bulletLimit;

	int th_r;

	
public:
	cTankHead();
	cTankHead(int i, int j);
	~cTankHead();

	void DrawTankHead(HDC hdc);
	void MoveTankHead(string key);
	float GetTankHeadCenterX();
	float GetTankHeadCenterY();
	int GetTankHeadAngle();
	int GetBulletCount();
	void SetBulletCount();
	int GetBulletLimit();
	void DecreaseBulletCount();

};

class cBullet 
{
protected:
	float bullet_centerX;
	float bullet_centerY;
	int bullet_R;
	float move_MaxX;
	float move_MaxY;
	int collision_Direction;
	float collision_BlockX;
	float collision_BlockY;
	int collision_xNum;
	int collision_yNum;


	int bullet_Angle;
	int bullet_Speed;
	int bullet_Collision;


public:
	cBullet();
	cBullet(float x, float y, int angle);
	~cBullet();

	void DrawBullet(HDC hdc);
	void MoveBullet();
	void Collision_Ray();
	void ChagneAngle();
	void Collision();
	int GetCollision();
	int GetBulletAngle();

	float GetBulletCenterX();
	float GetBulletCenterY();
	float GetBulletMoveMaxX();
	float GetBulletMoveMaxY();
	int GetBulletR();
	
	void SetBulletCollision();

};