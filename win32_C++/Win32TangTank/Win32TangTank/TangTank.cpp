
#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "TangTank.h"
#include <iostream>
#include <string>
#include <vector>

#define SPIN_ANGLE 30

using namespace std;


extern HBITMAP hTankImage;
extern BITMAP bitTank;
extern HBITMAP hExplosion;
extern BITMAP bitExplosion;

extern cBlock* MapArray[MAPSIZE][MAPSIZE];
extern vector<cTankBody*> vTankBody;
extern vector<cBullet*> vBullet;

enum
{
	enum_in_block = 0,
	enum_out_block = 1
};

float Radian(float angle);


cBlock::cBlock()
{
	b_centerX = 0;
	b_centerY = 0;
	collisionNum = 10;
	state = enum_in_block;
}

cBlock::cBlock(int x, int y, int coll, int st)
{
	b_centerX = x;
	b_centerY = y;

	point[0].x = b_centerX - block_R;
	point[0].y = b_centerY - block_R;
	point[1].x = b_centerX + block_R;
	point[1].y = b_centerY - block_R;
	point[2].x = b_centerX + block_R;
	point[2].y = b_centerY + block_R;
	point[3].x = b_centerX - block_R;
	point[3].y = b_centerY + block_R;

	collisionNum = coll;
	state = st;
}

cBlock::~cBlock()
{

}

void cBlock::DrawBlock(HDC memDC)
{
	Polygon(memDC, point, 4);
}

int cBlock::GetCenterX()
{
	return b_centerX;
}

int cBlock::GetCenterY()
{
	return b_centerY;
}


int cBlock::GetState()
{
	return state;
}

int cBlock::GetcollosionNum()
{
	return collisionNum;
}

void cBlock::SetCollisionNum()
{
	if (state == 0) 
	{
		collisionNum--;
	}
	

}




cTankBody::cTankBody()
{
	tb_centerX = 170;
	tb_centerY = 150;
	tb_angle = 90;
	tb_speed = 10;

	tb_startX = tb_centerX - 15; // centerY 에서 값 계산 
	tb_startY = tb_centerY - 15; // centerY 에서 값 계산 

	sprite_xStart = 60;
	sprite_yStart = 70;
	sprite_xEnd = 34;
	sprite_yEnd = 36;
}

cTankBody::cTankBody(int i, int j)
{
	tb_centerX = (i - 2) * (block_R * 2) + 170;
	tb_centerY = (j - 2) * (block_R * 2) + 150;

	tb_angle = 90;
	tb_speed = 7;
	tb_backSpeed = 5;

	tb_startX = tb_centerX - 26;
	tb_startY = tb_centerY - 24;

	sprite_xStart = 45;
	sprite_yStart = 60;
	sprite_xEnd = 60;
	sprite_yEnd = 60;	
}


cTankBody::~cTankBody()
{
}

void cTankBody::DrawTankBody(HDC hdc)
{

	HDC hMemDC;
	HBITMAP hOldBitmap;
	int bx, by;

	//탱크 몸체
	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hTankImage);

		bx = bitTank.bmWidth / 20;
		by = bitTank.bmHeight / 20;

		TransparentBlt(hdc, tb_startX, tb_startY, bx, by, hMemDC, sprite_xStart, sprite_yStart, sprite_xEnd, sprite_yEnd, RGB(255, 0, 255));

		SelectObject(hMemDC, hOldBitmap);
	}
	DeleteDC(hMemDC);


	Polygon(hdc, tankPoint, 4);

	
}

void cTankBody::MoveTankBody(string key)
{

	double vectorX = 0;
	double vectorY = 0;
	double xTmp = 0;
	double yTmp = 0;
	
	sprite_xStart += 74;

	//벽돌인지 체크
	//탱크와 벽돌 사이의 거리가 두 반지름 합보다 작으면 이동 불가

	




	if (key == "W")
	{

		vectorX = cos(Radian(tb_angle));
		vectorY = -sin(Radian(tb_angle));

		tb_centerX -= vectorX * tb_speed;
		tb_centerY += vectorY * tb_speed;

		tb_startX = tb_centerX - 26;
		tb_startY = tb_centerY - 24;

	}
	else if (key == "S")
	{
		sprite_xStart += 74;

		vectorX = cos(Radian(tb_angle));
		vectorY = -sin(Radian(tb_angle));

		tb_centerX += vectorX * tb_backSpeed;
		tb_centerY -= vectorY * tb_backSpeed;

		tb_startX = tb_centerX - 26;
		tb_startY = tb_centerY - 24;
	}
	else if (key == "WD")
	{

		tb_angle += SPIN_ANGLE;

		vectorX = cos(Radian(tb_angle));
		vectorY = -sin(Radian(tb_angle));

		tb_startX = tb_centerX - 26;
		tb_startY = tb_centerY - 24;


	}
	else if (key == "WA")
	{

		tb_angle -= SPIN_ANGLE;

		vectorX = cos(Radian(tb_angle));
		vectorY = -sin(Radian(tb_angle));

		tb_startX = tb_centerX - 26;
		tb_startY = tb_centerY - 24;

	}
	else if (key == "SD")
	{

		tb_angle -= SPIN_ANGLE;

		vectorX = cos(Radian(tb_angle));
		vectorY = -sin(Radian(tb_angle));

		tb_startX = tb_centerX - 26;
		tb_startY = tb_centerY - 24;

	}
	else if (key == "SA")
	{

		tb_angle += SPIN_ANGLE;

		vectorX = cos(Radian(tb_angle));
		vectorY = -sin(Radian(tb_angle));

		tb_startX = tb_centerX - 26;
		tb_startY = tb_centerY - 24;


	}
	
	if (tb_angle > 360 ) 
	{
		tb_angle = 30;
	}
	else if (tb_angle < 0) 
	{
		tb_angle = 330;
	}

	if (tb_angle == 90)
	{
		if (sprite_yStart != 60)
		{
			sprite_yStart = 60;
		}
		if (sprite_xStart != 45 && sprite_xStart != 119 && sprite_xStart != 193)
		{
			sprite_xStart = 45;
		}

		if (sprite_xStart > 193)
		{
			sprite_xStart = 45;
		}
	}
	else if (tb_angle == 120)
	{
		if (sprite_xStart != 267 && sprite_xStart != 341 && sprite_xStart != 415)
		{
			sprite_xStart = 341;
		}

		if (sprite_xStart > 420)
		{
			sprite_xStart = 267;
		}
	}
	else if (tb_angle == 150)
	{
		if (sprite_xStart != 489 && sprite_xStart != 563 && sprite_xStart != 637)
		{
			sprite_xStart = 489;
		}

		if (sprite_xStart > 637)
		{
			sprite_xStart = 489;
		}
	}
	else if (tb_angle == 180)
	{
		if (sprite_yStart != 60)
		{
			sprite_yStart = 60;
		}

		if (sprite_xStart != 711 && sprite_xStart != 785 && sprite_xStart != 859)
		{
			sprite_xStart = 711;
		}

		if (sprite_xStart > 864)
		{
			sprite_xStart = 711;
		}
	}

	//스프라이트 2번쨰 줄
	else if (tb_angle == 210)
	{
		if (sprite_yStart != 305)
		{
			sprite_yStart = 305;
		}


		if (sprite_xStart != 45 && sprite_xStart != 119 && sprite_xStart != 193)
		{
			sprite_xStart = 45;
		}

		if (sprite_xStart > 193)
		{
			sprite_xStart = 45;
		}


	}
	else if (tb_angle == 240)
	{
		if (sprite_xStart != 267 && sprite_xStart != 341 && sprite_xStart != 415)
		{
			sprite_xStart = 341;
		}

		if (sprite_xStart > 420)
		{
			sprite_xStart = 267;
		}
	}
	else if (tb_angle == 270)
	{
		if (sprite_xStart != 489 && sprite_xStart != 563 && sprite_xStart != 637)
		{
			sprite_xStart = 489;
		}

		if (sprite_xStart > 637)
		{
			sprite_xStart = 489;
		}
	}
	else if (tb_angle == 300)
	{
		if (sprite_yStart != 305)
		{
			sprite_yStart = 305;
		}

		if (sprite_xStart != 711 && sprite_xStart != 785 && sprite_xStart != 859)
		{
			sprite_xStart = 711;
		}

		if (sprite_xStart > 864)
		{
			sprite_xStart = 711;
		}
	}
	//스프라이트 3번째 줄
	else if (tb_angle == 330)
	{
		if (sprite_yStart != 550)
		{
			sprite_yStart = 550;
		}

		if (sprite_xStart != 45 && sprite_xStart != 119 && sprite_xStart != 193)
		{
			sprite_xStart = 45;
		}

		if (sprite_xStart > 193)
		{
			sprite_xStart = 45;
		}
	}
	else if (tb_angle == 360)
	{
		if (sprite_xStart != 267 && sprite_xStart != 341 && sprite_xStart != 415)
		{
			sprite_xStart = 341;
		}

		if (sprite_xStart > 420)
		{
			sprite_xStart = 267;
		}
	}
	else if (tb_angle == 0)
	{
		if (sprite_xStart != 267 && sprite_xStart != 341 && sprite_xStart != 415)
		{
			sprite_xStart = 341;
		}

		if (sprite_xStart > 420)
		{
			sprite_xStart = 267;
		}
	}
	else if (tb_angle == 30)
	{
		if (sprite_xStart != 489 && sprite_xStart != 563 && sprite_xStart != 637)
		{
			sprite_xStart = 489;
		}

		if (sprite_xStart > 637)
		{
			sprite_xStart = 489;
		}
	}
	else if (tb_angle == 60)
	{
		if (sprite_yStart != 550)
		{
			sprite_yStart = 550;
		}

		if (sprite_xStart != 711 && sprite_xStart != 785 && sprite_xStart != 859)
		{
			sprite_xStart = 711;
		}

		if (sprite_xStart > 864)
		{
			sprite_xStart = 711;
		}

	}
}

int cTankBody::CollisionCheck(HDC hdc, float bx, float by, int bR)
{
	//총알과 충돌 시 폭발
	//총알과 탱크 사이의 거리가 두 반지름의 합보다 작으면 충돌
	float between = 0;

	between = sqrt(pow(tb_centerY - by, 2) + pow(tb_centerX - bx, 2));

	if (between < 12 + bR) 
	{
		
		return 1;
	}

	return 0;
}

float cTankBody::GetCenterX()
{
	return tb_centerX;
}

float cTankBody::GetCenterY()
{
	return tb_centerY;
}

bool cTankBody::BlockTankCollisionCheck()
{
	/*
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			if (MapArray[i][j] != NULL)
			{
				float bx = MapArray[i][j]->GetCenterX();
				float by = MapArray[i][j]->GetCenterY();
				cout << "i: " << i << endl;
				cout << "j: " << j << endl;
				cout << "tb_centerX" << tb_centerX << endl;
				cout << "tb_centerY" << tb_centerY << endl;
				cout << "bx: " << bx << endl;
				cout << "by: " << by << endl;

				long between = long(sqrt(pow(tb_centerY - by, 2) + pow(tb_centerX - bx, 2)));
				cout << "between: " << between << endl;
				if (between <= block_R + 12)
				{
					return false;
				}

			}
		}
	}
	*/
	return true;
}

void cTankBody::DrawExplosion(HDC hdc, int xStart, int yStart)
{
	HDC hMemDC;
	HBITMAP hOldBitmap;
	int bx, by;

	int sprite_xStart = xStart;
	int sprite_yStart = yStart;
	int sprite_xEnd = 125;
	int sprite_yEnd = 125;


	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hExplosion);

		bx = bitExplosion.bmWidth / 10;
		by = bitExplosion.bmHeight / 10;

		TransparentBlt(hdc, tb_centerX - 60, tb_centerY - 55, bx, by, hMemDC, sprite_xStart, sprite_yStart, sprite_xEnd, sprite_yEnd, RGB(255, 0, 255));

		SelectObject(hMemDC, hOldBitmap);

	}
	DeleteDC(hMemDC);
}


cTankHead::cTankHead()
{

}

cTankHead::cTankHead(int i, int j)
{
	th_centerX = (i - 2) * (block_R * 2) + 170;
	th_centerY = (j - 2) * (block_R * 2) + 150;
	th_startX = th_centerX - 17;
	th_startY = th_centerY - 23;
	th_angle = 90;
	th_speed = 7;
	th_backSpeed = 5;

	sprite_xStart = 15;
	sprite_yStart = 795;
	sprite_xEnd = 40;
	sprite_yEnd = 50;


	th_bulletCount = 0;
	th_bulletLimit = 7;
}

cTankHead::~cTankHead()
{
}

void cTankHead::DrawTankHead(HDC hdc)
{
	
	HDC hMemDC;
	HBITMAP hOldBitmap;
	int bx, by;

	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hTankImage);
		bx = bitTank.bmWidth/27;
		by = bitTank.bmHeight/22;

		//탱크 포
		
		TransparentBlt(hdc, th_startX, th_startY, bx, by, hMemDC, sprite_xStart, sprite_yStart, sprite_xEnd, sprite_yEnd, RGB(255, 0, 255));


		SelectObject(hMemDC, hOldBitmap);
	}

	DeleteDC(hMemDC);
	
}

void cTankHead::MoveTankHead(string key)
{
	
	float radian = 0;
	float vectorX = 0;
	float vectorY = 0;

	if (key == "W")
	{

		vectorX = cos(Radian(th_angle));
		vectorY = -sin(Radian(th_angle));

		th_centerX -= vectorX * th_speed;
		th_centerY += vectorY * th_speed;

		th_startX = th_centerX - 17;
		th_startY = th_centerY - 23;
	}
	else if (key == "S")
	{
		vectorX = cos(Radian(th_angle));
		vectorY = -sin(Radian(th_angle));

		th_centerX += vectorX * th_backSpeed;
		th_centerY -= vectorY * th_backSpeed;

		th_startX = th_centerX - 17;
		th_startY = th_centerY - 23;
	}
	else if (key == "WA")
	{
		th_angle -= SPIN_ANGLE;
		vectorX = cos(Radian(th_angle));
		vectorY = -sin(Radian(th_angle));

		th_startX = th_centerX - 17;
		th_startY = th_centerY - 23;

	}
	else if (key == "WD")
	{
		th_angle += SPIN_ANGLE;
		vectorX = cos(Radian(th_angle));
		vectorY = -sin(Radian(th_angle));

		th_startX = th_centerX - 17;
		th_startY = th_centerY - 23;

	}
	else if (key == "SD")
	{

		th_angle -= SPIN_ANGLE;

		vectorX = cos(Radian(th_angle));
		vectorY = -sin(Radian(th_angle));

		th_startX = th_centerX - 17;
		th_startY = th_centerY - 23;
	}
	else if (key == "SA")
	{

		th_angle += SPIN_ANGLE;

		vectorX = cos(Radian(th_angle));
		vectorY = -sin(Radian(th_angle));

		th_startX = th_centerX - 17;
		th_startY = th_centerY - 23;
	}

	if (th_angle > 360)
	{
		th_angle = 30;
	}
	else if (th_angle < 0)
	{
		th_angle = 330;
	}

	if (th_angle == 90)
	{
		sprite_xStart = 15;
	}
	else if (th_angle == 120)
	{
		sprite_xStart = 65;
	}
	else if (th_angle == 150)
	{
		sprite_xStart = 115;
	}
	else if (th_angle == 180)
	{
		sprite_xStart = 165;
	}
	else if (th_angle == 210)
	{
		sprite_xStart = 215;
	}
	else if (th_angle == 240)
	{
		sprite_xStart = 265;
	}
	else if (th_angle == 270)
	{
		sprite_xStart = 315;
	}
	else if (th_angle == 300)
	{
		sprite_xStart = 365;
	}
	else if (th_angle == 330)
	{
		sprite_xStart = 415;
	}
	else if (th_angle == 360)
	{
		sprite_xStart = 465;
	}
	else if (th_angle == 0)
	{
		sprite_xStart = 465;
	}
	else if (th_angle == 30)
	{
		sprite_xStart = 515;
	}
	else if (th_angle == 60)
	{
		sprite_xStart = 565;
	}
}

float cTankHead::GetTankHeadCenterX()
{
	return th_centerX;
}

float cTankHead::GetTankHeadCenterY()
{
	return th_centerY;
}

int cTankHead::GetTankHeadAngle()
{
	return th_angle;
}

int cTankHead::GetBulletCount()
{
	return th_bulletCount;
}

void cTankHead::SetBulletCount()
{
	th_bulletCount++;
}

int cTankHead::GetBulletLimit()
{
	return th_bulletLimit;
}

void cTankHead::DecreaseBulletCount()
{
	th_bulletCount--;
}

void Move(int angle)
{
}

float Radian(float angle)
{

	return  angle * M_PI / 180;
}

cBullet::cBullet()
{
}

cBullet::cBullet(float x, float y, int angle)
{
	float vectorX = 0;
	float vectorY = 0;


	bullet_R = 5;

	//탱크 머리의 센터값

	bullet_centerX = x +2;
	bullet_centerY = y ;

	bullet_Angle = angle;	//탱크 머리의 앵글을 가져옴

	bullet_Speed = 20;
	bullet_Collision = 0;

	vectorX = cos(Radian(bullet_Angle));
	vectorY = -sin(Radian(bullet_Angle));

	bullet_centerX -= vectorX * bullet_Speed;
	bullet_centerY += vectorY * bullet_Speed;

	collision_BlockX = 0;
	collision_BlockY = 0;
	collision_xNum = 0;
	collision_yNum = 0;

}

cBullet::~cBullet()
{
}

void cBullet::DrawBullet(HDC hdc)
{
	HBRUSH Brush, oBrush;
	Brush = CreateSolidBrush(RGB(0, 0, 0));
	oBrush = (HBRUSH)SelectObject(hdc, Brush);
	Ellipse(hdc,
		bullet_centerX - bullet_R,
		bullet_centerY - bullet_R,
		bullet_centerX + bullet_R,
		bullet_centerY + bullet_R);

	SelectObject(hdc, oBrush);
	DeleteObject(Brush);

	
	Brush = CreateSolidBrush(RGB(0, 255, 255));
	oBrush = (HBRUSH)SelectObject(hdc, Brush);
	Ellipse(hdc,
		move_MaxX - bullet_R,
		move_MaxY - bullet_R,
		move_MaxX + bullet_R,
		move_MaxY + bullet_R);

	SelectObject(hdc, oBrush);
	DeleteObject(Brush);
	
	/*
	Brush = CreateSolidBrush(RGB(0, 255, 0));
	oBrush = (HBRUSH)SelectObject(hdc, Brush);
	Ellipse(hdc,
		collision_BlockX - bullet_R,
		collision_BlockY - bullet_R,
		collision_BlockX + bullet_R,
		collision_BlockY + bullet_R);

	SelectObject(hdc, oBrush);
	DeleteObject(Brush);
	*/

}

void cBullet::MoveBullet()
{

	float radian = 0;
	float vectorX = 0;
	float vectorY = 0;

	int i = 0;
	int j = 0;
	int k = 0;
	long between = 0;
	vectorX = cos(Radian(bullet_Angle));
	vectorY = -sin(Radian(bullet_Angle));


	
	Collision_Ray();

	bullet_centerX -= vectorX * bullet_Speed;
	bullet_centerY += vectorY * bullet_Speed;


}

void cBullet::Collision_Ray()
{
	int tempSpeed = 1;
	float tempX = 0;
	float tempY = 0;
	int flag = 0;
	float vectorX = 0;
	float vectorY = 0;

	tempX = bullet_centerX;
	tempY = bullet_centerY;

	vectorX = cos(Radian(bullet_Angle));
	vectorY = -sin(Radian(bullet_Angle));

	for (int k = 0; k < 1000; k++)
	{
		tempX -= vectorX * tempSpeed;
		tempY += vectorY * tempSpeed;

		for (int i = 0; i < MAPSIZE; i++)
		{
			for (int j = 0; j < MAPSIZE; j++)
			{
				if (MapArray[i][j] != NULL)
				{

					collision_BlockX = MapArray[i][j]->GetCenterX();
					collision_BlockY = MapArray[i][j]->GetCenterY();


					//벽과 충돌 시

					if (collision_BlockX - block_R <= tempX && tempX < collision_BlockX + block_R)
					{
						if (collision_BlockY - block_R <= tempY && tempY < collision_BlockY + block_R)
						{
							move_MaxX = tempX;
							move_MaxY = tempY;
							collision_BlockX = MapArray[i][j]->GetCenterX();
							collision_BlockY = MapArray[i][j]->GetCenterY();
							collision_xNum = i;
							collision_yNum = j;

							this->Collision();
							
							flag = 1;

						}
					}

				}

				if (flag > 0)
				{
					break;
				}

			}
			if (flag > 0)
			{
				break;
			}
		}
		if (flag > 0)
		{
			break;
		}

	}
}

void cBullet::ChagneAngle()
{

	float vectorX = 0;
	float vectorY = 0;

	vectorX = cos(Radian(bullet_Angle));
	vectorY = -sin(Radian(bullet_Angle));

	//이전 값으로
	bullet_centerX += vectorX * bullet_Speed;
	bullet_centerY -= vectorY * bullet_Speed;

	float temp_speed = sqrt(pow(collision_BlockY - bullet_centerY, 2) + pow(collision_BlockX - bullet_centerX, 2)) - (block_R + bullet_R + bullet_R);
	bullet_centerX -= vectorX * temp_speed;
	bullet_centerY += vectorY * temp_speed;

	if (collision_Direction == 1)
	{
		bullet_Angle = 180 - bullet_Angle;
		if (bullet_Angle < 0)
		{
			bullet_Angle = bullet_Angle + 360;
		}

		MapArray[collision_xNum][collision_yNum]->SetCollisionNum();
	}
	else if (collision_Direction == 2)
	{
		bullet_Angle = 360 - bullet_Angle;
		if (bullet_Angle < 0)
		{
			bullet_Angle = bullet_Angle + 360;
		}
		MapArray[collision_xNum][collision_yNum]->SetCollisionNum();
	}
	
}

void cBullet::Collision()
{
	POINT point[4];
	vector <float> tempPoint;
	float between = 0;
	int i = 0;


	point[0].x = collision_BlockX - block_R;
	point[0].y = collision_BlockY - block_R;

	point[1].x = collision_BlockX + block_R;
	point[1].y = collision_BlockY - block_R;

	point[2].x = collision_BlockX + block_R;
	point[2].y = collision_BlockY + block_R;

	point[3].x = collision_BlockX - block_R;
	point[3].y = collision_BlockY + block_R;


	for (i = 0 ; i < 4; i++) 
	{
		between = sqrt(pow(move_MaxY - point[i].y, 2) + pow(move_MaxX - point[i].x, 2));
		tempPoint.push_back(between);
	}

	//가장 짧은 거 두개
	float min = 9999;
	int firstMin = 0;
	int secondMin = 0;

	for (i = 0; i < 4; i++) 
	{
		if (tempPoint[i] < min) 
		{
			min = tempPoint[i];
			firstMin = i;
		}
	}

	tempPoint[firstMin] = 9999;
	min = 9999;

	for (i = 0; i < 4; i++) 
	{
		if (tempPoint[i] < min)
		{
			min = tempPoint[i];
			secondMin = i;
		}
	}

	
	//좌 우 판정
	if (firstMin == 0 && secondMin == 3 || firstMin == 3 && secondMin == 0)
	{
		collision_Direction = 1;
	}
	else if (firstMin == 1 && secondMin == 2 || firstMin == 2 && secondMin == 1)
	{
		collision_Direction = 1;
	}

	//상 하 판정
	else if (firstMin == 0 && secondMin == 1 || firstMin == 1 && secondMin == 0)
	{
		collision_Direction = 2;
	}
	else if (firstMin == 2 && secondMin == 3 || firstMin == 3 && secondMin == 2)
	{
		collision_Direction = 2;
	}

	else 
	{
		cout << "충돌 거리계산 예외 발생" <<endl;
	}
	

}

int cBullet::GetCollision()
{
	return bullet_Collision;
}

int cBullet::GetBulletAngle()
{
	return bullet_Angle;
}

float cBullet::GetBulletCenterX()
{
	return bullet_centerX;
}

float cBullet::GetBulletCenterY()
{
	return bullet_centerY;
}

float cBullet::GetBulletMoveMaxX()
{
	return move_MaxX;
}

float cBullet::GetBulletMoveMaxY()
{
	return move_MaxY;
}

int cBullet::GetBulletR()
{
	return bullet_R;
}

void cBullet::SetBulletCollision()
{
	bullet_Collision++;
}
