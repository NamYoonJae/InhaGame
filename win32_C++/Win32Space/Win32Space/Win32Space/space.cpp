#include "stdafx.h"
#include "space.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

extern vector <cBullet*> cBulletList;
extern vector <cBlock*> cBlockList;
extern double bulletCenterX;
extern double bulletCenterY;
extern double fireAngle;
extern int score;

enum
{
	enum_right = 1,
	enum_left = 2,

};

cSpace::cSpace()
{
	m_centerX = 0;
	m_centerY = 0;
	m_r = 0;
}

cSpace::~cSpace()
{
}

cCannon::cCannon()
{
	m_centerX = 213;
	m_centerY = 700;
	m_r = 80;
	c_width = 2;
	c_height = 20;
	c_angle = 0;
	c_angleCount = 0;


	cannon[0].x = m_centerX - c_width;
	cannon[0].y = m_centerY - m_r;

	cannon[1].x = m_centerX + c_width;
	cannon[1].y = m_centerY - m_r;

	cannon[2].x = m_centerX + c_width;
	cannon[2].y = m_centerY - c_height;

	cannon[3].x = m_centerX - c_width;
	cannon[3].y = m_centerY - c_height;
}

cCannon::~cCannon()
{

}

void cCannon::Draw(HDC hdc)
{

	Polygon(hdc, cannon ,4);
}

void cCannon::move(HDC hdc, int Direction)
{
	int i = 0;

	double xTmp = 0, yTmp = 0, bxTmp = 0, byTmp = 0;
	double radian =0;

	if (Direction == enum_right) 
	{

		if (c_angleCount<80)
		{
			cannon[0].x = m_centerX - c_width;
			cannon[0].y = m_centerY - m_r;

			cannon[1].x = m_centerX + c_width;
			cannon[1].y = m_centerY - m_r;

			cannon[2].x = m_centerX + c_width;
			cannon[2].y = m_centerY - c_height;

			cannon[3].x = m_centerX - c_width;
			cannon[3].y = m_centerY - c_height;

			bulletCenterX = 213;
			bulletCenterY = 700 - 80 - 4;

			c_angleCount = c_angleCount + 5;
			c_angle = 0;
			c_angle = c_angle + c_angleCount;
			fireAngle = 90 + c_angle;

			radian = M_PI / 180 * c_angleCount;

			for (i = 0; i < 4; i++)
			{
				xTmp = cos(radian) * long(cannon[i].x - m_centerX) - sin(radian) * long(cannon[i].y - m_centerY);
				yTmp = sin(radian) * long(cannon[i].x - m_centerX) + cos(radian) * long(cannon[i].y - m_centerY);

				cannon[i].x = long(xTmp + m_centerX);
				cannon[i].y = long(yTmp + m_centerY);
			}
			bxTmp = cos(radian) * long(bulletCenterX - m_centerX) - sin(radian) * long(bulletCenterY - m_centerY);
			byTmp = sin(radian) * long(bulletCenterX - m_centerX) + cos(radian) * long(bulletCenterY - m_centerY);

			bulletCenterX = long(bxTmp + m_centerX);
			bulletCenterY = long(byTmp + m_centerY);

		}

	}
	else
	{
		if (c_angleCount>-80)
		{
			cannon[0].x = m_centerX - c_width;
			cannon[0].y = m_centerY - m_r;

			cannon[1].x = m_centerX + c_width;
			cannon[1].y = m_centerY - m_r;

			cannon[2].x = m_centerX + c_width;
			cannon[2].y = m_centerY - c_height;

			cannon[3].x = m_centerX - c_width;
			cannon[3].y = m_centerY - c_height;

			c_angleCount = c_angleCount - 5;
			c_angle = 0;

			c_angle = c_angle - c_angleCount;

			fireAngle = 90 - c_angle;
			bulletCenterX = 213;
			bulletCenterY = 700 - 80 - 4;

			radian = M_PI / 180 * c_angleCount;

			for (i = 0; i < 4; i++)
			{
				xTmp = cos(radian) * long(cannon[i].x - m_centerX) - sin(radian) * long(cannon[i].y - m_centerY);
				yTmp = sin(radian) * long(cannon[i].x - m_centerX) + cos(radian) * long(cannon[i].y - m_centerY);


				cannon[i].x = long(xTmp + m_centerX);
				cannon[i].y = long(yTmp + m_centerY);

			}
			bxTmp = cos(radian) * long(bulletCenterX - m_centerX) - sin(radian) * long(bulletCenterY - m_centerY);
			byTmp = sin(radian) * long(bulletCenterX - m_centerX) + cos(radian) * long(bulletCenterY - m_centerY);
			bulletCenterX = long(bxTmp + m_centerX);
			bulletCenterY = long(byTmp + m_centerY);


		}
	}
}

cBullet::cBullet()
{
	m_centerX = bulletCenterX;
	m_centerY = bulletCenterY;
	b_r = 2;
	b_angle = fireAngle;

	double radian = M_PI / 180 * (fireAngle); //왼쪽 기능 정상

	m_moveX = cos(radian) * 20;
	m_moveY = sin(radian) * 20;

}

cBullet::~cBullet()
{
}

void cBullet::Draw(HDC hdc)
{

	Ellipse(hdc, m_centerX - 4, m_centerY - 4, m_centerX +4, m_centerY +4);
}

int cBullet::move(HDC hdc, int right)
{

	m_centerX = m_centerX - m_moveX;
	m_centerY = m_centerY - m_moveY;
	
	if (m_centerX < 0 || m_centerY < 0 | m_centerX > right) 
	{
		return 1;
	}
	

	return 0;
}

BOOL cBullet::collision()
{
	int i = 0;
	int blockCenterX = 0;
	int blockCenterY = 0;
	double between = 0;
	double r_sum = 0;

	for (i = 0; i < cBlockList.size(); i++) 
	{
		blockCenterX = cBlockList[i]->GetCenterX();
		blockCenterY = cBlockList[i]->GetCenterY();

		// 두  센터 사이의 거리가  두 도형의 반지름의 합보다 작으면 충돌
		between = sqrt(pow(blockCenterX - m_centerX, 2) + pow(blockCenterY - m_centerY, 2));
		r_sum = m_r + cBlockList[i]->GetR();

		if (r_sum >= between)
		{
			delete(cBlockList[i]);
			cBlockList.erase(cBlockList.begin() + i);
			score += 100;
			return TRUE;
		}

	}


	return FALSE;
}

cBlock::cBlock()
{

}

cBlock::cBlock(int x, int y)
{
	m_centerX = x;
	m_centerY = y;
	m_r = 25;
}

cBlock::~cBlock()
{

}

void cBlock::Draw(HDC hdc)
{
	blockPoint[0].x = m_centerX - m_r;
	blockPoint[0].y = m_centerY - m_r;

	blockPoint[1].x = m_centerX + m_r;
	blockPoint[1].y = m_centerY - m_r;

	blockPoint[2].x = m_centerX + m_r;
	blockPoint[2].y = m_centerY + m_r;

	blockPoint[3].x = m_centerX - m_r;
	blockPoint[3].y = m_centerY + m_r;

	Polygon(hdc, blockPoint, 4);

}

void cBlock::Move(HDC hdc, double y)
{
	m_moveY = y;

	m_centerY += m_moveY;

}

int cBlock::GetCenterX()
{
	return m_centerX;
}

int cBlock::GetCenterY()
{
	return m_centerY;
}

double cBlock::GetR()
{
	return m_r;
}

BOOL cBlock::Collision()
{
	int i = 0;

	if (m_centerY + m_r >= 700) 
	{
		return TRUE;
	}

	return FALSE;
}


