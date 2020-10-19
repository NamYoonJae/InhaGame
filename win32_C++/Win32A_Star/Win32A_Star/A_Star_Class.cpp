#include "stdafx.h"
#include "A_Star_Class.h"
#include <iostream>
#include <vector>

using namespace std;

extern vector <AStar> vAStarList;


AStar::AStar()
{
	as_centerX = as_centerY = as_r = as_g = as_h = as_f = as_state = 0;
}

AStar::AStar(int x, int y)
{
	as_centerX = x;
	as_centerY = y;
	as_r = 20;
	as_state = 0;
}

AStar::~AStar()
{

}

void AStar::DrawAMap(HDC hdc)
{
	POINT point[4];

	point[0].x = as_centerX - as_r;
	point[0].y = as_centerY - as_r;

	point[1].x = as_centerX + as_r;
	point[1].y = as_centerY - as_r;

	point[2].x = as_centerX + as_r;
	point[2].y = as_centerY + as_r;

	point[3].x = as_centerX - as_r;
	point[3].y = as_centerY + as_r;

	Polygon(hdc, point, 4);

}

void AStar::ChangeState()
{
	as_state = !as_state;
}

int AStar::GetState()
{
	return as_state;
}

int AStar::GetCenterX()
{
	return as_centerX;
}

int AStar::GetCenterY()
{
	return as_centerY;
}
